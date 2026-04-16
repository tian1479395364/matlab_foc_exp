#include "FOC_CURRENTLOOP_DOUBLE.h"
#include "jscl_transform.h"
#include "rtwtypes.h"
#include <math.h>
#include <float.h>

#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

VectorUVW_T measureCureent_s;
real_T s16_PwmOnTicks[3];
DW rtDW;
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_modd(real_T u0, real_T u1);
static void SVPWM_func(void);
static void FOC_CURRENT(void);
static void rate_scheduler(void);
static void rate_scheduler(void)
{
    (rtM->Timing.TaskCounters.TID[1])++;
    if ((rtM->Timing.TaskCounters.TID[1]) > 1) {
        rtM->Timing.TaskCounters.TID[1] = 0;
    }
}

static void SVPWM_func(void)
{
    VectorUVW_T local_voltage_uvw;
    real_T local_ZeroSequenceVoltage;
    InverseClarkeTransform(&rtDW.invpark, &local_voltage_uvw);
    CalcZeroSequenceVoltage(&local_voltage_uvw, &local_ZeroSequenceVoltage);
    SVPWM_CalcDutyCycle(local_ZeroSequenceVoltage, &local_voltage_uvw,
                        rtDW.RateTransition7, &s16_PwmOnTicks[0]);
}

static void FOC_CURRENT(void)
{
    VectorAB_T local_ClarkeTransform;
    VectorDQ_T local_ParkTransform;
    VectorDQ_T local_currentLoopDQ;
    real_T local_sine_cose_theta[2];
    sincos_func(rtDW.Merge, &local_sine_cose_theta[0]);
    ClarkeTransform(&measureCureent_s, &local_ClarkeTransform);
    ParkTransform(&local_ClarkeTransform, &local_sine_cose_theta[0],
                  &local_ParkTransform);
    CurrentLoopDQ(0.0, local_ParkTransform.s64_d, rtDW.IRefQ,
                  local_ParkTransform.s64_q, 0.24527670483636954,
                  221.54511393115223, 0.24527670483636954, 221.54511393115223,
                  &local_currentLoopDQ);
    InverseParkTransform(&local_sine_cose_theta[0], &local_currentLoopDQ,
                         &rtDW.invpark);
    SVPWM_func();
}

real_T rt_modd(real_T u0, real_T u1)
{
    real_T y;
    y = u0;
    if (u1 == 0.0) {
        if (u0 == 0.0) {
            y = u1;
        }
    } else if (u0 == 0.0) {
        y = 0.0 / u1;
    } else {
        boolean_T yEq;
        y = fmod(u0, u1);
        yEq = (y == 0.0);
        if ((!yEq) && (u1 > floor(u1))) {
            real_T q;
            q = fabs(u0 / u1);
            yEq = (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q);
        }

        if (yEq) {
            y = 0.0;
        } else if ((u0 < 0.0) != (u1 < 0.0)) {
            y += u1;
        }
    }

    return y;
}

void FOC_CURRENTLOOP_DOUBLE_step(void)
{
    real_T local_Add_l;
    real_T local_DiscreteTimeIntegrator3;
    real_T local_DiscreteTimeIntegrator3_e;
    real_T local_Mod;
    real_T local_Product_jc_idx_0;
    real_T local_Product_jc_idx_1;
    real_T local_Product_jc_idx_2;
    real_T local_Switch1;
    real_T local_sine_cosine_o1;
    real_T local_sine_cosine_o2;
    real_T u0;
    if (rtM->Timing.TaskCounters.TID[1] == 0) {
        rtDW.PWM[0] = rtDW.RateTransition_Buffer0[0];
        rtDW.PWM[1] = rtDW.RateTransition_Buffer0[1];
        rtDW.PWM[2] = rtDW.RateTransition_Buffer0[2];
    }

    local_Product_jc_idx_0 = -(0.00023815194093831864 * rtDW.PWM[0] - 0.5) + 0.5;
    if (local_Product_jc_idx_0 > 1.0) {
        local_Product_jc_idx_0 = 1.0;
    } else if (local_Product_jc_idx_0 < 0.0) {
        local_Product_jc_idx_0 = 0.0;
    }

    local_Product_jc_idx_1 = -(0.00023815194093831864 * rtDW.PWM[1] - 0.5) + 0.5;
    if (local_Product_jc_idx_1 > 1.0) {
        local_Product_jc_idx_1 = 1.0;
    } else if (local_Product_jc_idx_1 < 0.0) {
        local_Product_jc_idx_1 = 0.0;
    }

    local_Product_jc_idx_2 = -(0.00023815194093831864 * rtDW.PWM[2] - 0.5) + 0.5;
    if (local_Product_jc_idx_2 > 1.0) {
        local_Product_jc_idx_2 = 1.0;
    } else if (local_Product_jc_idx_2 < 0.0) {
        local_Product_jc_idx_2 = 0.0;
    }

    local_sine_cosine_o2 = ((local_Product_jc_idx_1 + local_Product_jc_idx_2) +
                            local_Product_jc_idx_0) * 0.33333333333333331;
    local_Product_jc_idx_0 = (local_Product_jc_idx_0 - local_sine_cosine_o2) *
        24.0;
    local_Product_jc_idx_1 = (local_Product_jc_idx_1 - local_sine_cosine_o2) *
        24.0;
    local_Product_jc_idx_2 = (local_Product_jc_idx_2 - local_sine_cosine_o2) *
        24.0;
    if (rtDW.DiscreteTimeIntegrator3_IC_LOAD != 0) {
        rtDW.DiscreteTimeIntegrator3_DSTATE = 0.0;
        if (rtDW.DiscreteTimeIntegrator3_DSTATE > 1.0E+7) {
            rtDW.DiscreteTimeIntegrator3_DSTATE = 1.0E+7;
        } else if (rtDW.DiscreteTimeIntegrator3_DSTATE < -1.0E+7) {
            rtDW.DiscreteTimeIntegrator3_DSTATE = -1.0E+7;
        }
    }

    local_DiscreteTimeIntegrator3_e = rtDW.DiscreteTimeIntegrator3_DSTATE;
    if (rtDW.UnitDelay_DSTATE >= -3.1415926535897931) {
        if (rtDW.UnitDelay_DSTATE <= 3.1415926535897931) {
            local_Switch1 = rtDW.UnitDelay_DSTATE;
        } else {
            local_Switch1 = rtDW.UnitDelay_DSTATE - 6.2831854820251465;
        }
    } else {
        local_Switch1 = rtDW.UnitDelay_DSTATE + 6.2831854820251465;
    }

    local_sine_cosine_o2 = 5.0 * local_Switch1;
    local_sine_cosine_o1 = sin(local_sine_cosine_o2);
    local_sine_cosine_o2 = cos(local_sine_cosine_o2);
    if (rtDW.DiscreteTimeIntegrator3_IC_LO_l != 0) {
        rtDW.DiscreteTimeIntegrator3_DSTAT_p = 0.0;
        if (rtDW.DiscreteTimeIntegrator3_DSTAT_p > 1.0E+7) {
            rtDW.DiscreteTimeIntegrator3_DSTAT_p = 1.0E+7;
        } else if (rtDW.DiscreteTimeIntegrator3_DSTAT_p < -1.0E+7) {
            rtDW.DiscreteTimeIntegrator3_DSTAT_p = -1.0E+7;
        }
    }

    local_DiscreteTimeIntegrator3 = rtDW.DiscreteTimeIntegrator3_DSTAT_p;
    local_Add_l = rtDW.DiscreteTimeIntegrator3_DSTATE * local_sine_cosine_o2 -
        rtDW.DiscreteTimeIntegrator3_DSTAT_p * local_sine_cosine_o1;
    local_Mod = rtDW.DiscreteTimeIntegrator3_DSTATE * local_sine_cosine_o1 +
        rtDW.DiscreteTimeIntegrator3_DSTAT_p * local_sine_cosine_o2;
    if (rtM->Timing.TaskCounters.TID[1] == 0) {
        if (local_Add_l > 50.0) {
            measureCureent_s.s64_u = 50.0;
        } else if (local_Add_l < -50.0) {
            measureCureent_s.s64_u = -50.0;
        } else {
            measureCureent_s.s64_u = local_Add_l;
        }

        u0 = -0.5 * local_Add_l + 0.8660254037844386 * local_Mod;
        if (u0 > 50.0) {
            measureCureent_s.s64_v = 50.0;
        } else if (u0 < -50.0) {
            measureCureent_s.s64_v = -50.0;
        } else {
            measureCureent_s.s64_v = u0;
        }

        u0 = -0.5 * local_Add_l + -0.8660254037844386 * local_Mod;
        if (u0 > 50.0) {
            measureCureent_s.s64_w = 50.0;
        } else if (u0 < -50.0) {
            measureCureent_s.s64_w = -50.0;
        } else {
            measureCureent_s.s64_w = u0;
        }

        rtDW.Merge = rt_modd(5.0 * local_Switch1, 6.2831853071795862);
        rtDW.RateTransition7 = 24.0;

        {
            real_T t = ((rtM->Timing.clockTick1) * 0.0001);
            real_T *pTimeValues = (real_T *) rtDW.fromWS_Signal1_PWORK.TimePtr;
            real_T *pDataValues = (real_T *) rtDW.fromWS_Signal1_PWORK.DataPtr;
            if (t < pTimeValues[0]) {
                rtDW.IRefQ = 0.0;
            } else if (t == pTimeValues[6]) {
                rtDW.IRefQ = pDataValues[6];
            } else if (t > pTimeValues[6]) {
                rtDW.IRefQ = 0.0;
            } else {
                int_T currTimeIndex = rtDW.fromWS_Signal1_IWORK.PrevIndex;
                if (t < pTimeValues[currTimeIndex]) {
                    while (t < pTimeValues[currTimeIndex]) {
                        currTimeIndex--;
                    }
                } else {
                    while (t >= pTimeValues[currTimeIndex + 1]) {
                        currTimeIndex++;
                    }
                }

                rtDW.IRefQ = pDataValues[currTimeIndex];
                rtDW.fromWS_Signal1_IWORK.PrevIndex = currTimeIndex;
            }
        }

        FOC_CURRENT();
        rtDW.RateTransition_Buffer0[0] = s16_PwmOnTicks[0];
        rtDW.RateTransition_Buffer0[1] = s16_PwmOnTicks[1];
        rtDW.RateTransition_Buffer0[2] = s16_PwmOnTicks[2];
    }

    local_Add_l = (0.66666666666666663 * local_Product_jc_idx_0 +
                   -0.33333333333333331 * local_Product_jc_idx_1) +
        -0.33333333333333331 * local_Product_jc_idx_2;
    local_Mod = 0.57735026918962573 * local_Product_jc_idx_1 +
        -0.57735026918962573 * local_Product_jc_idx_2;
    local_Product_jc_idx_0 = 5.0 * rtDW.DiscreteTimeIntegrator_DSTATE;
    rtDW.DiscreteTimeIntegrator3_IC_LOAD = 0U;
    rtDW.DiscreteTimeIntegrator3_DSTATE += (((local_Add_l * local_sine_cosine_o2
        + local_Mod * local_sine_cosine_o1) / 0.000195185 +
        local_Product_jc_idx_0 * local_DiscreteTimeIntegrator3 * 0.000195185 /
        0.000195185) - local_DiscreteTimeIntegrator3_e * 0.1763 / 0.000195185) *
        5.0E-5;
    if (rtDW.DiscreteTimeIntegrator3_DSTATE > 1.0E+7) {
        rtDW.DiscreteTimeIntegrator3_DSTATE = 1.0E+7;
    } else if (rtDW.DiscreteTimeIntegrator3_DSTATE < -1.0E+7) {
        rtDW.DiscreteTimeIntegrator3_DSTATE = -1.0E+7;
    }

    rtDW.UnitDelay_DSTATE = 5.0E-5 * rtDW.DiscreteTimeIntegrator_DSTATE +
        local_Switch1;
    rtDW.DiscreteTimeIntegrator3_IC_LO_l = 0U;
    rtDW.DiscreteTimeIntegrator3_DSTAT_p += ((((local_Mod * local_sine_cosine_o2
        - local_Add_l * local_sine_cosine_o1) / 0.000195185 -
        local_DiscreteTimeIntegrator3_e * local_Product_jc_idx_0 * 0.000195185 /
        0.000195185) - local_Product_jc_idx_0 * 0.0109 / 0.000195185) -
        local_DiscreteTimeIntegrator3 * 0.1763 / 0.000195185) * 5.0E-5;
    if (rtDW.DiscreteTimeIntegrator3_DSTAT_p > 1.0E+7) {
        rtDW.DiscreteTimeIntegrator3_DSTAT_p = 1.0E+7;
    } else if (rtDW.DiscreteTimeIntegrator3_DSTAT_p < -1.0E+7) {
        rtDW.DiscreteTimeIntegrator3_DSTAT_p = -1.0E+7;
    }

    rtDW.DiscreteTimeIntegrator_DSTATE += ((0.0109 *
        local_DiscreteTimeIntegrator3 * 7.5 - 0.05 *
        rtDW.DiscreteTimeIntegrator_DSTATE) - rtDW.DiscreteTimeIntegrator_DSTATE
        * 0.000159) / 0.00058 * 5.0E-5;
    if (rtDW.DiscreteTimeIntegrator_DSTATE > 1.0E+7) {
        rtDW.DiscreteTimeIntegrator_DSTATE = 1.0E+7;
    } else if (rtDW.DiscreteTimeIntegrator_DSTATE < -1.0E+7) {
        rtDW.DiscreteTimeIntegrator_DSTATE = -1.0E+7;
    }

    if (rtM->Timing.TaskCounters.TID[1] == 0) {
        rtM->Timing.clockTick1++;
    }

    rate_scheduler();
}

void FOC_CURRENTLOOP_DOUBLE_initialize(void)
{
    {
        static real_T pTimeValues0[] = { 0.0, 1.627, 5.261, 7.006, 7.402, 8.751,
            10.0 } ;

        static real_T pDataValues0[] = { 0.0, 18.0, 12.0, 18.0, -9.0, -15.0, 0.0
        } ;

        rtDW.fromWS_Signal1_PWORK.TimePtr = (void *) pTimeValues0;
        rtDW.fromWS_Signal1_PWORK.DataPtr = (void *) pDataValues0;
        rtDW.fromWS_Signal1_IWORK.PrevIndex = 0;
    }

    rtDW.DiscreteTimeIntegrator3_IC_LOAD = 1U;
    rtDW.DiscreteTimeIntegrator3_IC_LO_l = 1U;
}
