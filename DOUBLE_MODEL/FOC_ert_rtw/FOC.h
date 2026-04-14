/*
 * File: FOC.h
 *
 * Code generated for Simulink model 'FOC'.
 *
 * Model version                  : 8.38
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Apr 10 13:39:16 2026
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

#ifndef DEFINED_TYPEDEF_FOR_ClarkeInput_
#define DEFINED_TYPEDEF_FOR_ClarkeInput_

typedef struct {
    real_T ia;
    real_T ib;
    real_T ic;
} ClarkeInput;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
    real_T Gain1[3];                   /* '<S6>/Gain1' */
    real_T Signal1;                    /* '<S4>/fromWS_Signal 1' */
    real_T Saturation;                 /* '<S55>/Saturation' */
    real_T Sum1;                       /* '<S118>/Sum1' */
    real_T u_alpha;                    /* '<S118>/u_alpha' */
    real_T Sum;                        /* '<S118>/Sum' */
    real_T Gain;                       /* '<S119>/Gain' */
    real_T Integrator_DSTATE;          /* '<S101>/Integrator' */
    real_T Integrator_DSTATE_f;        /* '<S48>/Integrator' */
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
    real_T ISensA;                     /* '<Root>/ISensA' */
    real_T ISensB;                     /* '<Root>/ISensB' */
    real_T ISensC;                     /* '<Root>/ISensC' */
    real_T Theta;                      /* '<Root>/Theta' */
    real_T Vbus;                       /* '<Root>/Vbus' */
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
 * Block '<S10>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition6' : Eliminated since input and output rates are identical
 * Block '<S10>/Rate Transition8' : Eliminated since input and output rates are identical
 * Block '<S11>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<S11>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<S11>/Rate Transition5' : Eliminated since input and output rates are identical
 * Block '<S11>/Rate Transition7' : Eliminated since input and output rates are identical
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
 * '<S5>'   : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop'
 * '<S6>'   : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/SVPWM2'
 * '<S7>'   : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/inv_park'
 * '<S8>'   : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/park'
 * '<S9>'   : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/sincos'
 * '<S10>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI'
 * '<S11>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI'
 * '<S12>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller'
 * '<S13>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Anti-windup'
 * '<S14>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/D Gain'
 * '<S15>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/External Derivative'
 * '<S16>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Filter'
 * '<S17>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Filter ICs'
 * '<S18>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/I Gain'
 * '<S19>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Ideal P Gain'
 * '<S20>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S21>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Integrator'
 * '<S22>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Integrator ICs'
 * '<S23>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/N Copy'
 * '<S24>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/N Gain'
 * '<S25>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/P Copy'
 * '<S26>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Parallel P Gain'
 * '<S27>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Reset Signal'
 * '<S28>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Saturation'
 * '<S29>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Saturation Fdbk'
 * '<S30>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Sum'
 * '<S31>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Sum Fdbk'
 * '<S32>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Tracking Mode'
 * '<S33>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Tracking Mode Sum'
 * '<S34>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Tsamp - Integral'
 * '<S35>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Tsamp - Ngain'
 * '<S36>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/postSat Signal'
 * '<S37>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/preSat Signal'
 * '<S38>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S39>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S40>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S41>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/D Gain/Disabled'
 * '<S42>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/External Derivative/Disabled'
 * '<S43>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Filter/Disabled'
 * '<S44>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Filter ICs/Disabled'
 * '<S45>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/I Gain/External Parameters'
 * '<S46>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S47>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S48>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Integrator/Discrete'
 * '<S49>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S50>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/N Copy/Disabled wSignal Specification'
 * '<S51>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/N Gain/Disabled'
 * '<S52>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/P Copy/Disabled'
 * '<S53>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S54>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Reset Signal/Disabled'
 * '<S55>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Saturation/Enabled'
 * '<S56>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S57>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Sum/Sum_PI'
 * '<S58>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S59>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S60>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S61>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S62>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S63>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S64>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/DCurrentPI/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S65>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1'
 * '<S66>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Anti-windup'
 * '<S67>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/D Gain'
 * '<S68>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/External Derivative'
 * '<S69>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Filter'
 * '<S70>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Filter ICs'
 * '<S71>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/I Gain'
 * '<S72>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Ideal P Gain'
 * '<S73>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S74>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Integrator'
 * '<S75>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Integrator ICs'
 * '<S76>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/N Copy'
 * '<S77>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/N Gain'
 * '<S78>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/P Copy'
 * '<S79>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Parallel P Gain'
 * '<S80>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Reset Signal'
 * '<S81>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Saturation'
 * '<S82>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Saturation Fdbk'
 * '<S83>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Sum'
 * '<S84>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Sum Fdbk'
 * '<S85>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Tracking Mode'
 * '<S86>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Tracking Mode Sum'
 * '<S87>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Tsamp - Integral'
 * '<S88>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Tsamp - Ngain'
 * '<S89>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/postSat Signal'
 * '<S90>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/preSat Signal'
 * '<S91>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S92>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S93>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S94>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/D Gain/Disabled'
 * '<S95>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/External Derivative/Disabled'
 * '<S96>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Filter/Disabled'
 * '<S97>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Filter ICs/Disabled'
 * '<S98>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/I Gain/External Parameters'
 * '<S99>'  : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S100>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S101>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Integrator/Discrete'
 * '<S102>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S103>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S104>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/N Gain/Disabled'
 * '<S105>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/P Copy/Disabled'
 * '<S106>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Parallel P Gain/External Parameters'
 * '<S107>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S108>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Saturation/Enabled'
 * '<S109>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S110>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Sum/Sum_PI'
 * '<S111>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S112>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S113>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S114>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S115>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S116>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S117>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/CurrentLoop/QCurrentPI/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S118>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/SVPWM2/InvClark'
 * '<S119>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/FOC_CURRENT/SVPWM2/ei_t'
 * '<S120>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/RangeLimit/If Action Subsystem'
 * '<S121>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/RangeLimit/If Action Subsystem1'
 * '<S122>' : 'FOC_CURRENTLOOP_DOUBLE/FOC/RangeLimit/If Action Subsystem2'
 */
#endif                                 /* FOC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
