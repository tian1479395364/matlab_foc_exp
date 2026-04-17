#ifndef MATH_SCALAR_MINIMALJERKRAMP_H
#define MATH_SCALAR_MINIMALJERKRAMP_H

#include "rtwtypes.h"

typedef struct {
    double s64_MaximumJerk;
    double s64_MaximumAcceleration;
    double s64_MinimumAcceleration;
} MATH_Scalar_MinimalJerkParameterT;

typedef struct {
    double s64_CurrentSpeed;
    double s64_CurrentAcceleration;
} MATH_Scalar_MinimalJerkStateT;

typedef struct {
    double s64_Output;
    double b_Settled;
} MATH_Scalar_MinimalJerkOutputT;

extern MATH_Scalar_MinimalJerkParameterT g_minimal_jerk_param;

void MATH_Scalar_MinimalJerk_Init(
    MATH_Scalar_MinimalJerkStateT *aps_State,
    double as64_CurrentSpeed,
    double as64_CurrentAcceleration);

void MATH_Scalar_MinimalJerk_Update(
    MATH_Scalar_MinimalJerkStateT *aps_State,
    const MATH_Scalar_MinimalJerkParameterT *aps_Parameter,
    double as64_SetPointSpeed,
    MATH_Scalar_MinimalJerkOutputT *aps_Output);

#endif
