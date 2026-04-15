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
    real_T Gain3[3];
    real_T RateTransition;
    real_T RateTransition1;
    real_T RateTransition2;
    real_T RateTransition7;
    real_T DiscreteTimeIntegrator3_DSTATE;
    real_T UnitDelay_DSTATE;
    real_T DiscreteTimeIntegrator3_DSTAT_l;
    real_T DiscreteTimeIntegrator_DSTATE;
    real_T RateTransition_Buffer0;
    real_T RateTransition1_Buffer0;
    real_T RateTransition2_Buffer0;
    struct {
        int_T PrevIndex;
    } fromWS_Signal1_IWORK;

    struct {
        void *TimePtr;
        void *DataPtr;
        void *RSimInfoPtr;
    } fromWS_Signal1_PWORK;

    uint8_T DiscreteTimeIntegrator3_IC_LOAD;
    uint8_T DiscreteTimeIntegrator3_IC_LO_o;
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
extern void FOC_CURRENTLOOP_DOUBLE_initialize(void);
extern void FOC_CURRENTLOOP_DOUBLE_step(void);
extern RT_MODEL *const rtM;

#endif

