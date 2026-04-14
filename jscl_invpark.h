#ifndef JSCL_INVPARK_H
#define JSCL_INVPARK_H
/*
typedef struct {
    double sin;     // sin(θ)
    double cos;     // cos(θ)
} SinCosInput;
*/
#include "jscl_park.h"

void InverseParkTransform(double u_d,
                          double u_q,
                          const SinCosInput *sin_cos,
                          double *u_alpha,
                          double *u_beta);

#endif