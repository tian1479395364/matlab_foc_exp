#include "jscl_invpark.h"

void InverseParkTransform(double u_d,
                          double u_q,
                          const SinCosInput *sin_cos,
                          double *u_alpha,
                          double *u_beta)
{
    double f64_u_alpha;
    double f64_u_beta;

    /* Inverse Park Transform */
    f64_u_alpha = u_d * sin_cos->m_cos - u_q * sin_cos->m_sin;
    f64_u_beta  = u_d * sin_cos->m_sin + u_q * sin_cos->m_cos;

    *u_alpha = f64_u_alpha;
    *u_beta  = f64_u_beta;
}