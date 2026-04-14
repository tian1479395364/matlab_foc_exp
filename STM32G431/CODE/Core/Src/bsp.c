#include "bsp.h"
#include "arm_math.h"
#include "FOC_CURRENT.h"

static void StopPWM(void);		// stop mcu pwm output.
static void StartPWM(void);		// start mcu pwm output.
static void UploadData(void);	// upload paramters to simulink by uart2.
static void ParaInit(void);		// parameters initialization.


float comm[6];					// communicate download parameters.
float encoder_angle;			// ABZ angle.
stMcInfo mc_info;				// about motor parameters.

/*
 *  Function Describe : Deal with FOC algorithm.
 *  exec period : 10kHz
 */
void HAL_ADCEx_InjectedConvCpltCallback( ADC_HandleTypeDef *hadc)
{
	extern ADC_HandleTypeDef hadc1, hadc2;
	extern TIM_HandleTypeDef htim1;
	extern TIM_HandleTypeDef htim2;
	extern TIM_HandleTypeDef htim4;
	
	uint16_t adc1_in1, adc1_in2, adc2_in7;

	if( hadc->Instance == hadc1.Instance)
	{
		// start timer to calculate the execution time of the function.
		__HAL_TIM_SET_COUNTER( &htim4, 0);

		/*********************  Processing ENCODER   *************************/
		float count = (float)((int32_t)__HAL_TIM_GET_COUNTER( &htim2) - 65536);
		mc_info.encoder_count += count;
		__HAL_TIM_SET_COUNTER( &htim2, 65536);

		if( mc_info.encoder_count > 2000)
		{
			mc_info.encoder_count -= 2000;
		}
		else if( mc_info.encoder_count < 0)
		{
			mc_info.encoder_count += 2000;
		}

		mc_info.encoder_theta =  0.003141592653590f * mc_info.encoder_count;
		/**********************     ENCODDER END   ***************************/

		/***********************   Processing ADC  ***************************/
		adc1_in1 = HAL_ADCEx_InjectedGetValue( &hadc1, ADC_INJECTED_RANK_1);
		adc1_in2 = HAL_ADCEx_InjectedGetValue( &hadc1, ADC_INJECTED_RANK_2);
		adc2_in7 = HAL_ADCEx_InjectedGetValue( &hadc2, ADC_INJECTED_RANK_1);
		mc_info.isens_b = (2048 - adc1_in1) * 0.0161F;
		mc_info.isens_c = (2048 - adc2_in7) * 0.0161F;
		mc_info.isens_a = -( mc_info.isens_b + mc_info.isens_c);
		mc_info.vbus   = adc1_in2 * 0.01047618F;
		/**************************   ADC END   ******************************/

		/********************    Get CMD from Simulink    ********************/
		if( comm[2] )
		{
			mc_info.cmd = START_CMD;
		}
		else
		{
			mc_info.cmd = STOP_CMD;
		}

		mc_info.refIq = comm[0];
		if( mc_info.refIq > 10)
			mc_info.refIq = 10;
		else if( mc_info.refIq < -10)
			mc_info.refIq = -10;

		mc_info.refRPM = comm[1];
		/*************************  Get CMD END   ****************************/

		switch( mc_info.mc_state)
		{
			case MC_RDY:
			case MC_STOP:
				if(mc_info.cmd == START_CMD)
				{
					// Add Simulink Algorithm initialize function.
					FOC_CURRENT_initialize();
					
					ParaInit();
					mc_info.mc_state = MC_START;
					LED_DRV_RESET;
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
				// Add Simulink Algorithm step function.
				FOC_CURRENT_U.IRefQ  = mc_info.refIq;
				FOC_CURRENT_U.ISensA = mc_info.isens_a;
				FOC_CURRENT_U.ISensB = mc_info.isens_b;
				FOC_CURRENT_U.ISensC = mc_info.isens_c;
				FOC_CURRENT_U.theta  = mc_info.encoder_theta;
				FOC_CURRENT_U.Vbus   = mc_info.vbus;
				FOC_CURRENT_step();
				TIM1->CCR1 = FOC_CURRENT_Y.tAout;
				TIM1->CCR2 = FOC_CURRENT_Y.tBout;
				TIM1->CCR3 = FOC_CURRENT_Y.tCout;

				if( mc_info.cmd == STOP_CMD)
				{
					mc_info.mc_state = MC_STOP;
					StopPWM();
					EN_GATE_RESET;
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

		/*************    Under AND Over Voltage protection    ***************/
		if( mc_info.vbus < 10.0f)
		{
			mc_info.mc_err = LV_ERR;
		}
		else if( mc_info.vbus > 36.0f)
		{
			if( mc_info.over_vol_count++ > 5)
			{
				mc_info.mc_err = OV_ERR;
				DISCHARGE_MOS_RESET;
				mc_info.err_state_vbus = mc_info.vbus;
			}
		}
		else if(mc_info.vbus >30.0f)
		{
			DISCHARGE_MOS_SET;
		}
		else
		{
			DISCHARGE_MOS_RESET;
			mc_info.over_vol_count = 0;
		}
		/************************      protection END     ********************/

		UploadData();

		mc_info.run_realtime = __HAL_TIM_GET_COUNTER( &htim4);
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	extern TIM_HandleTypeDef htim2;
	if( GPIO_Pin == GPIO_PIN_10)
	{
		mc_info.encoder_dir = __HAL_TIM_IS_TIM_COUNTING_DOWN( &htim2);
		mc_info.encoder_count = 1500;
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
	mc_info.refIq = 0.0f;
	mc_info	.refRPM = 0.0f;
	mc_info.mc_state = MC_RDY;
	mc_info.mc_err = NONE_ERR;
}

void UploadData(void)
{
	extern UART_HandleTypeDef huart2;
	static float temp[15];
	static uint16_t time_count;

	if( time_count == 0)
	{
		time_count++;
		temp[0] = *(float*)"SSSS";
		temp[1] = mc_info.vbus;
		temp[2] = mc_info.isens_a;
		temp[3] = mc_info.isens_b;
		temp[4] = mc_info.encoder_theta;
		__HAL_UNLOCK( huart2.hdmatx);
		huart2.gState = HAL_UART_STATE_READY;
		huart2.hdmatx->State = HAL_DMA_STATE_READY;
		HAL_UART_Transmit_DMA( &huart2, (uint8_t *)temp, 5*4);
	}
	else if( time_count == 999)
	{
		temp[0] = mc_info.vbus;
		temp[1] = mc_info.isens_a;
		temp[2] = mc_info.isens_b;
		temp[3] = mc_info.encoder_theta;
		temp[4] = *(float*)"EEEE";
		__HAL_UNLOCK( huart2.hdmatx);
		huart2.gState = HAL_UART_STATE_READY;
		huart2.hdmatx->State = HAL_DMA_STATE_READY;
		HAL_UART_Transmit_DMA( &huart2, (uint8_t *)temp, 5*4);
		time_count = 0;
	}
	else
	{
		time_count++;
		temp[0] = mc_info.vbus;
		temp[1] = mc_info.isens_a;
		temp[2] = mc_info.isens_b;
		temp[3] = mc_info.encoder_theta;
		__HAL_UNLOCK( huart2.hdmatx);
		huart2.gState = HAL_UART_STATE_READY;
		huart2.hdmatx->State = HAL_DMA_STATE_READY;
		HAL_UART_Transmit_DMA( &huart2, (uint8_t *)temp, 4*4);
	}
}

