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

DW rtDW;
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_modd(real_T u0, real_T u1);
static void SVPWM1(void);
static void rate_scheduler(void);
static void rate_scheduler(void)
{
    (rtM->Timing.TaskCounters.TID[1])++;
    if ((rtM->Timing.TaskCounters.TID[1]) > 1) {
        rtM->Timing.TaskCounters.TID[1] = 0;
    }
}

static void SVPWM1(void)
{
    VectorUVW_T rtb_spwm;
    real_T rtb_Sum2_idx_0;
    real_T rtb_Sum2_idx_1;
    real_T rtb_eit;
    InverseClarkeTransform(&rtDW.invpark, &rtb_spwm);
    CalcZeroSequenceVoltage(&rtb_spwm, &rtb_eit);
    rtb_Sum2_idx_0 = rtb_eit + rtb_spwm.s64_u;
    rtb_Sum2_idx_1 = rtb_eit + rtb_spwm.s64_v;
    rtb_eit += rtb_spwm.s64_w;
    rtDW.Gain3[0] = (-rtb_Sum2_idx_0 / rtDW.RateTransition7 + 0.5) * 4199.0;
    rtDW.Gain3[1] = (-rtb_Sum2_idx_1 / rtDW.RateTransition7 + 0.5) * 4199.0;
    rtDW.Gain3[2] = (-rtb_eit / rtDW.RateTransition7 + 0.5) * 4199.0;
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
    real_T rtb_Signal1;
    VectorAB_T rtb_ClarkeTransform;
    VectorDQ_T rtb_ParkTransform;
    VectorDQ_T rtb_currentLoopDQ;
    VectorUVW_T rtb_BusConversion_InsertedFor_C;
    real_T rtb_TmpSignalConversionAtParkTr[2];
    real_T rtb_Add_k;
    real_T rtb_Divide;
    real_T rtb_Gain4;
    real_T rtb_Mod;
    real_T rtb_Product;
    real_T rtb_Product_c;
    real_T rtb_Product_e;
    real_T rtb_Product_gk;
    real_T rtb_Product_jc_idx_0;
    real_T rtb_Product_jc_idx_1;
    real_T rtb_Product_jc_idx_2;
    real_T rtb_Product_l;
    real_T rtb_sine_cosine_o1;
    real_T rtb_sine_cosine_o2;
    if (rtM->Timing.TaskCounters.TID[1] == 0) {
        rtDW.RateTransition = rtDW.RateTransition_Buffer0;
        rtDW.RateTransition1 = rtDW.RateTransition1_Buffer0;
        rtDW.RateTransition2 = rtDW.RateTransition2_Buffer0;
    }

    rtb_Product_jc_idx_0 = -(0.00023815194093831864 * rtDW.RateTransition - 0.5)
        + 0.5;
    if (rtb_Product_jc_idx_0 > 1.0) {
        rtb_Product_jc_idx_0 = 1.0;
    } else if (rtb_Product_jc_idx_0 < 0.0) {
        rtb_Product_jc_idx_0 = 0.0;
    }

    rtb_Product_jc_idx_1 = -(0.00023815194093831864 * rtDW.RateTransition1 - 0.5)
        + 0.5;
    if (rtb_Product_jc_idx_1 > 1.0) {
        rtb_Product_jc_idx_1 = 1.0;
    } else if (rtb_Product_jc_idx_1 < 0.0) {
        rtb_Product_jc_idx_1 = 0.0;
    }

    rtb_Product_jc_idx_2 = -(0.00023815194093831864 * rtDW.RateTransition2 - 0.5)
        + 0.5;
    if (rtb_Product_jc_idx_2 > 1.0) {
        rtb_Product_jc_idx_2 = 1.0;
    } else if (rtb_Product_jc_idx_2 < 0.0) {
        rtb_Product_jc_idx_2 = 0.0;
    }

    rtb_sine_cosine_o2 = ((rtb_Product_jc_idx_1 + rtb_Product_jc_idx_2) +
                          rtb_Product_jc_idx_0) * 0.33333333333333331;
    rtb_Product_jc_idx_0 = (rtb_Product_jc_idx_0 - rtb_sine_cosine_o2) * 24.0;
    rtb_Product_jc_idx_1 = (rtb_Product_jc_idx_1 - rtb_sine_cosine_o2) * 24.0;
    rtb_Product_jc_idx_2 = (rtb_Product_jc_idx_2 - rtb_sine_cosine_o2) * 24.0;
    if (rtDW.DiscreteTimeIntegrator3_IC_LOAD != 0) {
        rtDW.DiscreteTimeIntegrator3_DSTATE = 0.0;
        if (rtDW.DiscreteTimeIntegrator3_DSTATE > 1.0E+7) {
            rtDW.DiscreteTimeIntegrator3_DSTATE = 1.0E+7;
        } else if (rtDW.DiscreteTimeIntegrator3_DSTATE < -1.0E+7) {
            rtDW.DiscreteTimeIntegrator3_DSTATE = -1.0E+7;
        }
    }

    rtb_Product = rtDW.DiscreteTimeIntegrator3_DSTATE * 0.1763 / 0.000195185;
    if (rtDW.UnitDelay_DSTATE >= -3.1415926535897931) {
        if (rtDW.UnitDelay_DSTATE <= 3.1415926535897931) {
            rtb_Mod = rtDW.UnitDelay_DSTATE;
        } else {
            rtb_Mod = rtDW.UnitDelay_DSTATE - 6.2831854820251465;
        }
    } else {
        rtb_Mod = rtDW.UnitDelay_DSTATE + 6.2831854820251465;
    }

    rtb_Gain4 = 5.0 * rtb_Mod;
    rtb_sine_cosine_o1 = sin(rtb_Gain4);
    rtb_sine_cosine_o2 = cos(rtb_Gain4);
    rtb_Product_jc_idx_0 = (0.66666666666666663 * rtb_Product_jc_idx_0 +
                            -0.33333333333333331 * rtb_Product_jc_idx_1) +
        -0.33333333333333331 * rtb_Product_jc_idx_2;
    rtb_Gain4 = 0.57735026918962573 * rtb_Product_jc_idx_1 +
        -0.57735026918962573 * rtb_Product_jc_idx_2;
    rtb_Product_jc_idx_1 = (rtb_Gain4 * rtb_sine_cosine_o2 -
                            rtb_Product_jc_idx_0 * rtb_sine_cosine_o1) /
        0.000195185;
    if (rtDW.DiscreteTimeIntegrator3_IC_LO_o != 0) {
        rtDW.DiscreteTimeIntegrator3_DSTAT_l = 0.0;
        if (rtDW.DiscreteTimeIntegrator3_DSTAT_l > 1.0E+7) {
            rtDW.DiscreteTimeIntegrator3_DSTAT_l = 1.0E+7;
        } else if (rtDW.DiscreteTimeIntegrator3_DSTAT_l < -1.0E+7) {
            rtDW.DiscreteTimeIntegrator3_DSTAT_l = -1.0E+7;
        }
    }

    rtb_Product_jc_idx_2 = 5.0 * rtDW.DiscreteTimeIntegrator_DSTATE;
    rtb_Product_c = rtDW.DiscreteTimeIntegrator3_DSTAT_l * rtb_Product_jc_idx_2 *
        0.000195185 / 0.000195185;
    rtb_Product_gk = rtb_Product_jc_idx_2 * 0.0109 / 0.000195185;
    rtb_Product_e = rtb_Product_jc_idx_2 * rtDW.DiscreteTimeIntegrator3_DSTATE *
        0.000195185 / 0.000195185;
    rtb_Product_jc_idx_0 = (rtb_Product_jc_idx_0 * rtb_sine_cosine_o2 +
                            rtb_Gain4 * rtb_sine_cosine_o1) / 0.000195185;
    rtb_Product_l = rtDW.DiscreteTimeIntegrator3_DSTAT_l * 0.1763 / 0.000195185;
    rtb_Divide = ((0.0109 * rtDW.DiscreteTimeIntegrator3_DSTATE * 7.5 - 0.05 *
                   rtDW.DiscreteTimeIntegrator_DSTATE) -
                  rtDW.DiscreteTimeIntegrator_DSTATE * 0.000159) / 0.00058;
    rtb_Add_k = 5.0E-5 * rtDW.DiscreteTimeIntegrator_DSTATE + rtb_Mod;
    rtb_Product_jc_idx_2 = rtDW.DiscreteTimeIntegrator3_DSTAT_l *
        rtb_sine_cosine_o2 - rtDW.DiscreteTimeIntegrator3_DSTATE *
        rtb_sine_cosine_o1;
    rtb_Gain4 = rtDW.DiscreteTimeIntegrator3_DSTAT_l * rtb_sine_cosine_o1 +
        rtDW.DiscreteTimeIntegrator3_DSTATE * rtb_sine_cosine_o2;
    rtb_Mod = rt_modd(5.0 * rtb_Mod, 6.2831853071795862);
    if (rtM->Timing.TaskCounters.TID[1] == 0) {
        rtDW.RateTransition7 = 24.0;

        {
            real_T *pDataValues = (real_T *) rtDW.fromWS_Signal1_PWORK.DataPtr;
            real_T *pTimeValues = (real_T *) rtDW.fromWS_Signal1_PWORK.TimePtr;
            int_T currTimeIndex = rtDW.fromWS_Signal1_IWORK.PrevIndex;
            real_T t = ((rtM->Timing.clockTick1) * 0.0001);
            if (t > pTimeValues[6]) {
                rtb_Signal1 = 0.0;
            } else {
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

        rtb_TmpSignalConversionAtParkTr[0] = sin(rtb_Mod);
        rtb_TmpSignalConversionAtParkTr[1] = cos(rtb_Mod);
        if (rtb_Product_jc_idx_2 > 50.0) {
            rtb_BusConversion_InsertedFor_C.s64_u = 50.0;
        } else if (rtb_Product_jc_idx_2 < -50.0) {
            rtb_BusConversion_InsertedFor_C.s64_u = -50.0;
        } else {
            rtb_BusConversion_InsertedFor_C.s64_u = rtb_Product_jc_idx_2;
        }

        rtb_sine_cosine_o2 = -0.5 * rtb_Product_jc_idx_2 + 0.8660254037844386 *
            rtb_Gain4;
        if (rtb_sine_cosine_o2 > 50.0) {
            rtb_BusConversion_InsertedFor_C.s64_v = 50.0;
        } else if (rtb_sine_cosine_o2 < -50.0) {
            rtb_BusConversion_InsertedFor_C.s64_v = -50.0;
        } else {
            rtb_BusConversion_InsertedFor_C.s64_v = rtb_sine_cosine_o2;
        }

        rtb_sine_cosine_o2 = -0.5 * rtb_Product_jc_idx_2 + -0.8660254037844386 *
            rtb_Gain4;
        if (rtb_sine_cosine_o2 > 50.0) {
            rtb_BusConversion_InsertedFor_C.s64_w = 50.0;
        } else if (rtb_sine_cosine_o2 < -50.0) {
            rtb_BusConversion_InsertedFor_C.s64_w = -50.0;
        } else {
            rtb_BusConversion_InsertedFor_C.s64_w = rtb_sine_cosine_o2;
        }

        ClarkeTransform(&rtb_BusConversion_InsertedFor_C, &rtb_ClarkeTransform);
        ParkTransform(&rtb_ClarkeTransform, &rtb_TmpSignalConversionAtParkTr[0],
                      &rtb_ParkTransform);
        CurrentLoopDQ(0.0, rtb_ParkTransform.s64_d, rtb_Signal1,
                      rtb_ParkTransform.s64_q, 0.24527670483636954,
                      221.54511393115223, 0.24527670483636954,
                      221.54511393115223, &rtb_currentLoopDQ);
        InverseParkTransform(&rtb_currentLoopDQ,
                             &rtb_TmpSignalConversionAtParkTr[0], &rtDW.invpark);
        SVPWM1();
        rtDW.RateTransition_Buffer0 = rtDW.Gain3[0];
        rtDW.RateTransition1_Buffer0 = rtDW.Gain3[1];
        rtDW.RateTransition2_Buffer0 = rtDW.Gain3[2];
    }

    rtDW.DiscreteTimeIntegrator3_IC_LOAD = 0U;
    rtDW.DiscreteTimeIntegrator3_DSTATE += (((rtb_Product_jc_idx_1 -
        rtb_Product_c) - rtb_Product_gk) - rtb_Product) * 5.0E-5;
    if (rtDW.DiscreteTimeIntegrator3_DSTATE > 1.0E+7) {
        rtDW.DiscreteTimeIntegrator3_DSTATE = 1.0E+7;
    } else if (rtDW.DiscreteTimeIntegrator3_DSTATE < -1.0E+7) {
        rtDW.DiscreteTimeIntegrator3_DSTATE = -1.0E+7;
    }

    rtDW.UnitDelay_DSTATE = rtb_Add_k;
    rtDW.DiscreteTimeIntegrator3_IC_LO_o = 0U;
    rtDW.DiscreteTimeIntegrator3_DSTAT_l += ((rtb_Product_jc_idx_0 +
        rtb_Product_e) - rtb_Product_l) * 5.0E-5;
    if (rtDW.DiscreteTimeIntegrator3_DSTAT_l > 1.0E+7) {
        rtDW.DiscreteTimeIntegrator3_DSTAT_l = 1.0E+7;
    } else if (rtDW.DiscreteTimeIntegrator3_DSTAT_l < -1.0E+7) {
        rtDW.DiscreteTimeIntegrator3_DSTAT_l = -1.0E+7;
    }

    rtDW.DiscreteTimeIntegrator_DSTATE += 5.0E-5 * rtb_Divide;
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
    rtDW.DiscreteTimeIntegrator3_IC_LO_o = 1U;
}
