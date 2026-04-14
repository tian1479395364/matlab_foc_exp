#include "main.h"
#include "FOC_CURRENT.h"

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

#define READ_NFAULT				HAL_GPIO_ReadPin(nFAULT_GPIO_Port, \
									nFAULT_Pin)
#define READ_NOCTW				HAL_GPIO_ReadPin(nOCTW_GPIO_Port, \
									nOCTW_Pin)

typedef enum
{
	NONE_ERR,
	LV_ERR,
	OV_ERR,
	OC_ERR,
	DRV_ERR
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
	enMcCMD cmd;			// uint16.
	enMcState mc_state;
	enMcErr	mc_err;

	int32_t refIq;			// sfix16_en9.
	int32_t refRPM;			// sfix16_en2.

	int32_t isens_a;		// sfix16_en8.
	int32_t isens_b;		// sfix16_en8.
	int32_t isens_c;		// sfix16_en8.
	uint32_t vbus;			// ufix16_en9.
	uint16_t encoder_theta;	// ufix16_13.
	int16_t encoder_count;
	uint16_t encoder_dir;
	
	uint32_t run_realtime;
	uint8_t discharge_on;
	uint8_t err_code;
	uint8_t err_count;
	uint32_t err_state_vbus;
} stMcInfo;


extern stMcInfo mc_info;
extern int16_t comm[6];


extern void BspCordicInit(void);
extern void BspInit(void);
