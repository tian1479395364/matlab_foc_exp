#include "FOC_CURRENT.h"
#include "jscl_transform.h"
#include "rtwtypes.h"
#include <math.h>

DW rtDW;
ExtU rtU;
ExtY rtY;
static void SVPWM_func(void);
static void SVPWM_func(void)
{
    VectorUVW_T local_voltage_uvw;
    real_T local_ZeroSequenceVoltage;
    InverseClarkeTransform(&rtDW.invpark, &local_voltage_uvw);
    CalcZeroSequenceVoltage(&local_voltage_uvw, &local_ZeroSequenceVoltage);
    SVPWM_CalcDutyCycle(local_ZeroSequenceVoltage, &local_voltage_uvw, rtU.Vbus,
                        &rtDW.SVPWM_CalcDutyCycle[0]);
}

void FOC_CURRENT_step(void)
{
    VectorAB_T local_ClarkeTransform;
    VectorDQ_T local_ParkTransform;
    VectorDQ_T local_currentLoopDQ;
    VectorUVW_T local_BusConversion_InsertedFor;
    real_T local_sine_cose_theta[2];
    local_sine_cose_theta[0] = sin(rtU.theta);
    local_sine_cose_theta[1] = cos(rtU.theta);
    local_BusConversion_InsertedFor.s64_u = rtU.s64_u;
    local_BusConversion_InsertedFor.s64_v = rtU.s64_v;
    local_BusConversion_InsertedFor.s64_w = rtU.s64_w;
    ClarkeTransform(&local_BusConversion_InsertedFor, &local_ClarkeTransform);
    ParkTransform(&local_ClarkeTransform, &local_sine_cose_theta[0],
                  &local_ParkTransform);
    CurrentLoopDQ(rtU.IRefD, local_ParkTransform.s64_d, rtU.IRefQ,
                  local_ParkTransform.s64_q, 0.24527670483636954,
                  221.54511393115223, 0.24527670483636954, 221.54511393115223,
                  &local_currentLoopDQ);
    InverseParkTransform(&local_sine_cose_theta[0], &local_currentLoopDQ,
                         &rtDW.invpark);
    SVPWM_func();
    rtY.tAout = rtDW.SVPWM_CalcDutyCycle[0];
    rtY.tBout = rtDW.SVPWM_CalcDutyCycle[1];
    rtY.tCout = rtDW.SVPWM_CalcDutyCycle[2];
}

void FOC_CURRENT_initialize(void)
{
}
