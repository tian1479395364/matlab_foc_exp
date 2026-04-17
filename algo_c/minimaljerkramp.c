#include "minimaljerkramp.h"

MATH_Scalar_MinimalJerkParameterT g_minimal_jerk_param = {
    .s64_MaximumJerk = 10.0,
    .s64_MaximumAcceleration = 10.0,
    .s64_MinimumAcceleration = -10.0,
};

static double MATH_Abs(double x)
{
    return (x >= 0.0) ? x : -x;
}

void MATH_Scalar_MinimalJerk_Init(
    MATH_Scalar_MinimalJerkStateT *aps_State,
    double as64_CurrentSpeed,
    double as64_CurrentAcceleration)
{
    aps_State->s64_CurrentSpeed = as64_CurrentSpeed;
    aps_State->s64_CurrentAcceleration = as64_CurrentAcceleration;
}

void MATH_Scalar_MinimalJerk_Update(
    MATH_Scalar_MinimalJerkStateT *aps_State,
    const MATH_Scalar_MinimalJerkParameterT *aps_Parameter,
    double as64_SetPointSpeed,
    MATH_Scalar_MinimalJerkOutputT *aps_Output)
{
    double ls64_Difference;
    double ls64_MaximumDifference;
    double ls64_Jerk;
    double ls64_NextAcceleration;
    double ls64_SetPointSpeed;
    double ls64_MaximumJerk;
    double ls64_AbsCurrentAcceleration;
    double ls64_AbsDifference;

    ls64_SetPointSpeed = as64_SetPointSpeed;
    aps_Parameter = &g_minimal_jerk_param;
    ls64_MaximumJerk = aps_Parameter->s64_MaximumJerk;

    if (ls64_MaximumJerk <= 0.0) {
        aps_Output->s64_Output = as64_SetPointSpeed;
        aps_Output->b_Settled = 1.0;
        return;
    }

    ls64_AbsCurrentAcceleration = MATH_Abs(aps_State->s64_CurrentAcceleration);
    ls64_NextAcceleration = ls64_AbsCurrentAcceleration + 2.0 * ls64_MaximumJerk;
    ls64_Difference = ls64_SetPointSpeed - aps_State->s64_CurrentSpeed;

    ls64_MaximumDifference = (ls64_NextAcceleration * ls64_NextAcceleration) / ls64_MaximumJerk;
    ls64_MaximumDifference *= 0.5;
    ls64_AbsDifference = MATH_Abs(ls64_Difference);

    if ((ls64_AbsDifference > 0.0) || (ls64_AbsCurrentAcceleration > ls64_MaximumJerk)) {
        if (ls64_Difference < 0.0) {
            if (aps_State->s64_CurrentAcceleration > 0.0) {
                ls64_Jerk = -ls64_MaximumJerk;
            } else if (ls64_Difference <= -ls64_MaximumDifference) {
                ls64_Jerk = -ls64_MaximumJerk;
            } else {
                ls64_Jerk = ls64_MaximumJerk;
            }
        } else if (aps_State->s64_CurrentAcceleration < 0.0) {
            ls64_Jerk = ls64_MaximumJerk;
        } else if (ls64_Difference >= ls64_MaximumDifference) {
            ls64_Jerk = ls64_MaximumJerk;
        } else {
            ls64_Jerk = -ls64_MaximumJerk;
        }

        aps_Output->b_Settled = 0.0;
    } else {
        aps_State->s64_CurrentSpeed = ls64_SetPointSpeed;
        aps_State->s64_CurrentAcceleration = 0.0;
        ls64_Jerk = 0.0;
        aps_Output->b_Settled = 1.0;
    }

    aps_State->s64_CurrentAcceleration += ls64_Jerk;

    if (aps_State->s64_CurrentAcceleration > aps_Parameter->s64_MaximumAcceleration) {
        aps_State->s64_CurrentAcceleration = aps_Parameter->s64_MaximumAcceleration;
    }
    if (aps_State->s64_CurrentAcceleration < aps_Parameter->s64_MinimumAcceleration) {
        aps_State->s64_CurrentAcceleration = aps_Parameter->s64_MinimumAcceleration;
    }

    aps_State->s64_CurrentSpeed += aps_State->s64_CurrentAcceleration;
    aps_Output->s64_Output = aps_State->s64_CurrentSpeed;
}
