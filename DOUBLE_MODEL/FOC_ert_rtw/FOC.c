/*
 * File: FOC.c
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

#include "FOC.h"
#include "rtwtypes.h"
#include <math.h>

/* Used by FromWorkspace Block: '<S4>/fromWS_Signal 1' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static void park(real_T param_u_i_alpha, real_T param_u_i_beta, const real_T
                 param_u_sin_cos[2], real_T *param_y_i_d, real_T *param_y_i_q);
static void DCurrentPI(void);
static void QCurrentPI(void);
static void CurrentLoop(void);
static void InvClark(void);
static void ei_t(void);
static void SVPWM2(void);
static void inv_park(void);

/* Output and update for atomic system: '<S5>/DCurrentPI' */
static void DCurrentPI(void)
{
    real_T rtb_DeadZone;
    real_T rtb_Sum;
    int8_T tmp;
    int8_T tmp_0;

    /* Sum: '<S57>/Sum' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S1>/Constant'
     *  DiscreteIntegrator: '<S48>/Integrator'
     *  Product: '<S53>/PProd Out'
     *  Sum: '<S10>/Sum'
     */
    rtb_Sum = (0.0 - rtDW.Sum) * 0.24527670483636954 + rtDW.Integrator_DSTATE_f;

    /* DeadZone: '<S40>/DeadZone' incorporates:
     *  Saturate: '<S55>/Saturation'
     */
    if (rtb_Sum > 10.0) {
        rtb_DeadZone = rtb_Sum - 10.0;

        /* Saturate: '<S55>/Saturation' */
        rtDW.Saturation = 10.0;
    } else {
        if (rtb_Sum >= -10.0) {
            rtb_DeadZone = 0.0;
        } else {
            rtb_DeadZone = rtb_Sum - -10.0;
        }

        if (rtb_Sum < -10.0) {
            /* Saturate: '<S55>/Saturation' */
            rtDW.Saturation = -10.0;
        } else {
            /* Saturate: '<S55>/Saturation' */
            rtDW.Saturation = rtb_Sum;
        }
    }

    /* End of DeadZone: '<S40>/DeadZone' */

    /* Product: '<S45>/IProd Out' incorporates:
     *  Constant: '<S10>/Constant1'
     *  Constant: '<S1>/Constant'
     *  Sum: '<S10>/Sum'
     */
    rtb_Sum = (0.0 - rtDW.Sum) * 221.54511393115223;

    /* Switch: '<S38>/Switch1' incorporates:
     *  Constant: '<S38>/Clamping_zero'
     *  Constant: '<S38>/Constant'
     *  Constant: '<S38>/Constant2'
     *  RelationalOperator: '<S38>/fix for DT propagation issue'
     */
    if (rtb_DeadZone > 0.0) {
        tmp = 1;
    } else {
        tmp = -1;
    }

    /* Switch: '<S38>/Switch2' incorporates:
     *  Constant: '<S38>/Clamping_zero'
     *  Constant: '<S38>/Constant3'
     *  Constant: '<S38>/Constant4'
     *  RelationalOperator: '<S38>/fix for DT propagation issue1'
     */
    if (rtb_Sum > 0.0) {
        tmp_0 = 1;
    } else {
        tmp_0 = -1;
    }

    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S38>/Clamping_zero'
     *  Constant: '<S38>/Constant1'
     *  Logic: '<S38>/AND3'
     *  RelationalOperator: '<S38>/Equal1'
     *  RelationalOperator: '<S38>/Relational Operator'
     *  Switch: '<S38>/Switch1'
     *  Switch: '<S38>/Switch2'
     */
    if ((rtb_DeadZone != 0.0) && (tmp == tmp_0)) {
        rtb_Sum = 0.0;
    }

    /* Update for DiscreteIntegrator: '<S48>/Integrator' incorporates:
     *  Switch: '<S38>/Switch'
     */
    rtDW.Integrator_DSTATE_f += 0.0001 * rtb_Sum;
}

/* Output and update for atomic system: '<S5>/QCurrentPI' */
static void QCurrentPI(void)
{
    real_T rtb_DeadZone;
    real_T rtb_IProdOut_j;
    real_T rtb_Sum;
    int8_T tmp;
    int8_T tmp_0;

    /* Sum: '<S11>/Sum1' */
    rtb_IProdOut_j = rtDW.Signal1 - rtDW.Gain;

    /* Sum: '<S110>/Sum' incorporates:
     *  Constant: '<S11>/Constant2'
     *  DiscreteIntegrator: '<S101>/Integrator'
     *  Product: '<S106>/PProd Out'
     */
    rtb_Sum = rtb_IProdOut_j * 0.24527670483636954 + rtDW.Integrator_DSTATE;

    /* DeadZone: '<S93>/DeadZone' incorporates:
     *  Saturate: '<S108>/Saturation'
     */
    if (rtb_Sum > 10.0) {
        rtb_DeadZone = rtb_Sum - 10.0;
        rtDW.Sum = 10.0;
    } else {
        if (rtb_Sum >= -10.0) {
            rtb_DeadZone = 0.0;
        } else {
            rtb_DeadZone = rtb_Sum - -10.0;
        }

        if (rtb_Sum < -10.0) {
            rtDW.Sum = -10.0;
        } else {
            rtDW.Sum = rtb_Sum;
        }
    }

    /* End of DeadZone: '<S93>/DeadZone' */

    /* Product: '<S98>/IProd Out' incorporates:
     *  Constant: '<S11>/Constant3'
     */
    rtb_IProdOut_j *= 221.54511393115223;

    /* Switch: '<S91>/Switch1' incorporates:
     *  Constant: '<S91>/Clamping_zero'
     *  Constant: '<S91>/Constant'
     *  Constant: '<S91>/Constant2'
     *  RelationalOperator: '<S91>/fix for DT propagation issue'
     */
    if (rtb_DeadZone > 0.0) {
        tmp = 1;
    } else {
        tmp = -1;
    }

    /* Switch: '<S91>/Switch2' incorporates:
     *  Constant: '<S91>/Clamping_zero'
     *  Constant: '<S91>/Constant3'
     *  Constant: '<S91>/Constant4'
     *  RelationalOperator: '<S91>/fix for DT propagation issue1'
     */
    if (rtb_IProdOut_j > 0.0) {
        tmp_0 = 1;
    } else {
        tmp_0 = -1;
    }

    /* Switch: '<S91>/Switch' incorporates:
     *  Constant: '<S91>/Clamping_zero'
     *  Constant: '<S91>/Constant1'
     *  Logic: '<S91>/AND3'
     *  RelationalOperator: '<S91>/Equal1'
     *  RelationalOperator: '<S91>/Relational Operator'
     *  Switch: '<S91>/Switch1'
     *  Switch: '<S91>/Switch2'
     */
    if ((rtb_DeadZone != 0.0) && (tmp == tmp_0)) {
        rtb_IProdOut_j = 0.0;
    }

    /* Update for DiscreteIntegrator: '<S101>/Integrator' incorporates:
     *  Switch: '<S91>/Switch'
     */
    rtDW.Integrator_DSTATE += 0.0001 * rtb_IProdOut_j;
}

/* Output and update for atomic system: '<S2>/CurrentLoop' */
static void CurrentLoop(void)
{
    /* Outputs for Atomic SubSystem: '<S5>/DCurrentPI' */
    DCurrentPI();

    /* End of Outputs for SubSystem: '<S5>/DCurrentPI' */

    /* Outputs for Atomic SubSystem: '<S5>/QCurrentPI' */
    QCurrentPI();

    /* End of Outputs for SubSystem: '<S5>/QCurrentPI' */
}

/* Output and update for atomic system: '<S6>/InvClark' */
static void InvClark(void)
{
    real_T rtb_Gain;
    real_T rtb_Gain1;

    /* SignalConversion generated from: '<S118>/u_alpha' */
    rtDW.u_alpha = rtDW.Gain;

    /* Gain: '<S118>/Gain' */
    rtb_Gain = -0.5 * rtDW.u_alpha;

    /* Gain: '<S118>/Gain1' */
    rtb_Gain1 = 0.8660254037844386 * rtDW.Sum;

    /* Sum: '<S118>/Sum' */
    rtDW.Sum = rtb_Gain + rtb_Gain1;

    /* Sum: '<S118>/Sum1' */
    rtDW.Sum1 = rtb_Gain - rtb_Gain1;
}

/* Output and update for atomic system: '<S6>/ei_t' */
static void ei_t(void)
{
    /* Gain: '<S119>/Gain' incorporates:
     *  MinMax: '<S119>/Max'
     *  MinMax: '<S119>/Min'
     *  Sum: '<S119>/Sum'
     */
    rtDW.Gain = (fmin(fmin(rtDW.u_alpha, rtDW.Sum), rtDW.Sum1) + fmax(fmax
                  (rtDW.u_alpha, rtDW.Sum), rtDW.Sum1)) * -0.5;
}

/* Output and update for atomic system: '<S2>/SVPWM2' */
static void SVPWM2(void)
{
    /* Outputs for Atomic SubSystem: '<S6>/InvClark' */
    InvClark();

    /* End of Outputs for SubSystem: '<S6>/InvClark' */

    /* Outputs for Atomic SubSystem: '<S6>/ei_t' */
    ei_t();

    /* End of Outputs for SubSystem: '<S6>/ei_t' */

    /* Gain: '<S6>/Gain1' incorporates:
     *  Constant: '<S6>/Constant1'
     *  Gain: '<S6>/Gain'
     *  Inport: '<Root>/Vbus'
     *  Product: '<S6>/Divide'
     *  Sum: '<S6>/Sum'
     *  Sum: '<S6>/Sum1'
     */
    rtDW.Gain1[0] = (-(rtDW.Gain + rtDW.u_alpha) / rtU.Vbus + 0.5) * 4199.0;
    rtDW.Gain1[1] = (-(rtDW.Gain + rtDW.Sum) / rtU.Vbus + 0.5) * 4199.0;
    rtDW.Gain1[2] = (-(rtDW.Gain + rtDW.Sum1) / rtU.Vbus + 0.5) * 4199.0;
}

/* Output and update for atomic system: '<S2>/inv_park' */
static void inv_park(void)
{
    /* Sum: '<S7>/u_alpha_sum_u16' incorporates:
     *  Product: '<S7>/Product'
     *  Product: '<S7>/Product1'
     */
    rtDW.Gain = rtDW.Saturation * rtDW.u_alpha - rtDW.Sum * rtDW.Sum1;

    /* Sum: '<S7>/u_beta_sum_u16' incorporates:
     *  Product: '<S7>/Product2'
     *  Product: '<S7>/Product3'
     */
    rtDW.Sum = rtDW.Sum1 * rtDW.Saturation + rtDW.Sum * rtDW.u_alpha;
}

/* Output and update for atomic system: '<S2>/park' */
static void park(real_T param_u_i_alpha, real_T param_u_i_beta, const real_T
                 param_u_sin_cos[2], real_T *param_y_i_d, real_T *param_y_i_q)
{
    /* Product: '<S8>/Product' */
    *param_y_i_d = param_u_i_alpha * param_u_sin_cos[1];

    /* Product: '<S8>/Product1' */
    *param_y_i_q = param_u_i_beta * param_u_sin_cos[0];

    /* Sum: '<S8>/Sum' */
    *param_y_i_d += *param_y_i_q;

    /* Product: '<S8>/Product2' */
    *param_y_i_q = param_u_i_alpha * param_u_sin_cos[0];

    /* Sum: '<S8>/Sum1' incorporates:
     *  Product: '<S8>/Product3'
     */
    *param_y_i_q = param_u_i_beta * param_u_sin_cos[1] - *param_y_i_q;
}

/* Model step function */
void FOC_step(void)
{
    ClarkeInput rtb_BusConversion_InsertedFor_C;
    real_T rtb_TmpSignalConversionAtparkIn[2];
    real_T rtb_Merge;
    real_T rtb_i_alpha_clark;
    real_T rtb_i_beta_clark;

    /* If: '<S3>/If' incorporates:
     *  Constant: '<S3>/Constant'
     *  Constant: '<S3>/Constant1'
     *  Inport: '<Root>/Theta'
     *  RelationalOperator: '<S3>/Relational Operator'
     *  RelationalOperator: '<S3>/Relational Operator1'
     */
    if (rtU.Theta > 6.2831853071795862) {
        /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S121>/Action Port'
         */
        /* Sum: '<S121>/Sum' incorporates:
         *  Constant: '<S121>/Constant'
         */
        rtb_Merge = rtU.Theta - 6.2831853071795862;

        /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */
    } else if (rtU.Theta < 0.0) {
        /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
         *  ActionPort: '<S120>/Action Port'
         */
        /* Sum: '<S120>/Sum' incorporates:
         *  Constant: '<S120>/Constant'
         */
        rtb_Merge = rtU.Theta + 6.2831853071795862;

        /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */
    } else {
        /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S122>/Action Port'
         */
        /* SignalConversion generated from: '<S122>/In1' */
        rtb_Merge = rtU.Theta;

        /* End of Outputs for SubSystem: '<S3>/If Action Subsystem2' */
    }

    /* End of If: '<S3>/If' */

    /* FromWorkspace: '<S4>/fromWS_Signal 1' */
    {
        real_T *pDataValues = (real_T *) rtDW.fromWS_Signal1_PWORK.DataPtr;
        real_T *pTimeValues = (real_T *) rtDW.fromWS_Signal1_PWORK.TimePtr;
        int_T currTimeIndex = rtDW.fromWS_Signal1_IWORK.PrevIndex;
        real_T t = ((rtM->Timing.clockTick0) * 0.0001);
        if (t > pTimeValues[6]) {
            rtDW.Signal1 = 0.0;
        } else {
            /* Get index */
            if (t <= pTimeValues[0]) {
                currTimeIndex = 0;
            } else if (t >= pTimeValues[6]) {
                currTimeIndex = 5;
            } else {
                if (t < pTimeValues[currTimeIndex]) {
                    while (t < pTimeValues[currTimeIndex]) {
                        currTimeIndex--;
                    }
                } else {
                    while (t >= pTimeValues[currTimeIndex + 1]) {
                        currTimeIndex++;
                    }
                }
            }

            rtDW.fromWS_Signal1_IWORK.PrevIndex = currTimeIndex;

            /* Post output */
            {
                real_T t1 = pTimeValues[currTimeIndex];
                real_T t2 = pTimeValues[currTimeIndex + 1];
                if (t1 == t2) {
                    if (t < t1) {
                        rtDW.Signal1 = pDataValues[currTimeIndex];
                    } else {
                        rtDW.Signal1 = pDataValues[currTimeIndex + 1];
                    }
                } else {
                    real_T f1 = (t2 - t) / (t2 - t1);
                    real_T f2 = 1.0 - f1;
                    real_T d1;
                    real_T d2;
                    int_T TimeIndex = currTimeIndex;
                    d1 = pDataValues[TimeIndex];
                    d2 = pDataValues[TimeIndex + 1];
                    rtDW.Signal1 = (real_T) rtInterpolate(d1, d2, f1, f2);
                    pDataValues += 7;
                }
            }
        }
    }

    /* Outputs for Atomic SubSystem: '<S1>/FOC_CURRENT' */
    /* Trigonometry: '<S9>/SinCos' */
    rtDW.Sum1 = sin(rtb_Merge);
    rtDW.u_alpha = cos(rtb_Merge);

    /* SignalConversion generated from: '<S2>/park' */
    rtb_TmpSignalConversionAtparkIn[0] = rtDW.Sum1;
    rtb_TmpSignalConversionAtparkIn[1] = rtDW.u_alpha;

    /* End of Outputs for SubSystem: '<S1>/FOC_CURRENT' */

    /* Saturate: '<S1>/Saturation' incorporates:
     *  Inport: '<Root>/ISensA'
     */
    if (rtU.ISensA > 50.0) {
        /* Outputs for Atomic SubSystem: '<S1>/FOC_CURRENT' */
        /* BusCreator generated from: '<S2>/C Caller' */
        rtb_BusConversion_InsertedFor_C.ia = 50.0;

        /* End of Outputs for SubSystem: '<S1>/FOC_CURRENT' */
    } else if (rtU.ISensA < -50.0) {
        /* Outputs for Atomic SubSystem: '<S1>/FOC_CURRENT' */
        /* BusCreator generated from: '<S2>/C Caller' */
        rtb_BusConversion_InsertedFor_C.ia = -50.0;

        /* End of Outputs for SubSystem: '<S1>/FOC_CURRENT' */
    } else {
        /* Outputs for Atomic SubSystem: '<S1>/FOC_CURRENT' */
        /* BusCreator generated from: '<S2>/C Caller' */
        rtb_BusConversion_InsertedFor_C.ia = rtU.ISensA;

        /* End of Outputs for SubSystem: '<S1>/FOC_CURRENT' */
    }

    /* End of Saturate: '<S1>/Saturation' */

    /* Saturate: '<S1>/Saturation1' incorporates:
     *  Inport: '<Root>/ISensB'
     */
    if (rtU.ISensB > 50.0) {
        /* Outputs for Atomic SubSystem: '<S1>/FOC_CURRENT' */
        /* BusCreator generated from: '<S2>/C Caller' */
        rtb_BusConversion_InsertedFor_C.ib = 50.0;

        /* End of Outputs for SubSystem: '<S1>/FOC_CURRENT' */
    } else if (rtU.ISensB < -50.0) {
        /* Outputs for Atomic SubSystem: '<S1>/FOC_CURRENT' */
        /* BusCreator generated from: '<S2>/C Caller' */
        rtb_BusConversion_InsertedFor_C.ib = -50.0;

        /* End of Outputs for SubSystem: '<S1>/FOC_CURRENT' */
    } else {
        /* Outputs for Atomic SubSystem: '<S1>/FOC_CURRENT' */
        /* BusCreator generated from: '<S2>/C Caller' */
        rtb_BusConversion_InsertedFor_C.ib = rtU.ISensB;

        /* End of Outputs for SubSystem: '<S1>/FOC_CURRENT' */
    }

    /* End of Saturate: '<S1>/Saturation1' */

    /* Saturate: '<S1>/Saturation2' incorporates:
     *  Inport: '<Root>/ISensC'
     */
    if (rtU.ISensC > 50.0) {
        /* Outputs for Atomic SubSystem: '<S1>/FOC_CURRENT' */
        /* BusCreator generated from: '<S2>/C Caller' */
        rtb_BusConversion_InsertedFor_C.ic = 50.0;

        /* End of Outputs for SubSystem: '<S1>/FOC_CURRENT' */
    } else if (rtU.ISensC < -50.0) {
        /* Outputs for Atomic SubSystem: '<S1>/FOC_CURRENT' */
        /* BusCreator generated from: '<S2>/C Caller' */
        rtb_BusConversion_InsertedFor_C.ic = -50.0;

        /* End of Outputs for SubSystem: '<S1>/FOC_CURRENT' */
    } else {
        /* Outputs for Atomic SubSystem: '<S1>/FOC_CURRENT' */
        /* BusCreator generated from: '<S2>/C Caller' */
        rtb_BusConversion_InsertedFor_C.ic = rtU.ISensC;

        /* End of Outputs for SubSystem: '<S1>/FOC_CURRENT' */
    }

    /* End of Saturate: '<S1>/Saturation2' */

    /* Outputs for Atomic SubSystem: '<S1>/FOC_CURRENT' */
    /* CCaller: '<S2>/C Caller' */
    ClarkeTransform(&rtb_BusConversion_InsertedFor_C, &rtb_i_alpha_clark,
                    &rtb_i_beta_clark);

    /* Outputs for Atomic SubSystem: '<S2>/park' */
    park(rtb_i_alpha_clark, rtb_i_beta_clark, rtb_TmpSignalConversionAtparkIn,
         &rtDW.Sum, &rtDW.Gain);

    /* End of Outputs for SubSystem: '<S2>/park' */

    /* Outputs for Atomic SubSystem: '<S2>/CurrentLoop' */
    CurrentLoop();

    /* End of Outputs for SubSystem: '<S2>/CurrentLoop' */

    /* Outputs for Atomic SubSystem: '<S2>/inv_park' */
    inv_park();

    /* End of Outputs for SubSystem: '<S2>/inv_park' */

    /* Outputs for Atomic SubSystem: '<S2>/SVPWM2' */
    SVPWM2();

    /* End of Outputs for SubSystem: '<S2>/SVPWM2' */
    /* End of Outputs for SubSystem: '<S1>/FOC_CURRENT' */

    /* Outport: '<Root>/tAout' */
    rtY.tAout = rtDW.Gain1[0];

    /* Outport: '<Root>/tBout' */
    rtY.tBout = rtDW.Gain1[1];

    /* Outport: '<Root>/tCout' */
    rtY.tCout = rtDW.Gain1[2];

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.0001, which is the step size
     * of the task. Size of "clockTick0" ensures timer will not overflow during the
     * application lifespan selected.
     */
    rtM->Timing.clockTick0++;
}

/* Model initialize function */
void FOC_initialize(void)
{
    /* Start for FromWorkspace: '<S4>/fromWS_Signal 1' */
    {
        static real_T pTimeValues0[] = { 0.0, 1.627, 5.261, 7.006, 7.402, 8.751,
            10.0 } ;

        static real_T pDataValues0[] = { 0.0, 18.0, 12.0, 18.0, -9.0, -15.0, 0.0
        } ;

        rtDW.fromWS_Signal1_PWORK.TimePtr = (void *) pTimeValues0;
        rtDW.fromWS_Signal1_PWORK.DataPtr = (void *) pDataValues0;
        rtDW.fromWS_Signal1_IWORK.PrevIndex = 0;
    }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
