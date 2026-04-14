#include "jscl_transform.h"
#include <math.h>

/* ====================== Clarke Transform ====================== */
void ClarkeTransform(const VectorUVW_T *ABC_in, VectorAB_T *AB_out)
{
    AB_out->s64_alpha = 0.6666666666666666 * ABC_in->s64_u 
                      - 0.3333333333333333 * (ABC_in->s64_v + ABC_in->s64_w);

    AB_out->s64_beta  = 0.5773502691896257 * (ABC_in->s64_v - ABC_in->s64_w);
}

/* ====================== Park Transform ====================== */
void ParkTransform(const VectorAB_T *AB_in, const double sin_cos[2], VectorDQ_T *DQ_out)
{
    double cos_theta = sin_cos[1];//cose
    double sin_theta = sin_cos[0];//sine

    DQ_out->s64_d =  AB_in->s64_alpha * cos_theta + AB_in->s64_beta * sin_theta;
    DQ_out->s64_q = -AB_in->s64_alpha * sin_theta + AB_in->s64_beta * cos_theta;
}

/* ====================== Inverse Park Transform ====================== */
void InverseParkTransform(const VectorDQ_T *in, const double sin_cos[2], VectorAB_T *out)
{
    double cos_theta = sin_cos[1];//cose
    double sin_theta = sin_cos[0];//sine

    out->s64_alpha = in->s64_d * cos_theta - in->s64_q * sin_theta;
    out->s64_beta  = in->s64_d * sin_theta + in->s64_q * cos_theta;
}

/* ====================== Inverse Clarke Transform ====================== */
void InverseClarkeTransform(const VectorAB_T *in, VectorUVW_T *out)
{
    out->s64_u = in->s64_alpha;
    out->s64_v = -0.5 * in->s64_alpha + 0.8660254037844386 * in->s64_beta;
    out->s64_w = -0.5 * in->s64_alpha - 0.8660254037844386 * in->s64_beta;
}


void CalcZeroSequenceVoltage(const VectorUVW_T *u_abc, 
                             double *u_zero)
{
    double max_val;
    double min_val;

    /* 找出三相中的最大值和最小值 */
    max_val = u_abc->s64_u;
    min_val = u_abc->s64_u;

    if (u_abc->s64_v > max_val) max_val = u_abc->s64_v;
    if (u_abc->s64_v < min_val) min_val = u_abc->s64_v;

    if (u_abc->s64_w > max_val) max_val = u_abc->s64_w;
    if (u_abc->s64_w < min_val) min_val = u_abc->s64_w;

    /* 根据公式计算零序电压 */
    /* e(t) = -1/2 * (u_max + u_min) */
    *u_zero = -0.5 * (max_val + min_val);
}