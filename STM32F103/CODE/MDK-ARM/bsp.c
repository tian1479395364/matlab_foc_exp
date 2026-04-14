#include "bsp.h"
#include "FOC_CURRENT.h"

static void StopPWM(void);		// stop mcu pwm output.
static void StartPWM(void);		// start mcu pwm output.
static void UploadData(void);	// upload paramters to simulink by uart2.
static void ParaInit(void);		// parameters initialization.


stMcInfo mc_info;
int16_t comm[6];
uint32_t adc1_in0, adc1_in1, ac2_in11;
// 10khz
void HAL_ADCEx_InjectedConvCpltCallback( ADC_HandleTypeDef *hadc)
{
	extern ADC_HandleTypeDef hadc1, hadc2;
	extern TIM_HandleTypeDef htim1, htim2, htim3;


	if( hadc->Instance == hadc1.Instance)
	{
		// start timer to calculate the execution time of the function.
		__HAL_TIM_SET_COUNTER( &htim3 , 0);

		/*********************  Processing ENCODER   *************************/
		int32_t count = (int32_t)__HAL_TIM_GET_COUNTER( &htim2) - 32768;
		__HAL_TIM_SET_COUNTER( &htim2, 32768);

		mc_info.encoder_count += count;
		if( mc_info.encoder_count < 0)
		{
			mc_info.encoder_count += 2000;
		}
		else if( mc_info.encoder_count > 2000)
		{
			mc_info.encoder_count -= 2000;
		}

		// ufix16_en13
		mc_info.encoder_theta = (uint16_t)((13177 *
								 mc_info.encoder_count) >> 9);
		/**********************     ENCODDER END   ***************************/

		/***********************   Processing ADC  ***************************/
		// 2.3us.
		// isens_b(sfix16_en8) = (2048 - i_ADC(uint32_t)) * 0.0161(sfix16_en8).
		adc1_in0 = HAL_ADCEx_InjectedGetValue( &hadc1, ADC_INJECTED_RANK_1);
		mc_info.isens_b = (int16_t)(((int16_t)((int16_t)(2048 - 
							adc1_in0) << 3) * 8441) >> 14);

		// vbus(ufix16_en9) = v_ADC(uint32_t) * 0.01047618(ufix16_9).
		adc1_in1 = HAL_ADCEx_InjectedGetValue( &hadc1, ADC_INJECTED_RANK_2);
		mc_info.vbus = (uint16_t)( (adc1_in1 * 10985U) >> 11 );

		//isens_c(sfix16_en8) = (2048 - i_ADC(uint32_t)) * 0.0161(sfix16_en8).
		ac2_in11  = HAL_ADCEx_InjectedGetValue( &hadc2, ADC_INJECTED_RANK_1);
		mc_info.isens_c = (int16_t)(((int16_t)((int16_t)(2048 -
							ac2_in11) << 3) * 8441) >> 14);

		// isens_a + isens_b + isens_c = 0;
		mc_info.isens_a = -( mc_info.isens_b + mc_info.isens_c);
		/**************************   ADC END   ******************************/


		/***********************   FOC Algorithm   ***************************/
		// MC_RUN -- 18us.
		switch( mc_info.mc_state)
		{
			case MC_RDY:
			case MC_STOP:
				if(mc_info.cmd == START_CMD)
				{
					// Add Simulink initialize function.
					FOC_CURRENT_initialize();

					ParaInit();
					LED_DRV_RESET;
					mc_info.mc_state = MC_START;
				}
				else
				{
					EN_GATE_RESET;
				}
				break;

			case MC_START:
				EN_GATE_SET;
				HAL_Delay(50);
				mc_info.mc_state = MC_RUN;
				StartPWM();
				break;

			case MC_RUN:
				// Add Simulink Step function.
				FOC_CURRENT_U.IRefD  = 0;
				FOC_CURRENT_U.IRefQ  = mc_info.refIq;
				FOC_CURRENT_U.ISensA = mc_info.isens_a;
				FOC_CURRENT_U.ISensB = mc_info.isens_b;
				FOC_CURRENT_U.ISensC = mc_info.isens_c;
				FOC_CURRENT_U.Vbus   = mc_info.vbus;
				FOC_CURRENT_U.theta  = mc_info.encoder_theta;
				FOC_CURRENT_step();
				TIM1->CCR1 = FOC_CURRENT_Y.tAout;
				TIM1->CCR2 = FOC_CURRENT_Y.tBout;
				TIM1->CCR3 = FOC_CURRENT_Y.tCout;

				if( mc_info.cmd == STOP_CMD)
				{
					mc_info.mc_state = MC_STOP;
					EN_GATE_RESET;
					StopPWM();
					HAL_Delay(50);
					LED_DRV_RESET;
				}
				if( mc_info.mc_err != NONE_ERR)
				{
					mc_info.mc_state = MC_ERR;
				}
				break;

			case MC_ERR:
				StopPWM();
				LED_DRV_SET;
				EN_GATE_RESET;
				break;

			default:
				break;
		}
		/*********************   FOC Algorithm END ***************************/
		mc_info.run_realtime = __HAL_TIM_GET_COUNTER( &htim3);

		// Upload debug parameters to simulink.
		UploadData();		// 7us.

	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if( GPIO_Pin == GPIO_PIN_10)
	{
		mc_info.encoder_count = 1500;
	}
	else if( GPIO_Pin == GPIO_PIN_11)
	{
	
	}
}

void StopPWM(void)
{
	extern TIM_HandleTypeDef htim1;
	HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Stop( &htim1, TIM_CHANNEL_3);
	HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Stop( &htim1, TIM_CHANNEL_3);
}

void StartPWM(void)
{
	extern TIM_HandleTypeDef htim1;
	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start( &htim1, TIM_CHANNEL_3);
	HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Start( &htim1, TIM_CHANNEL_3);
}

void ParaInit(void)
{
	mc_info.refIq = 0;
	mc_info	.refRPM = 0;
	mc_info.mc_state = MC_RDY;
	mc_info.mc_err = NONE_ERR;
}

void UploadData(void)
{
	extern UART_HandleTypeDef huart2;
	extern TIM_HandleTypeDef htim3;
	static int16_t temp[15];
	static uint16_t time_count;

	if( time_count == 0)
	{
		time_count++;
		temp[0] = *(int16_t*)"SS";
		temp[1] = mc_info.encoder_theta;
		temp[2] = mc_info.isens_a;
		temp[3] = mc_info.isens_b;
		__HAL_UNLOCK( huart2.hdmatx);
		huart2.gState = HAL_UART_STATE_READY;
		huart2.hdmatx->State = HAL_DMA_STATE_READY;
		HAL_UART_Transmit_DMA( &huart2, (uint8_t *)temp, 4*2);
	}
	else if( time_count == 999)
	{
		temp[0] = mc_info.encoder_theta;
		temp[1] = mc_info.isens_a;
		temp[2] = mc_info.isens_b;
		temp[3] = *(int16_t*)"EE";
		__HAL_UNLOCK( huart2.hdmatx);
		huart2.gState = HAL_UART_STATE_READY;
		huart2.hdmatx->State = HAL_DMA_STATE_READY;
		HAL_UART_Transmit_DMA( &huart2, (uint8_t *)temp, 4*2);
		time_count = 0;
	}
	else
	{
		time_count++;
		temp[0] = mc_info.encoder_theta;
		temp[1] = mc_info.isens_a;
		temp[2] = mc_info.isens_b;
		__HAL_UNLOCK( huart2.hdmatx);
		huart2.gState = HAL_UART_STATE_READY;
		huart2.hdmatx->State = HAL_DMA_STATE_READY;
		HAL_UART_Transmit_DMA( &huart2, (uint8_t *)temp, 3*2);
	}
}
