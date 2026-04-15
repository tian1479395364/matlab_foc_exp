#include "FOC_CURRENT.h"
#include "jscl_transform.h"
#include "rtwtypes.h"
#include <math.h>

DW rtDW;
ExtU rtU;
ExtY rtY;
static void SVPWM1(void);
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
    rtDW.Gain3[0] = (-rtb_Sum2_idx_0 / rtU.Vbus + 0.5) * 4199.0;
    rtDW.Gain3[1] = (-rtb_Sum2_idx_1 / rtU.Vbus + 0.5) * 4199.0;
    rtDW.Gain3[2] = (-rtb_eit / rtU.Vbus + 0.5) * 4199.0;
}

void FOC_CURRENT_step(void)
{
    VectorAB_T rtb_ClarkeTransform;
    VectorDQ_T rtb_ParkTransform;
    VectorDQ_T rtb_currentLoopDQ;
    VectorUVW_T rtb_BusConversion_InsertedFor_C;
    real_T rtb_TmpSignalConversionAtParkTr[2];
    rtb_TmpSignalConversionAtParkTr[0] = sin(rtU.theta);
    rtb_TmpSignalConversionAtParkTr[1] = cos(rtU.theta);
    rtb_BusConversion_InsertedFor_C.s64_u = rtU.s64_u;
    rtb_BusConversion_InsertedFor_C.s64_v = rtU.s64_v;
    rtb_BusConversion_InsertedFor_C.s64_w = rtU.s64_w;
    ClarkeTransform(&rtb_BusConversion_InsertedFor_C, &rtb_ClarkeTransform);
    ParkTransform(&rtb_ClarkeTransform, &rtb_TmpSignalConversionAtParkTr[0],
                  &rtb_ParkTransform);
    CurrentLoopDQ(rtU.IRefD, rtb_ParkTransform.s64_d, rtU.IRefQ,
                  rtb_ParkTransform.s64_q, 0.24527670483636954,
                  221.54511393115223, 0.24527670483636954, 221.54511393115223,
                  &rtb_currentLoopDQ);
    InverseParkTransform(&rtb_currentLoopDQ, &rtb_TmpSignalConversionAtParkTr[0],
                         &rtDW.invpark);
    SVPWM1();
    rtY.tAout = rtDW.Gain3[0];
    rtY.tBout = rtDW.Gain3[1];
    rtY.tCout = rtDW.Gain3[2];
}

void FOC_CURRENT_initialize(void)
{
}
