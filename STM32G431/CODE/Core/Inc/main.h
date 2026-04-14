/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"
#include "stm32g4xx_ll_cordic.h"
#include "stm32g4xx_ll_bus.h"
#include "stm32g4xx_ll_cortex.h"
#include "stm32g4xx_ll_rcc.h"
#include "stm32g4xx_ll_system.h"
#include "stm32g4xx_ll_utils.h"
#include "stm32g4xx_ll_pwr.h"
#include "stm32g4xx_ll_gpio.h"
#include "stm32g4xx_ll_dma.h"

#include "stm32g4xx_ll_exti.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ISENS_C_Pin GPIO_PIN_1
#define ISENS_C_GPIO_Port GPIOC
#define ISENS_B_Pin GPIO_PIN_0
#define ISENS_B_GPIO_Port GPIOA
#define VBUS_Pin GPIO_PIN_1
#define VBUS_GPIO_Port GPIOA
#define EN_GATE_Pin GPIO_PIN_5
#define EN_GATE_GPIO_Port GPIOA
#define nCOTW_Pin GPIO_PIN_6
#define nCOTW_GPIO_Port GPIOA
#define PWM_AL_Pin GPIO_PIN_7
#define PWM_AL_GPIO_Port GPIOA
#define PWM_BL_Pin GPIO_PIN_0
#define PWM_BL_GPIO_Port GPIOB
#define PWM_CL_Pin GPIO_PIN_1
#define PWM_CL_GPIO_Port GPIOB
#define ENC_Z_Pin GPIO_PIN_10
#define ENC_Z_GPIO_Port GPIOB
#define ENC_Z_EXTI_IRQn EXTI15_10_IRQn
#define LED_DRV_Pin GPIO_PIN_9
#define LED_DRV_GPIO_Port GPIOC
#define PWM_AH_Pin GPIO_PIN_8
#define PWM_AH_GPIO_Port GPIOA
#define PWM_BH_Pin GPIO_PIN_9
#define PWM_BH_GPIO_Port GPIOA
#define PWM_CH_Pin GPIO_PIN_10
#define PWM_CH_GPIO_Port GPIOA
#define nFAULT_Pin GPIO_PIN_11
#define nFAULT_GPIO_Port GPIOA
#define ENC_A_Pin GPIO_PIN_15
#define ENC_A_GPIO_Port GPIOA
#define ENC_B_Pin GPIO_PIN_3
#define ENC_B_GPIO_Port GPIOB
#define DISCHARGE_MOS_Pin GPIO_PIN_7
#define DISCHARGE_MOS_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
