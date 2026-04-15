#ifndef FOC_CURRENT_h_
#define FOC_CURRENT_h_
#ifndef FOC_CURRENT_COMMON_INCLUDES_
#define FOC_CURRENT_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "jscl_transform.h"

#include "jscl_clarke.h"
#include "jscl_park.h"

typedef struct {
    VectorAB_T invpark;
    real_T SVPWM_CalcDutyCycle[3];
} DW;

typedef struct {
    real_T theta;
    real_T Vbus;
    real_T IRefD;
    real_T IRefQ;
    real_T s64_u;
    real_T s64_v;
    real_T s64_w;
} ExtU;

typedef struct {
    real_T tAout_out;
    real_T tBout_out;
    real_T tCout_out;
} ExtY;

extern DW rtDW;
extern ExtU rtU;
extern ExtY rtY;
extern void FOC_CURRENT_initialize(void);
extern void FOC_CURRENT_step(void);

#endif

