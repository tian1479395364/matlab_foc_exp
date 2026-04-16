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
} DW;

typedef struct {
    real_T theta;
    real_T Vbus;
    real_T IRefD;
    real_T IRefQ;
} ExtU;

extern DW rtDW;
extern ExtU rtU;
extern VectorUVW_T measureCureent_s;
extern real_T s16_PwmOnTicks[3];
extern void FOC_CURRENT_initialize(void);
extern void FOC_CURRENT_step(void);

#endif

