#ifndef FOC_CURRENTLOOP_DOUBLE_h_
#define FOC_CURRENTLOOP_DOUBLE_h_
#ifndef FOC_CURRENTLOOP_DOUBLE_COMMON_INCLUDES_
#define FOC_CURRENTLOOP_DOUBLE_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "jscl_transform.h"
#include <math.h>

typedef struct tag_RTM RT_MODEL;

#include "jscl_clarke.h"
#include "jscl_park.h"

typedef struct {
    VectorAB_T invpark;
    real_T PWM[3];
    real_T RateTransition_Buffer0[3];
    real_T Merge;
    real_T RateTransition7;
    real_T IRefQ;
    real_T DiscreteTimeIntegrator3_DSTATE;
    real_T UnitDelay_DSTATE;
    real_T DiscreteTimeIntegrator3_DSTAT_p;
    real_T DiscreteTimeIntegrator_DSTATE;
    struct {
        int_T PrevIndex;
    } fromWS_Signal1_IWORK;

    struct {
        void *TimePtr;
        void *DataPtr;
        void *RSimInfoPtr;
    } fromWS_Signal1_PWORK;

    uint8_T DiscreteTimeIntegrator3_IC_LOAD;
    uint8_T DiscreteTimeIntegrator3_IC_LO_l;
} DW;

struct tag_RTM {
    struct {
        uint32_T clockTick1;
        struct {
            uint8_T TID[2];
        } TaskCounters;
    } Timing;
};

extern DW rtDW;
extern VectorUVW_T measureCureent_s;
extern real_T s16_PwmOnTicks[3];
extern void FOC_CURRENTLOOP_DOUBLE_initialize(void);
extern void FOC_CURRENTLOOP_DOUBLE_step(void);
extern RT_MODEL *const rtM;

#endif

