/*
 * File: FOC.c
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
static void SVPWM1(void);

/* Output and update for atomic system: '<S2>/SVPWM1' */
static void SVPWM1(void)
{
    VectorUVW_T rtb_spwm;
    real_T rtb_Sum2_idx_0;
    real_T rtb_Sum2_idx_1;
    real_T rtb_eit;

    /* CCaller: '<S5>/C Caller' */
    InverseClarkeTransform(&rtDW.CCaller3, &rtb_spwm);

    /* CCaller: '<S5>/C Caller1' */
    CalcZeroSequenceVoltage(&rtb_spwm, &rtb_eit);

    /* Sum: '<S5>/Sum2' */
    rtb_Sum2_idx_0 = rtb_eit + rtb_spwm.s64_u;
    rtb_Sum2_idx_1 = rtb_eit + rtb_spwm.s64_v;
    rtb_eit += rtb_spwm.s64_w;

    /* Gain: '<S5>/Gain3' incorporates:
     *  Constant: '<S5>/Constant2'
     *  Gain: '<S5>/Gain2'
     *  Inport: '<Root>/Vbus'
     *  Product: '<S5>/Divide1'
     *  Sum: '<S5>/Sum3'
     */
    rtDW.Gain3[0] = (-rtb_Sum2_idx_0 / rtU.Vbus + 0.5) * 4199.0;
    rtDW.Gain3[1] = (-rtb_Sum2_idx_1 / rtU.Vbus + 0.5) * 4199.0;
    rtDW.Gain3[2] = (-rtb_eit / rtU.Vbus + 0.5) * 4199.0;
}

/* Model step function */
void FOC_step(void)
{
    /* local block i/o variables */
    real_T rtb_Signal1;
    VectorAB_T rtb_ClarkeTransform;
    VectorDQ_T rtb_BusConversion_InsertedFor_m;
    VectorUVW_T rtb_BusConversion_InsertedFor_C;
    real_T rtb_TmpSignalConversionAtCCalle[2];
    real_T rtb_CCaller2_o1;
    real_T rtb_CCaller2_o2;
    real_T rtb_Merge;

    /* If: '<S3>/If' incorporates:
     *  Constant: '<S3>/Constant'
     *  Constant: '<S3>/Constant1'
     *  Inport: '<Root>/Theta'
     *  RelationalOperator: '<S3>/Relational Operator'
     *  RelationalOperator: '<S3>/Relational Operator1'
     */
    if (rtU.Theta > 6.2831853071795862) {
        /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S8>/Action Port'
         */
        /* Sum: '<S8>/Sum' incorporates:
         *  Constant: '<S8>/Constant'
         */
        rtb_Merge = rtU.Theta - 6.2831853071795862;

        /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */
    } else if (rtU.Theta < 0.0) {
        /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
         *  ActionPort: '<S7>/Action Port'
         */
        /* Sum: '<S7>/Sum' incorporates:
         *  Constant: '<S7>/Constant'
         */
        rtb_Merge = rtU.Theta + 6.2831853071795862;

        /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */
    } else {
        /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S9>/Action Port'
         */
        /* SignalConversion generated from: '<S9>/In1' */
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
            rtb_Signal1 = 0.0;
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
                        rtb_Signal1 = pDataValues[currTimeIndex];
                    } else {
                        rtb_Signal1 = pDataValues[currTimeIndex + 1];
                    }
                } else {
                    real_T f1 = (t2 - t) / (t2 - t1);
                    real_T f2 = 1.0 - f1;
                    real_T d1;
                    real_T d2;
                    int_T TimeIndex = currTimeIndex;
                    d1 = pDataValues[TimeIndex];
                    d2 = pDataValues[TimeIndex + 1];
                    rtb_Signal1 = (real_T) rtInterpolate(d1, d2, f1, f2);
                    pDataValues += 7;
                }
            }
        }
    }

    /* Outputs for Atomic SubSystem: '<S1>/FOC_CURRENT' */
    /* SignalConversion generated from: '<S2>/C Caller3' incorporates:
     *  Trigonometry: '<S6>/SinCos'
     */
    rtb_TmpSignalConversionAtCCalle[0] = sin(rtb_Merge);
    rtb_TmpSignalConversionAtCCalle[1] = cos(rtb_Merge);

    /* BusCreator generated from: '<S2>/ClarkeTransform' incorporates:
     *  Inport: '<Root>/s64_u'
     *  Inport: '<Root>/s64_v'
     *  Inport: '<Root>/s64_w'
     */
    rtb_BusConversion_InsertedFor_C.s64_u = rtU.s64_u;
    rtb_BusConversion_InsertedFor_C.s64_v = rtU.s64_v;
    rtb_BusConversion_InsertedFor_C.s64_w = rtU.s64_w;

    /* CCaller: '<S2>/ClarkeTransform' */
    ClarkeTransform(&rtb_BusConversion_InsertedFor_C, &rtb_ClarkeTransform);

    /* CCaller: '<S2>/ParkTransform' */
    ParkTransform(&rtb_ClarkeTransform, &rtb_TmpSignalConversionAtCCalle[0],
                  &rtb_BusConversion_InsertedFor_m);

    /* CCaller: '<S2>/C Caller2' incorporates:
     *  Constant: '<S1>/Constant'
     *  Constant: '<S2>/d_ki'
     *  Constant: '<S2>/d_kp'
     *  Constant: '<S2>/q_ki'
     *  Constant: '<S2>/q_kp'
     */
    CurrentLoopDQ(0.0, rtb_BusConversion_InsertedFor_m.s64_d, rtb_Signal1,
                  rtb_BusConversion_InsertedFor_m.s64_q, 0.24527670483636954,
                  221.54511393115223, 0.24527670483636954, 221.54511393115223,
                  &rtb_CCaller2_o1, &rtb_CCaller2_o2);

    /* BusCreator generated from: '<S2>/C Caller3' */
    rtb_BusConversion_InsertedFor_m.s64_d = rtb_CCaller2_o1;
    rtb_BusConversion_InsertedFor_m.s64_q = rtb_CCaller2_o2;

    /* CCaller: '<S2>/C Caller3' */
    InverseParkTransform(&rtb_BusConversion_InsertedFor_m,
                         &rtb_TmpSignalConversionAtCCalle[0], &rtDW.CCaller3);

    /* Outputs for Atomic SubSystem: '<S2>/SVPWM1' */
    SVPWM1();

    /* End of Outputs for SubSystem: '<S2>/SVPWM1' */
    /* End of Outputs for SubSystem: '<S1>/FOC_CURRENT' */

    /* Outport: '<Root>/tAout' */
    rtY.tAout = rtDW.Gain3[0];

    /* Outport: '<Root>/tBout' */
    rtY.tBout = rtDW.Gain3[1];

    /* Outport: '<Root>/tCout' */
    rtY.tCout = rtDW.Gain3[2];

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
