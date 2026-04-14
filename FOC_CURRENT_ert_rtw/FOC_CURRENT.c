#include "FOC_CURRENT.h"
#include "rtwtypes.h"
#include <math.h>
#include "jscl_clarke.h"

DW rtDW;
ExtU rtU;
ExtY rtY;
static void park(real_T param_u_i_alpha, real_T param_u_i_beta, const real_T
                 param_u_sin_cos[2], real_T *param_y_i_d, real_T *param_y_i_q);
static void DCurrentPI(void);
static void QCurrentPI(void);
static void CurrentLoop(void);
static void InvClark(void);
static void ei_t(void);
static void SVPWM2(void);
static void inv_park(void);
static void DCurrentPI(void)
{
    real_T local_DeadZone;
    real_T local_IProdOut;
    real_T local_Sum;
    int8_T tmp;
    int8_T tmp_0;
    local_IProdOut = rtU.IRefD - rtDW.Sum;
    local_Sum = local_IProdOut * 0.24527670483636954 + rtDW.Integrator_DSTATE_f;
    if (local_Sum > 10.0) {
        local_DeadZone = local_Sum - 10.0;
        rtDW.Saturation = 10.0;
    } else {
        if (local_Sum >= -10.0) {
            local_DeadZone = 0.0;
        } else {
            local_DeadZone = local_Sum - -10.0;
        }

        if (local_Sum < -10.0) {
            rtDW.Saturation = -10.0;
        } else {
            rtDW.Saturation = local_Sum;
        }
    }

    local_IProdOut *= 221.54511393115223;
    if (local_DeadZone > 0.0) {
        tmp = 1;
    } else {
        tmp = -1;
    }

    if (local_IProdOut > 0.0) {
        tmp_0 = 1;
    } else {
        tmp_0 = -1;
    }

    if ((local_DeadZone != 0.0) && (tmp == tmp_0)) {
        local_IProdOut = 0.0;
    }

    rtDW.Integrator_DSTATE_f += 0.0001 * local_IProdOut;
}

static void QCurrentPI(void)
{
    real_T local_DeadZone;
    real_T local_IProdOut;
    real_T local_Sum;
    int8_T tmp;
    int8_T tmp_0;
    local_IProdOut = rtU.Signal1 - rtDW.Gain;
    local_Sum = local_IProdOut * 0.24527670483636954 + rtDW.Integrator_DSTATE;
    if (local_Sum > 10.0) {
        local_DeadZone = local_Sum - 10.0;
        rtDW.Sum = 10.0;
    } else {
        if (local_Sum >= -10.0) {
            local_DeadZone = 0.0;
        } else {
            local_DeadZone = local_Sum - -10.0;
        }

        if (local_Sum < -10.0) {
            rtDW.Sum = -10.0;
        } else {
            rtDW.Sum = local_Sum;
        }
    }

    local_IProdOut *= 221.54511393115223;
    if (local_DeadZone > 0.0) {
        tmp = 1;
    } else {
        tmp = -1;
    }

    if (local_IProdOut > 0.0) {
        tmp_0 = 1;
    } else {
        tmp_0 = -1;
    }

    if ((local_DeadZone != 0.0) && (tmp == tmp_0)) {
        local_IProdOut = 0.0;
    }

    rtDW.Integrator_DSTATE += 0.0001 * local_IProdOut;
}

static void CurrentLoop(void)
{
    DCurrentPI();
    QCurrentPI();
}

static void InvClark(void)
{
    real_T local_Gain;
    real_T local_Gain1;
    rtDW.u_alpha = rtDW.Gain;
    local_Gain = -0.5 * rtDW.u_alpha;
    local_Gain1 = 0.8660254037844386 * rtDW.Sum;
    rtDW.Sum = local_Gain + local_Gain1;
    rtDW.Sum1 = local_Gain - local_Gain1;
}

static void ei_t(void)
{
    rtDW.Gain = (fmin(fmin(rtDW.u_alpha, rtDW.Sum), rtDW.Sum1) + fmax(fmax
                  (rtDW.u_alpha, rtDW.Sum), rtDW.Sum1)) * -0.5;
}

static void SVPWM2(void)
{
    InvClark();
    ei_t();
    rtDW.Gain1[0] = (-(rtDW.Gain + rtDW.u_alpha) / rtU.Vbus + 0.5) * 4199.0;
    rtDW.Gain1[1] = (-(rtDW.Gain + rtDW.Sum) / rtU.Vbus + 0.5) * 4199.0;
    rtDW.Gain1[2] = (-(rtDW.Gain + rtDW.Sum1) / rtU.Vbus + 0.5) * 4199.0;
}

static void inv_park(void)
{
    rtDW.Gain = rtDW.Saturation * rtDW.u_alpha - rtDW.Sum * rtDW.Sum1;
    rtDW.Sum = rtDW.Sum1 * rtDW.Saturation + rtDW.Sum * rtDW.u_alpha;
}

static void park(real_T param_u_i_alpha, real_T param_u_i_beta, const real_T
                 param_u_sin_cos[2], real_T *param_y_i_d, real_T *param_y_i_q)
{
    *param_y_i_d = param_u_i_alpha * param_u_sin_cos[1];
    *param_y_i_q = param_u_i_beta * param_u_sin_cos[0];
    *param_y_i_d += *param_y_i_q;
    *param_y_i_q = param_u_i_alpha * param_u_sin_cos[0];
    *param_y_i_q = param_u_i_beta * param_u_sin_cos[1] - *param_y_i_q;
}

void FOC_CURRENT_step(void)
{
    ClarkeInput local_BusConversion_InsertedFor;
    real_T local_TmpSignalConversionAtpark[2];
    real_T local_i_alpha_clark;
    real_T local_i_beta_clark;
    rtDW.Sum1 = sin(rtU.theta);
    rtDW.u_alpha = cos(rtU.theta);
    local_TmpSignalConversionAtpark[0] = rtDW.Sum1;
    local_TmpSignalConversionAtpark[1] = rtDW.u_alpha;
    local_BusConversion_InsertedFor.ia = rtU.signal1;
    local_BusConversion_InsertedFor.ib = rtU.signal2;
    local_BusConversion_InsertedFor.ic = rtU.signal3;
    ClarkeTransform(&local_BusConversion_InsertedFor, &local_i_alpha_clark,
                    &local_i_beta_clark);
    park(local_i_alpha_clark, local_i_beta_clark,
         local_TmpSignalConversionAtpark, &rtDW.Sum, &rtDW.Gain);
    CurrentLoop();
    inv_park();
    SVPWM2();
    rtY.tAout = rtDW.Gain1[0];
    rtY.tBout = rtDW.Gain1[1];
    rtY.tCout = rtDW.Gain1[2];
}

void FOC_CURRENT_initialize(void)
{
}
