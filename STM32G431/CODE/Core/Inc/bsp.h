#include "stm32g4xx_hal.h"
#include "main.h"

#define PI_2		6.2832f

#define EN_GATE_SET				HAL_GPIO_WritePin(EN_GATE_GPIO_Port, \
									EN_GATE_Pin, GPIO_PIN_SET)
#define EN_GATE_RESET			HAL_GPIO_WritePin(EN_GATE_GPIO_Port, \
									EN_GATE_Pin, GPIO_PIN_RESET)

#define LED_DRV_SET				HAL_GPIO_WritePin(LED_DRV_GPIO_Port, \
									LED_DRV_Pin, GPIO_PIN_SET)
#define LED_DRV_RESET			HAL_GPIO_WritePin(LED_DRV_GPIO_Port, \
									LED_DRV_Pin, GPIO_PIN_RESET)

#define DISCHARGE_MOS_SET		HAL_GPIO_WritePin(DISCHARGE_MOS_GPIO_Port, \
									DISCHARGE_MOS_Pin, GPIO_PIN_SET)
#define DISCHARGE_MOS_RESET		HAL_GPIO_WritePin(DISCHARGE_MOS_GPIO_Port, \
									DISCHARGE_MOS_Pin, GPIO_PIN_RESET)

typedef enum
{
	NONE_ERR,
	LV_ERR,
	OV_ERR,
	OC_ERR
} enMcErr;

typedef enum
{
	MC_RDY,
	MC_START,
	MC_RUN,
	MC_STOP,
	MC_ERR
} enMcState;

typedef enum
{
	START_CMD = 1,
	STOP_CMD = 0
} enMcCMD;

typedef struct
{
	enMcCMD cmd;
	enMcState mc_state;
	enMcErr	mc_err;
	float refIq;
	float refRPM;

	float isens_a;
	float isens_b;
	float isens_c;
	float vbus;
	float encoder_theta;
	uint16_t encoder_dir;
	int16_t encoder_count;
	
	float run_realtime;
	uint8_t discharge_on;
	uint8_t err_code;
	uint8_t over_vol_count;

	float err_state_vbus;
} stMcInfo;

extern void BspCordicInit(void);
extern void BspInit(void);
