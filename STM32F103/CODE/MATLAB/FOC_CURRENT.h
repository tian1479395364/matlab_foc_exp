#ifndef RTW_HEADER_FOC_CURRENT_h_
#define RTW_HEADER_FOC_CURRENT_h_
#include <stddef.h>
#include <string.h>
#ifndef FOC_CURRENT_COMMON_INCLUDES_
#define FOC_CURRENT_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "FOC_CURRENT_types.h"

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct {
    int16_T Integrator_DSTATE;
    int16_T Integrator_DSTATE_e;
} DW_FOC_CURRENT_T;

typedef struct {
    int16_T pooled3[257];
} ConstP_FOC_CURRENT_T;

typedef struct {
    int16_T ISensA;
    int16_T ISensB;
    int16_T ISensC;
    uint16_T theta;
    uint16_T Vbus;
    int16_T IRefD;
    int16_T IRefQ;
} ExtU_FOC_CURRENT_T;

typedef struct {
    uint16_T tAout;
    uint16_T tBout;
    uint16_T tCout;
} ExtY_FOC_CURRENT_T;

struct tag_RTM_FOC_CURRENT_T {
    const char_T * volatile errorStatus;
};

extern DW_FOC_CURRENT_T FOC_CURRENT_DW;
extern ExtU_FOC_CURRENT_T FOC_CURRENT_U;
extern ExtY_FOC_CURRENT_T FOC_CURRENT_Y;
extern const ConstP_FOC_CURRENT_T FOC_CURRENT_ConstP;
extern void FOC_CURRENT_initialize(void);
extern void FOC_CURRENT_step(void);
extern void FOC_CURRENT_terminate(void);
extern RT_MODEL_FOC_CURRENT_T *const FOC_CURRENT_M;

#endif

