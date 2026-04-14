/*
 * File: FOC_CURRENT.h
 *
 * Code generated for Simulink model 'FOC_CURRENT'.
 *
 * Model version                  : 8.146
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Apr 14 17:56:48 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef FOC_CURRENT_h_
#define FOC_CURRENT_h_
#ifndef FOC_CURRENT_COMMON_INCLUDES_
#define FOC_CURRENT_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FOC_CURRENT_COMMON_INCLUDES_ */

#include "jscl_transform.h"

/* user code (top of header file) */
#include "jscl_clarke.h"
#include "jscl_park.h"

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
    VectorAB_T CCaller3;               /* '<S1>/C Caller3' */
    real_T Gain3[3];                   /* '<S2>/Gain3' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
    real_T theta;                      /* '<Root>/Theta' */
    real_T Vbus;                       /* '<Root>/Vbus' */
    real_T IRefD;                      /* '<Root>/IRefD' */
    real_T Signal1;                    /* '<Root>/IRefQ' */
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

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void FOC_CURRENT_initialize(void);
extern void FOC_CURRENT_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S1>/Rate Transition8' : Eliminated since input and output rates are identical
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
 * hilite_system('FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT')    - opens subsystem FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT
 * hilite_system('FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FOC_CURRENTLOOP_DOUBLE/FOC'
 * '<S1>'   : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT'
 * '<S2>'   : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/SVPWM1'
 * '<S3>'   : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/sincos'
 */
#endif                                 /* FOC_CURRENT_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
