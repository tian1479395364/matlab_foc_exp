/*
 * File: FOC_CURRENT.c
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

#include "FOC_CURRENT.h"
#include "jscl_transform.h"
#include "rtwtypes.h"
#include <math.h>

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;
static void SVPWM1(void);

/* Output and update for atomic system: '<S1>/SVPWM1' */
static void SVPWM1(void)
{
    VectorUVW_T rtb_spwm;
    real_T rtb_Sum2_idx_0;
    real_T rtb_Sum2_idx_1;
    real_T rtb_eit;

    /* CCaller: '<S2>/C Caller' */
    InverseClarkeTransform(&rtDW.CCaller3, &rtb_spwm);

    /* CCaller: '<S2>/C Caller1' */
    CalcZeroSequenceVoltage(&rtb_spwm, &rtb_eit);

    /* Sum: '<S2>/Sum2' */
    rtb_Sum2_idx_0 = rtb_eit + rtb_spwm.s64_u;
    rtb_Sum2_idx_1 = rtb_eit + rtb_spwm.s64_v;
    rtb_eit += rtb_spwm.s64_w;

    /* Gain: '<S2>/Gain3' incorporates:
     *  Constant: '<S2>/Constant2'
     *  Gain: '<S2>/Gain2'
     *  Inport: '<Root>/Vbus'
     *  Product: '<S2>/Divide1'
     *  Sum: '<S2>/Sum3'
     */
    rtDW.Gain3[0] = (-rtb_Sum2_idx_0 / rtU.Vbus + 0.5) * 4199.0;
    rtDW.Gain3[1] = (-rtb_Sum2_idx_1 / rtU.Vbus + 0.5) * 4199.0;
    rtDW.Gain3[2] = (-rtb_eit / rtU.Vbus + 0.5) * 4199.0;
}

/* Model step function */
void FOC_CURRENT_step(void)
{
    VectorAB_T rtb_ClarkeTransform;
    VectorDQ_T rtb_CCaller2;
    VectorDQ_T rtb_ParkTransform;
    VectorUVW_T rtb_BusConversion_InsertedFor_C;
    real_T rtb_TmpSignalConversionAtCCalle[2];

    /* Outputs for Atomic SubSystem: '<Root>/FOC_CURRENT' */
    /* SignalConversion generated from: '<S1>/C Caller3' incorporates:
     *  Inport: '<Root>/Theta'
     *  Trigonometry: '<S3>/SinCos'
     */
    rtb_TmpSignalConversionAtCCalle[0] = sin(rtU.theta);
    rtb_TmpSignalConversionAtCCalle[1] = cos(rtU.theta);

    /* BusCreator generated from: '<S1>/ClarkeTransform' incorporates:
     *  Inport: '<Root>/s64_u'
     *  Inport: '<Root>/s64_v'
     *  Inport: '<Root>/s64_w'
     */
    rtb_BusConversion_InsertedFor_C.s64_u = rtU.s64_u;
    rtb_BusConversion_InsertedFor_C.s64_v = rtU.s64_v;
    rtb_BusConversion_InsertedFor_C.s64_w = rtU.s64_w;

    /* CCaller: '<S1>/ClarkeTransform' */
    ClarkeTransform(&rtb_BusConversion_InsertedFor_C, &rtb_ClarkeTransform);

    /* CCaller: '<S1>/ParkTransform' */
    ParkTransform(&rtb_ClarkeTransform, &rtb_TmpSignalConversionAtCCalle[0],
                  &rtb_ParkTransform);

    /* CCaller: '<S1>/C Caller2' incorporates:
     *  Constant: '<S1>/d_ki'
     *  Constant: '<S1>/d_kp'
     *  Constant: '<S1>/q_ki'
     *  Constant: '<S1>/q_kp'
     *  Inport: '<Root>/IRefD'
     *  Inport: '<Root>/IRefQ'
     */
    CurrentLoopDQ(rtU.IRefD, rtb_ParkTransform.s64_d, rtU.Signal1,
                  rtb_ParkTransform.s64_q, 0.24527670483636954,
                  221.54511393115223, 0.24527670483636954, 221.54511393115223,
                  &rtb_CCaller2);

    /* CCaller: '<S1>/C Caller3' */
    InverseParkTransform(&rtb_CCaller2, &rtb_TmpSignalConversionAtCCalle[0],
                         &rtDW.CCaller3);

    /* Outputs for Atomic SubSystem: '<S1>/SVPWM1' */
    SVPWM1();

    /* End of Outputs for SubSystem: '<S1>/SVPWM1' */
    /* End of Outputs for SubSystem: '<Root>/FOC_CURRENT' */

    /* Outport: '<Root>/tAout' */
    rtY.tAout = rtDW.Gain3[0];

    /* Outport: '<Root>/tBout' */
    rtY.tBout = rtDW.Gain3[1];

    /* Outport: '<Root>/tCout' */
    rtY.tCout = rtDW.Gain3[2];
}

/* Model initialize function */
void FOC_CURRENT_initialize(void)
{
    /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
