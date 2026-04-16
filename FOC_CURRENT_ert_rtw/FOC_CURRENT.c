#include "FOC_CURRENT.h"
#include "jscl_transform.h"
#include "rtwtypes.h"

VectorUVW_T measureCureent_s;
real_T s16_PwmOnTicks[3];
DW rtDW;
ExtU rtU;
static void SVPWM_func(void);
static void SVPWM_func(void)
{
    VectorUVW_T local_voltage_uvw;
    real_T local_ZeroSequenceVoltage;
    InverseClarkeTransform(&rtDW.invpark, &local_voltage_uvw);
    CalcZeroSequenceVoltage(&local_voltage_uvw, &local_ZeroSequenceVoltage);
    SVPWM_CalcDutyCycle(local_ZeroSequenceVoltage, &local_voltage_uvw, rtU.Vbus,
                        &s16_PwmOnTicks[0]);
}

void FOC_CURRENT_step(void)
{
    VectorAB_T local_ClarkeTransform;
    VectorDQ_T local_ParkTransform;
    VectorDQ_T local_currentLoopDQ;
    real_T local_sine_cose_theta[2];
    sincos_func(rtU.theta, &local_sine_cose_theta[0]);
    ClarkeTransform((const VectorUVW_T *)&measureCureent_s,
                    &local_ClarkeTransform);
    ParkTransform(&local_ClarkeTransform, &local_sine_cose_theta[0],
                  &local_ParkTransform);
    CurrentLoopDQ(rtU.IRefD, local_ParkTransform.s64_d, rtU.IRefQ,
                  local_ParkTransform.s64_q, 0.24527670483636954,
                  221.54511393115223, 0.24527670483636954, 221.54511393115223,
                  &local_currentLoopDQ);
    InverseParkTransform(&local_sine_cose_theta[0], &local_currentLoopDQ,
                         &rtDW.invpark);
    SVPWM_func();
}

void FOC_CURRENT_initialize(void)
{
}
