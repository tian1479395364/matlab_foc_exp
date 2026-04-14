#include "FOC_CURRENT.h"
#include "jscl_transform.h"
#include "rtwtypes.h"
#include <math.h>

g_ty_DW g_l5;
g_ty_ExtU g_m;
g_ty_ExtY g_ho;
static void t_p(void);
static void t_p(void)
{
    VectorUVW_T local_;
    real_T local_bw;
    real_T local_gb_idx_0;
    real_T local_gb_idx_1;
    InverseClarkeTransform(&g_l5.g_f_p, &local_);
    CalcZeroSequenceVoltage(&local_, &local_bw);
    local_gb_idx_0 = local_bw + local_.s64_u;
    local_gb_idx_1 = local_bw + local_.s64_v;
    local_bw += local_.s64_w;
    g_l5.g_f_b[0] = (-local_gb_idx_0 / g_m.g_f_m + 0.5) * 4199.0;
    g_l5.g_f_b[1] = (-local_gb_idx_1 / g_m.g_f_m + 0.5) * 4199.0;
    g_l5.g_f_b[2] = (-local_bw / g_m.g_f_m + 0.5) * 4199.0;
}

void FOC_CURRENT_step(void)
{
    VectorAB_T local_gy;
    VectorDQ_T local_b;
    VectorDQ_T local_e;
    VectorUVW_T local_l;
    real_T local_[2];
    local_[0] = sin(g_m.g_f_e);
    local_[1] = cos(g_m.g_f_e);
    local_l.s64_u = g_m.g_f_a;
    local_l.s64_v = g_m.g_f_o;
    local_l.s64_w = g_m.g_f_hk;
    ClarkeTransform(&local_l, &local_gy);
    ParkTransform(&local_gy, &local_[0], &local_e);
    CurrentLoopDQ(g_m.g_f_j, local_e.s64_d, g_m.g_f_h, local_e.s64_q,
                  0.24527670483636954, 221.54511393115223, 0.24527670483636954,
                  221.54511393115223, &local_b);
    InverseParkTransform(&local_b, &local_[0], &g_l5.g_f_p);
    t_p();
    g_ho.g_f_f = g_l5.g_f_b[0];
    g_ho.g_f_i = g_l5.g_f_b[1];
    g_ho.g_f_h = g_l5.g_f_b[2];
}

void FOC_CURRENT_initialize(void)
{
}
