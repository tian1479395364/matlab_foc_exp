/*
 * File: FOC.h
 *
 * Code generated for Simulink model 'FOC'.
 *
 * Model version                  : 8.130
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Apr 13 17:38:34 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef FOC_h_
#define FOC_h_
#ifndef FOC_COMMON_INCLUDES_
#define FOC_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FOC_COMMON_INCLUDES_ */

#include <math.h>

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* user code (top of header file) */
#include "jscl_clarke.h"
#include "jscl_park.h"
#ifndef DEFINED_TYPEDEF_FOR_VectorUVW_T_
#define DEFINED_TYPEDEF_FOR_VectorUVW_T_

typedef struct {
    real_T s64_u;
    real_T s64_v;
    real_T s64_w;
} VectorUVW_T;

#endif

#ifndef DEFINED_TYPEDEF_FOR_VectorDQ_T_
#define DEFINED_TYPEDEF_FOR_VectorDQ_T_

typedef struct {
    real_T s64_d;
    real_T s64_q;
} VectorDQ_T;

#endif

#ifndef DEFINED_TYPEDEF_FOR_VectorAB_T_
#define DEFINED_TYPEDEF_FOR_VectorAB_T_

typedef struct {
    real_T s64_alpha;
    real_T s64_beta;
} VectorAB_T;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
    VectorAB_T CCaller3;               /* '<S2>/C Caller3' */
    real_T Gain3[3];                   /* '<S5>/Gain3' */
    struct {
        int_T PrevIndex;
    } fromWS_Signal1_IWORK;            /* '<S4>/fromWS_Signal 1' */

    struct {
        void *TimePtr;
        void *DataPtr;
        void *RSimInfoPtr;
    } fromWS_Signal1_PWORK;            /* '<S4>/fromWS_Signal 1' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
    real_T Theta;                      /* '<Root>/Theta' */
    real_T Vbus;                       /* '<Root>/Vbus' */
    real_T s64_u;                      /* '<Root>/s64_u' */
    real_T s64_v;                      /* '<Root>/s64_v' */
    real_T s64_w;                      /* '<Root>/s64_w' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
    real_T tAout;                      /* '<Root>/tAout' */
    real_T tBout;                      /* '<Root>/tBout' */
    real_T tCout;                      /* '<Root>/tCout' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
    /*
     * Timing:
     * The following substructure contains information regarding
     * the timing information for the model.
     */
    struct {
        uint32_T clockTick0;
    } Timing;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void FOC_initialize(void);
extern void FOC_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S2>/Rate Transition8' : Eliminated since input and output rates are identical
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('FOC_CURRENTLOOP_DOUBLE/FOC')    - opens subsystem FOC_CURRENTLOOP_DOUBLE/FOC
 * hilite_system('FOC_CURRENTLOOP_DOUBLE/FOC/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FOC_CURRENTLOOP_DOUBLE'
 * '<S1>'   : 'FOC_CURRENTLOOP_DOUBLE/FOC'
 * '<S2>'   : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT'
 * '<S3>'   : 'FOC_CURRENTLOOP_DOUBLE/FOC/RangeLimit'
 * '<S4>'   : 'FOC_CURRENTLOOP_DOUBLE/FOC/Signal Editor'
 * '<S5>'   : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/SVPWM1'
 * '<S6>'   : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/sincos'
 * '<S7>'   : 'FOC_CURRENTLOOP_DOUBLE/FOC/RangeLimit/If Action Subsystem'
 * '<S8>'   : 'FOC_CURRENTLOOP_DOUBLE/FOC/RangeLimit/If Action Subsystem1'
 * '<S9>'   : 'FOC_CURRENTLOOP_DOUBLE/FOC/RangeLimit/If Action Subsystem2'
 */
#endif                                 /* FOC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
