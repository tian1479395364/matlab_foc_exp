#ifndef JSCL_PARK_H
#define JSCL_PARK_H

typedef struct {
    double m_sin;     // sin(θ)
    double m_cos;     // cos(θ)
} SinCosInput;

void ParkTransform(double i_alpha,
                   double i_beta,
                   const SinCosInput *sin_cos,
                   double *i_d,
                   double *i_q);

#endif