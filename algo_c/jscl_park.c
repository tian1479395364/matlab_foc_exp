#include "jscl_park.h"

void ParkTransform(double i_alpha,
                   double i_beta,
                   const SinCosInput *sin_cos,
                   double *i_d,
                   double *i_q)
{
    double f64_i_d;
    double f64_i_q;

    /* Park Transform */
    f64_i_d = i_alpha * sin_cos->m_cos + i_beta * sin_cos->m_sin;

    f64_i_q = -i_alpha * sin_cos->m_sin + i_beta * sin_cos->m_cos;

    *i_d = f64_i_d;
    *i_q = f64_i_q;
}