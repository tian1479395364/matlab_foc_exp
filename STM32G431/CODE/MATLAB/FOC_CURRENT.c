#include "FOC_CURRENT.h"
#include "FOC_CURRENT_private.h"

DW_FOC_CURRENT_T FOC_CURRENT_DW;
ExtU_FOC_CURRENT_T FOC_CURRENT_U;
ExtY_FOC_CURRENT_T FOC_CURRENT_Y;
static RT_MODEL_FOC_CURRENT_T FOC_CURRENT_M_;
RT_MODEL_FOC_CURRENT_T *const FOC_CURRENT_M = &FOC_CURRENT_M_;
void FOC_CURRENT_clark(real32_T rtu_i_a, real32_T rtu_i_b, real32_T rtu_i_c,
                       real32_T *rty_i_alpha, real32_T *rty_i_beta)
{
    *rty_i_alpha = 0.666666687F * rtu_i_a - (rtu_i_b + rtu_i_c) * 0.333333343F;
    *rty_i_beta = (rtu_i_b - rtu_i_c) * 0.577350259F;
}

void FOC_CURRENT_step(void)
{
    real32_T rtb_IProdOut;
    real32_T rtb_IProdOut_j;
    real32_T rtb_Max;
    real32_T rtb_SignPreIntegrator;
    real32_T rtb_SignPreSat;
    real32_T rtb_SignPreSat_h;
    real32_T rtb_SinCos_o1;
    real32_T rtb_Sum1_f;
    real32_T rtb_Sum_e;
    real32_T rtb_Sum_g;
    boolean_T rtb_NotEqual;
    boolean_T rtb_NotEqual_l;
    rtb_SinCos_o1 = arm_sin_f32(FOC_CURRENT_U.theta);
    rtb_Max = arm_cos_f32(FOC_CURRENT_U.theta);
    FOC_CURRENT_clark(FOC_CURRENT_U.ISensA, FOC_CURRENT_U.ISensB,
                      FOC_CURRENT_U.ISensC, &rtb_SignPreIntegrator, &rtb_Sum_g);
    rtb_IProdOut = 0.0F - (rtb_SignPreIntegrator * rtb_Max + rtb_Sum_g *
                           rtb_SinCos_o1);
    rtb_SignPreSat = rtb_IProdOut * 0.245276704F +
        FOC_CURRENT_DW.Integrator_DSTATE;
    if (rtb_SignPreSat > 10.0F) {
        rtb_Sum_e = 10.0F;
    } else if (rtb_SignPreSat < -10.0F) {
        rtb_Sum_e = -10.0F;
    } else {
        rtb_Sum_e = rtb_SignPreSat;
    }

    rtb_IProdOut_j = FOC_CURRENT_U.IRefQ - (rtb_Sum_g * rtb_Max -
        rtb_SignPreIntegrator * rtb_SinCos_o1);
    rtb_SignPreSat_h = rtb_IProdOut_j * 0.245276704F +
        FOC_CURRENT_DW.Integrator_DSTATE_e;
    if (rtb_SignPreSat_h > 10.0F) {
        rtb_Sum1_f = 10.0F;
        rtb_SignPreSat_h -= 10.0F;
    } else {
        if (rtb_SignPreSat_h < -10.0F) {
            rtb_Sum1_f = -10.0F;
        } else {
            rtb_Sum1_f = rtb_SignPreSat_h;
        }

        if (rtb_SignPreSat_h >= -10.0F) {
            rtb_SignPreSat_h = 0.0F;
        } else {
            rtb_SignPreSat_h -= -10.0F;
        }
    }

    rtb_Sum_g = rtb_Sum_e * rtb_Max - rtb_Sum1_f * rtb_SinCos_o1;
    rtb_SignPreIntegrator = -0.5F * rtb_Sum_g;
    rtb_Sum1_f = (rtb_SinCos_o1 * rtb_Sum_e + rtb_Sum1_f * rtb_Max) *
        0.866025388F;
    rtb_Sum_e = rtb_SignPreIntegrator + rtb_Sum1_f;
    rtb_Sum1_f = rtb_SignPreIntegrator - rtb_Sum1_f;
    rtb_SignPreIntegrator = (fminf(fminf(rtb_Sum_g, rtb_Sum_e), rtb_Sum1_f) +
        fmaxf(fmaxf(rtb_Sum_g, rtb_Sum_e), rtb_Sum1_f)) * -0.5F;
    rtb_NotEqual = (0.0F != rtb_SignPreSat_h);
    if (rtb_SignPreSat_h < 0.0F) {
        rtb_SignPreSat_h = -1.0F;
    } else {
        if (rtb_SignPreSat_h > 0.0F) {
            rtb_SignPreSat_h = 1.0F;
        }
    }

    rtb_IProdOut_j *= 221.54512F;
    if (rtb_SignPreSat > 10.0F) {
        rtb_SignPreSat -= 10.0F;
    } else if (rtb_SignPreSat >= -10.0F) {
        rtb_SignPreSat = 0.0F;
    } else {
        rtb_SignPreSat -= -10.0F;
    }

    rtb_NotEqual_l = (0.0F != rtb_SignPreSat);
    if (rtb_SignPreSat < 0.0F) {
        rtb_SignPreSat = -1.0F;
    } else {
        if (rtb_SignPreSat > 0.0F) {
            rtb_SignPreSat = 1.0F;
        }
    }

    rtb_IProdOut *= 221.54512F;
    rtb_SinCos_o1 = fmodf(rtb_SignPreSat, 256.0F);
    if (rtb_IProdOut < 0.0F) {
        rtb_Max = -1.0F;
    } else if (rtb_IProdOut > 0.0F) {
        rtb_Max = 1.0F;
    } else {
        rtb_Max = rtb_IProdOut;
    }

    rtb_Max = fmodf(rtb_Max, 256.0F);
    if (rtb_NotEqual_l && ((rtb_SinCos_o1 < 0.0F ? (int32_T)(int8_T)-(int8_T)
                            (uint8_T)-rtb_SinCos_o1 : (int32_T)(int8_T)(uint8_T)
                            rtb_SinCos_o1) == (rtb_Max < 0.0F ? (int32_T)(int8_T)
            -(int8_T)(uint8_T)-rtb_Max : (int32_T)(int8_T)(uint8_T)rtb_Max))) {
        rtb_IProdOut = 0.0F;
    }

    FOC_CURRENT_DW.Integrator_DSTATE += 0.0001F * rtb_IProdOut;
    rtb_SinCos_o1 = fmodf(rtb_SignPreSat_h, 256.0F);
    if (rtb_IProdOut_j < 0.0F) {
        rtb_IProdOut = -1.0F;
    } else if (rtb_IProdOut_j > 0.0F) {
        rtb_IProdOut = 1.0F;
    } else {
        rtb_IProdOut = rtb_IProdOut_j;
    }

    rtb_Max = fmodf(rtb_IProdOut, 256.0F);
    if (rtb_NotEqual && ((rtb_SinCos_o1 < 0.0F ? (int32_T)(int8_T)-(int8_T)
                          (uint8_T)-rtb_SinCos_o1 : (int32_T)(int8_T)(uint8_T)
                          rtb_SinCos_o1) == (rtb_Max < 0.0F ? (int32_T)(int8_T)
            -(int8_T)(uint8_T)-rtb_Max : (int32_T)(int8_T)(uint8_T)rtb_Max))) {
        rtb_IProdOut_j = 0.0F;
    }

    FOC_CURRENT_DW.Integrator_DSTATE_e += 0.0001F * rtb_IProdOut_j;
    FOC_CURRENT_Y.tAout = (-(rtb_SignPreIntegrator + rtb_Sum_g) /
                           FOC_CURRENT_U.Vbus + 0.5F) * 4199.0F;
    FOC_CURRENT_Y.tBout = (-(rtb_SignPreIntegrator + rtb_Sum_e) /
                           FOC_CURRENT_U.Vbus + 0.5F) * 4199.0F;
    FOC_CURRENT_Y.tCout = (-(rtb_SignPreIntegrator + rtb_Sum1_f) /
                           FOC_CURRENT_U.Vbus + 0.5F) * 4199.0F;
}

void FOC_CURRENT_initialize(void)
{
    rtmSetErrorStatus(FOC_CURRENT_M, (NULL));
    (void) memset((void *)&FOC_CURRENT_DW, 0,
                  sizeof(DW_FOC_CURRENT_T));
}

void FOC_CURRENT_terminate(void)
{
}
