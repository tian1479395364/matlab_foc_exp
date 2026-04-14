#ifndef RTW_HEADER_FOC_CURRENT_h_
#define RTW_HEADER_FOC_CURRENT_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef FOC_CURRENT_COMMON_INCLUDES_
#define FOC_CURRENT_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "FOC_CURRENT_types.h"
#include "mw_cmsis.h"

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct {
    real32_T Integrator_DSTATE;
    real32_T Integrator_DSTATE_e;
} DW_FOC_CURRENT_T;

typedef struct {
    real32_T ISensA;
    real32_T ISensB;
    real32_T ISensC;
    real32_T theta;
    real32_T Vbus;
    real32_T IRefQ;
} ExtU_FOC_CURRENT_T;

typedef struct {
    real32_T tAout;
    real32_T tBout;
    real32_T tCout;
} ExtY_FOC_CURRENT_T;

struct tag_RTM_FOC_CURRENT_T {
    const char_T * volatile errorStatus;
};

extern DW_FOC_CURRENT_T FOC_CURRENT_DW;
extern ExtU_FOC_CURRENT_T FOC_CURRENT_U;
extern ExtY_FOC_CURRENT_T FOC_CURRENT_Y;
extern void FOC_CURRENT_initialize(void);
extern void FOC_CURRENT_step(void);
extern void FOC_CURRENT_terminate(void);
extern RT_MODEL_FOC_CURRENT_T *const FOC_CURRENT_M;

#endif

