#ifndef FOC_CURRENT_h_
#define FOC_CURRENT_h_
#ifndef FOC_CURRENT_COMMON_INCLUDES_
#define FOC_CURRENT_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "jscl_clarke.h"

#include "jscl_clarke.h"

typedef struct {
    real_T Gain1[3];
    real_T Saturation;
    real_T Sum1;
    real_T u_alpha;
    real_T Sum;
    real_T Gain;
    real_T Integrator_DSTATE;
    real_T Integrator_DSTATE_f;
} DW;

typedef struct {
    real_T theta;
    real_T Vbus;
    real_T IRefD;
    real_T Signal1;
    real_T signal1;
    real_T signal2;
    real_T signal3;
} ExtU;

typedef struct {
    real_T tAout;
    real_T tBout;
    real_T tCout;
} ExtY;

extern DW rtDW;
extern ExtU rtU;
extern ExtY rtY;
extern void FOC_CURRENT_initialize(void);
extern void FOC_CURRENT_step(void);

#endif

