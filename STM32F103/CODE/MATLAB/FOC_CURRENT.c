#include "FOC_CURRENT.h"
#include "FOC_CURRENT_private.h"

DW_FOC_CURRENT_T FOC_CURRENT_DW;
ExtU_FOC_CURRENT_T FOC_CURRENT_U;
ExtY_FOC_CURRENT_T FOC_CURRENT_Y;
static RT_MODEL_FOC_CURRENT_T FOC_CURRENT_M_;
RT_MODEL_FOC_CURRENT_T *const FOC_CURRENT_M = &FOC_CURRENT_M_;
uint32_T plook_u32u16u32n16_even6c_gf(uint16_T u, uint16_T bp0, uint32_T
    maxIndex, uint32_T *fraction)
{
    uint32_T bpIndex;
    uint16_T fbpIndex;
    uint16_T uAdjust;
    uAdjust = (uint16_T)((uint32_T)u - bp0);
    fbpIndex = (uint16_T)((uint32_T)uAdjust >> 6U);
    if (fbpIndex < maxIndex) {
        bpIndex = fbpIndex;
        *fraction = (uint32_T)(uint16_T)(uAdjust & 63) << 10;
    } else {
        bpIndex = maxIndex - 1U;
        *fraction = 65536U;
    }

    return bpIndex;
}

int16_T intrp1d_s16s32s32u32u32n16l_f(uint32_T bpIndex, uint32_T frac, const
    int16_T table[])
{
    int16_T yL_0d0;
    yL_0d0 = table[bpIndex];
    return (int16_T)((int16_T)(((table[bpIndex + 1U] - yL_0d0) * (int32_T)frac) >>
                      16) + yL_0d0);
}

int16_T div_s16s32_floor(int32_T numerator, int32_T denominator)
{
    uint32_T absDenominator;
    uint32_T absNumerator;
    uint32_T tempAbsQuotient;
    int16_T quotient;
    boolean_T quotientNeedsNegation;
    if (denominator == 0) {
        quotient = (int16_T)(numerator >= 0 ? 32767 : -32768);
    } else {
        absNumerator = numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
            numerator;
        absDenominator = denominator < 0 ? ~(uint32_T)denominator + 1U :
            (uint32_T)denominator;
        quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
        tempAbsQuotient = absNumerator / absDenominator;
        if (quotientNeedsNegation) {
            absNumerator %= absDenominator;
            if (absNumerator > 0U) {
                tempAbsQuotient++;
            }
        }

        quotient = (int16_T)(quotientNeedsNegation ? (int32_T)(int16_T)-(int32_T)
                             tempAbsQuotient : (int32_T)(int16_T)tempAbsQuotient);
    }

    return quotient;
}

void FOC_CURRENT_clark(int16_T rtu_i_a, int16_T rtu_i_b, int16_T rtu_i_c,
                       int16_T *rty_i_alpha, int16_T *rty_i_beta)
{
    *rty_i_alpha = (int16_T)((((int16_T)((21845 * rtu_i_a) >> 12) << 1) -
        (int16_T)(((int16_T)((int16_T)(rtu_i_b + rtu_i_c) << 2) * 21845) >> 14))
        >> 2);
    *rty_i_beta = (int16_T)(((int16_T)((int16_T)(rtu_i_b - rtu_i_c) << 1) *
        18919) >> 14);
}

void FOC_CURRENT_step(void)
{
    int32_T rtb_Sum_tmp;
    uint32_T bpIdx;
    uint32_T frac;
    int16_T rtb_IProdOut;
    int16_T rtb_LookUpTable;
    int16_T rtb_LookUpTable_o;
    int16_T rtb_SignPreIntegrator;
    int16_T rtb_SignPreSat;
    int16_T rtb_SignPreSat_h;
    int16_T rtb_Sum1_l;
    int16_T rtb_Sum_d;
    uint16_T rtb_CastU16En16_0;
    uint16_T rtb_QuadHandle1;
    boolean_T rtb_GTEp75;
    boolean_T rtb_LTEp25;
    rtb_QuadHandle1 = (uint16_T)((uint16_T)(((uint32_T)FOC_CURRENT_U.theta << 11)
        / 3217U) << 1);
    rtb_LTEp25 = (rtb_QuadHandle1 <= 16384);
    rtb_GTEp75 = (rtb_QuadHandle1 >= 49152);
    if (rtb_QuadHandle1 <= 32768) {
        if (rtb_LTEp25) {
            rtb_CastU16En16_0 = (uint16_T)(16384 - rtb_QuadHandle1);
        } else {
            rtb_CastU16En16_0 = (uint16_T)(rtb_QuadHandle1 - 16384);
        }
    } else if (rtb_GTEp75) {
        rtb_CastU16En16_0 = (uint16_T)(rtb_QuadHandle1 - 49152);
    } else {
        rtb_CastU16En16_0 = (uint16_T)(49152 - rtb_QuadHandle1);
    }

    bpIdx = plook_u32u16u32n16_even6c_gf(rtb_CastU16En16_0, 0U, 256U, &frac);
    rtb_LookUpTable = intrp1d_s16s32s32u32u32n16l_f(bpIdx, frac,
        FOC_CURRENT_ConstP.pooled3);
    if ((!rtb_LTEp25) && (!rtb_GTEp75)) {
        rtb_LookUpTable = (int16_T)-rtb_LookUpTable;
    }

    FOC_CURRENT_clark(FOC_CURRENT_U.ISensA, FOC_CURRENT_U.ISensB,
                      FOC_CURRENT_U.ISensC, &rtb_IProdOut,
                      &rtb_SignPreIntegrator);
    rtb_LTEp25 = (rtb_QuadHandle1 <= 32768);
    if (!rtb_LTEp25) {
        rtb_QuadHandle1 = (uint16_T)(rtb_QuadHandle1 - 32768);
    }

    if (rtb_QuadHandle1 > 16384) {
        rtb_QuadHandle1 = (uint16_T)(32768 - rtb_QuadHandle1);
    }

    bpIdx = plook_u32u16u32n16_even6c_gf(rtb_QuadHandle1, 0U, 256U, &frac);
    rtb_LookUpTable_o = intrp1d_s16s32s32u32u32n16l_f(bpIdx, frac,
        FOC_CURRENT_ConstP.pooled3);
    if (!rtb_LTEp25) {
        rtb_LookUpTable_o = (int16_T)-rtb_LookUpTable_o;
    }

    rtb_Sum_d = (int16_T)((FOC_CURRENT_U.IRefD << 2) - (int16_T)((int16_T)
                           ((rtb_IProdOut * rtb_LookUpTable) >> 13) + (int16_T)
                           ((rtb_SignPreIntegrator * rtb_LookUpTable_o) >> 13)));
    rtb_SignPreSat = (int16_T)((((rtb_Sum_d * 32149) >> 15) +
        FOC_CURRENT_DW.Integrator_DSTATE) >> 2);
    rtb_Sum1_l = (int16_T)(((FOC_CURRENT_U.IRefQ << 1) - (int16_T)((int16_T)
        ((rtb_SignPreIntegrator * rtb_LookUpTable) >> 14) - (int16_T)
        ((rtb_IProdOut * rtb_LookUpTable_o) >> 14))) >> 1);
    rtb_SignPreSat_h = (int16_T)(((rtb_Sum1_l * 32149) >> 15) +
        FOC_CURRENT_DW.Integrator_DSTATE_e);
    if (rtb_SignPreSat_h > 20480) {
        rtb_IProdOut = 20480;
    } else if (rtb_SignPreSat_h < -20480) {
        rtb_IProdOut = -20480;
    } else {
        rtb_IProdOut = rtb_SignPreSat_h;
    }

    rtb_SignPreIntegrator = (int16_T)(((int16_T)((rtb_SignPreSat *
        rtb_LookUpTable) >> 12) - ((int16_T)((rtb_IProdOut * rtb_LookUpTable_o) >>
        14) << 2)) >> 2);
    rtb_IProdOut = (int16_T)(((int16_T)((((int16_T)((rtb_IProdOut *
        rtb_LookUpTable) >> 14) << 2) + (int16_T)((rtb_LookUpTable_o *
        rtb_SignPreSat) >> 12)) >> 2) * 14189) >> 14);
    rtb_Sum_tmp = rtb_IProdOut << 1;
    rtb_LookUpTable = (int16_T)((rtb_Sum_tmp + (int16_T)-rtb_SignPreIntegrator) >>
        1);
    rtb_LookUpTable_o = (int16_T)(((int16_T)-rtb_SignPreIntegrator - rtb_Sum_tmp)
        >> 1);
    if (rtb_SignPreIntegrator < rtb_LookUpTable) {
        rtb_IProdOut = rtb_SignPreIntegrator;
    } else {
        rtb_IProdOut = rtb_LookUpTable;
    }

    if (rtb_SignPreIntegrator > rtb_LookUpTable) {
        rtb_SignPreSat = rtb_SignPreIntegrator;
    } else {
        rtb_SignPreSat = rtb_LookUpTable;
    }

    if (rtb_IProdOut >= rtb_LookUpTable_o) {
        rtb_IProdOut = rtb_LookUpTable_o;
    }

    if (rtb_SignPreSat <= rtb_LookUpTable_o) {
        rtb_SignPreSat = rtb_LookUpTable_o;
    }

    rtb_IProdOut = (int16_T)-(int16_T)((int16_T)(rtb_IProdOut + rtb_SignPreSat) <<
        1);
    FOC_CURRENT_Y.tAout = (uint16_T)(((div_s16s32_floor((int16_T)-(int16_T)
        (((rtb_SignPreIntegrator << 2) + rtb_IProdOut) >> 2) << 14,
        FOC_CURRENT_U.Vbus) + 32768) * 3199U) >> 16);
    FOC_CURRENT_Y.tBout = (uint16_T)(((div_s16s32_floor((int16_T)-(int16_T)
        (((rtb_LookUpTable << 2) + rtb_IProdOut) >> 2) << 14, FOC_CURRENT_U.Vbus)
        + 32768) * 3199U) >> 16);
    FOC_CURRENT_Y.tCout = (uint16_T)(((div_s16s32_floor((int16_T)-(int16_T)
        (((rtb_LookUpTable_o << 2) + rtb_IProdOut) >> 2) << 14,
        FOC_CURRENT_U.Vbus) + 32768) * 3199U) >> 16);
    if (rtb_SignPreSat_h > 20480) {
        rtb_SignPreSat_h = (int16_T)(rtb_SignPreSat_h - 20480);
    } else if (rtb_SignPreSat_h >= -20480) {
        rtb_SignPreSat_h = 0;
    } else {
        rtb_SignPreSat_h = (int16_T)(rtb_SignPreSat_h - -20480);
    }

    rtb_LTEp25 = (0 != rtb_SignPreSat_h);
    if (rtb_SignPreSat_h < 0) {
        rtb_SignPreSat_h = -1;
    } else {
        rtb_SignPreSat_h = (int16_T)(rtb_SignPreSat_h > 0);
    }

    rtb_IProdOut = (int16_T)((rtb_Sum1_l * 56715) >> 16);
    FOC_CURRENT_DW.Integrator_DSTATE = (int16_T)((((int16_T)((rtb_Sum_d * 56715)
        >> 15) * 6711) >> 17) + FOC_CURRENT_DW.Integrator_DSTATE);
    if (rtb_IProdOut < 0) {
        rtb_SignPreIntegrator = -1;
    } else {
        rtb_SignPreIntegrator = (int16_T)(rtb_IProdOut > 0);
    }

    if (rtb_LTEp25 && (rtb_SignPreSat_h == rtb_SignPreIntegrator)) {
        rtb_IProdOut = 0;
    }

    FOC_CURRENT_DW.Integrator_DSTATE_e = (int16_T)(((6711 * rtb_IProdOut) >> 16)
        + FOC_CURRENT_DW.Integrator_DSTATE_e);
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
