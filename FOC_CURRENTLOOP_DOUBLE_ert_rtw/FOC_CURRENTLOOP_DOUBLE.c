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

g_ty_DW g_l5;
static g_ty_RT_MODEL g_j_;
g_ty_RT_MODEL *const g_j = &g_j_;
extern real_T rt_modd(real_T u0, real_T u1);
static void t_p(void);
static void rate_scheduler(void);
static void rate_scheduler(void)
{
    (g_j->Timing.TaskCounters.TID[1])++;
    if ((g_j->Timing.TaskCounters.TID[1]) > 1) {
        g_j->Timing.TaskCounters.TID[1] = 0;
    }
}

static void t_p(void)
{
    VectorUVW_T local_;
    real_T local_bw;
    real_T local_gb_idx_0;
    real_T local_gb_idx_1;
    InverseClarkeTransform(&g_l5.g_f_j, &local_);
    CalcZeroSequenceVoltage(&local_, &local_bw);
    local_gb_idx_0 = local_bw + local_.s64_u;
    local_gb_idx_1 = local_bw + local_.s64_v;
    local_bw += local_.s64_w;
    g_l5.g_f_bz[0] = (-local_gb_idx_0 / g_l5.g_f_k + 0.5) * 4199.0;
    g_l5.g_f_bz[1] = (-local_gb_idx_1 / g_l5.g_f_k + 0.5) * 4199.0;
    g_l5.g_f_bz[2] = (-local_bw / g_l5.g_f_k + 0.5) * 4199.0;
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
    real_T local_l;
    VectorAB_T local_py;
    VectorDQ_T local_o;
    VectorUVW_T local_j;
    real_T local_gr2[2];
    real_T local_;
    real_T local_d;
    real_T local_d5;
    real_T local_ef;
    real_T local_h0e;
    real_T local_jc_idx_0;
    real_T local_jc_idx_1;
    real_T local_jc_idx_2;
    real_T local_jx;
    real_T local_k4r;
    real_T local_kne;
    real_T local_ko;
    real_T local_nr;
    real_T local_ox;
    real_T local_p5;
    real_T local_pg;
    if (g_j->Timing.TaskCounters.TID[1] == 0) {
        g_l5.g_f_i = g_l5.g_f_h;
        g_l5.g_f_b = g_l5.g_f_cb;
        g_l5.g_f_bl = g_l5.g_f_k_c;
    }

    local_jc_idx_0 = -(0.00023815194093831864 * g_l5.g_f_i - 0.5) + 0.5;
    if (local_jc_idx_0 > 1.0) {
        local_jc_idx_0 = 1.0;
    } else if (local_jc_idx_0 < 0.0) {
        local_jc_idx_0 = 0.0;
    }

    local_jc_idx_1 = -(0.00023815194093831864 * g_l5.g_f_b - 0.5) + 0.5;
    if (local_jc_idx_1 > 1.0) {
        local_jc_idx_1 = 1.0;
    } else if (local_jc_idx_1 < 0.0) {
        local_jc_idx_1 = 0.0;
    }

    local_jc_idx_2 = -(0.00023815194093831864 * g_l5.g_f_bl - 0.5) + 0.5;
    if (local_jc_idx_2 > 1.0) {
        local_jc_idx_2 = 1.0;
    } else if (local_jc_idx_2 < 0.0) {
        local_jc_idx_2 = 0.0;
    }

    local_ = ((local_jc_idx_1 + local_jc_idx_2) + local_jc_idx_0) *
        0.33333333333333331;
    local_jc_idx_0 = (local_jc_idx_0 - local_) * 24.0;
    local_jc_idx_1 = (local_jc_idx_1 - local_) * 24.0;
    local_jc_idx_2 = (local_jc_idx_2 - local_) * 24.0;
    if (g_l5.g_f_lw != 0) {
        g_l5.g_f_p = 0.0;
        if (g_l5.g_f_p > 1.0E+7) {
            g_l5.g_f_p = 1.0E+7;
        } else if (g_l5.g_f_p < -1.0E+7) {
            g_l5.g_f_p = -1.0E+7;
        }
    }

    local_p5 = g_l5.g_f_p * 0.1763 / 0.000195185;
    if (g_l5.g_f_c >= -3.1415926535897931) {
        if (g_l5.g_f_c <= 3.1415926535897931) {
            local_pg = g_l5.g_f_c;
        } else {
            local_pg = g_l5.g_f_c - 6.2831854820251465;
        }
    } else {
        local_pg = g_l5.g_f_c + 6.2831854820251465;
    }

    local_ox = 5.0 * local_pg;
    local_ef = sin(local_ox);
    local_ = cos(local_ox);
    local_jc_idx_0 = (0.66666666666666663 * local_jc_idx_0 +
                      -0.33333333333333331 * local_jc_idx_1) +
        -0.33333333333333331 * local_jc_idx_2;
    local_ox = 0.57735026918962573 * local_jc_idx_1 + -0.57735026918962573 *
        local_jc_idx_2;
    local_jc_idx_1 = (local_ox * local_ - local_jc_idx_0 * local_ef) /
        0.000195185;
    if (g_l5.g_f_o != 0) {
        g_l5.g_f_l = 0.0;
        if (g_l5.g_f_l > 1.0E+7) {
            g_l5.g_f_l = 1.0E+7;
        } else if (g_l5.g_f_l < -1.0E+7) {
            g_l5.g_f_l = -1.0E+7;
        }
    }

    local_jc_idx_2 = 5.0 * g_l5.g_f_i_m;
    local_d5 = g_l5.g_f_l * local_jc_idx_2 * 0.000195185 / 0.000195185;
    local_jx = local_jc_idx_2 * 0.0109 / 0.000195185;
    local_ko = local_jc_idx_2 * g_l5.g_f_p * 0.000195185 / 0.000195185;
    local_jc_idx_0 = (local_jc_idx_0 * local_ + local_ox * local_ef) /
        0.000195185;
    local_kne = g_l5.g_f_l * 0.1763 / 0.000195185;
    local_h0e = ((0.0109 * g_l5.g_f_p * 7.5 - 0.05 * g_l5.g_f_i_m) -
                 g_l5.g_f_i_m * 0.000159) / 0.00058;
    local_nr = 5.0E-5 * g_l5.g_f_i_m + local_pg;
    local_jc_idx_2 = g_l5.g_f_l * local_ - g_l5.g_f_p * local_ef;
    local_ox = g_l5.g_f_l * local_ef + g_l5.g_f_p * local_;
    local_pg = rt_modd(5.0 * local_pg, 6.2831853071795862);
    if (g_j->Timing.TaskCounters.TID[1] == 0) {
        g_l5.g_f_k = 24.0;

        {
            real_T *pDataValues = (real_T *) g_l5.g_f_e2.DataPtr;
            real_T *pTimeValues = (real_T *) g_l5.g_f_e2.TimePtr;
            int_T currTimeIndex = g_l5.g_f_em.PrevIndex;
            real_T t = ((g_j->Timing.clockTick1) * 0.0001);
            if (t > pTimeValues[6]) {
                local_l = 0.0;
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

                g_l5.g_f_em.PrevIndex = currTimeIndex;

                {
                    real_T t1 = pTimeValues[currTimeIndex];
                    real_T t2 = pTimeValues[currTimeIndex + 1];
                    if (t1 == t2) {
                        if (t < t1) {
                            local_l = pDataValues[currTimeIndex];
                        } else {
                            local_l = pDataValues[currTimeIndex + 1];
                        }
                    } else {
                        real_T f1 = (t2 - t) / (t2 - t1);
                        real_T f2 = 1.0 - f1;
                        real_T d1;
                        real_T d2;
                        int_T TimeIndex = currTimeIndex;
                        d1 = pDataValues[TimeIndex];
                        d2 = pDataValues[TimeIndex + 1];
                        local_l = (real_T) rtInterpolate(d1, d2, f1, f2);
                        pDataValues += 7;
                    }
                }
            }
        }

        local_gr2[0] = sin(local_pg);
        local_gr2[1] = cos(local_pg);
        if (local_jc_idx_2 > 50.0) {
            local_j.s64_u = 50.0;
        } else if (local_jc_idx_2 < -50.0) {
            local_j.s64_u = -50.0;
        } else {
            local_j.s64_u = local_jc_idx_2;
        }

        local_ = -0.5 * local_jc_idx_2 + 0.8660254037844386 * local_ox;
        if (local_ > 50.0) {
            local_j.s64_v = 50.0;
        } else if (local_ < -50.0) {
            local_j.s64_v = -50.0;
        } else {
            local_j.s64_v = local_;
        }

        local_ = -0.5 * local_jc_idx_2 + -0.8660254037844386 * local_ox;
        if (local_ > 50.0) {
            local_j.s64_w = 50.0;
        } else if (local_ < -50.0) {
            local_j.s64_w = -50.0;
        } else {
            local_j.s64_w = local_;
        }

        ClarkeTransform(&local_j, &local_py);
        ParkTransform(&local_py, &local_gr2[0], &local_o);
        CurrentLoopDQ(0.0, local_o.s64_d, local_l, local_o.s64_q,
                      0.24527670483636954, 221.54511393115223,
                      0.24527670483636954, 221.54511393115223, &local_d,
                      &local_k4r);
        local_o.s64_d = local_d;
        local_o.s64_q = local_k4r;
        InverseParkTransform(&local_o, &local_gr2[0], &g_l5.g_f_j);
        t_p();
        g_l5.g_f_h = g_l5.g_f_bz[0];
        g_l5.g_f_cb = g_l5.g_f_bz[1];
        g_l5.g_f_k_c = g_l5.g_f_bz[2];
    }

    g_l5.g_f_lw = 0U;
    g_l5.g_f_p += (((local_jc_idx_1 - local_d5) - local_jx) - local_p5) * 5.0E-5;
    if (g_l5.g_f_p > 1.0E+7) {
        g_l5.g_f_p = 1.0E+7;
    } else if (g_l5.g_f_p < -1.0E+7) {
        g_l5.g_f_p = -1.0E+7;
    }

    g_l5.g_f_c = local_nr;
    g_l5.g_f_o = 0U;
    g_l5.g_f_l += ((local_jc_idx_0 + local_ko) - local_kne) * 5.0E-5;
    if (g_l5.g_f_l > 1.0E+7) {
        g_l5.g_f_l = 1.0E+7;
    } else if (g_l5.g_f_l < -1.0E+7) {
        g_l5.g_f_l = -1.0E+7;
    }

    g_l5.g_f_i_m += 5.0E-5 * local_h0e;
    if (g_l5.g_f_i_m > 1.0E+7) {
        g_l5.g_f_i_m = 1.0E+7;
    } else if (g_l5.g_f_i_m < -1.0E+7) {
        g_l5.g_f_i_m = -1.0E+7;
    }

    if (g_j->Timing.TaskCounters.TID[1] == 0) {
        g_j->Timing.clockTick1++;
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

        g_l5.g_f_e2.TimePtr = (void *) pTimeValues0;
        g_l5.g_f_e2.DataPtr = (void *) pDataValues0;
        g_l5.g_f_em.PrevIndex = 0;
    }

    g_l5.g_f_lw = 1U;
    g_l5.g_f_o = 1U;
}
