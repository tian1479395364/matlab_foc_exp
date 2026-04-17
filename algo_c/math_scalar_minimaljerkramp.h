#ifndef MATH_SCALAR_MINIMALJERKRAMP_H
#define MATH_SCALAR_MINIMALJERKRAMP_H

#include <stdbool.h>
#include <assert.h>
#include "math_scalar_base.h"

/**
 * \ingroup MATH
 * \{
 *
 * \file math_scalar_minimaljerkramp.h
 *
 * This file contains a minimal jerk ramp functions for int32_t. They are expected
 * to be called on a regular basis increment or decrement a variable until a target is
 * reached. A given jerk is not exceeded.
 *
 * the idea is to filter a discontinuous target speed in a way that a maximum acceleration
 * and a maximum jerk is not exceeded. the output of the component is that post-processed speed
 * which shall be fed to a speed controller's input.
 *
 * the component's parameter section contains those parameters.
 * from an algorithmic perspective, jerk is defined to be the derivative of acceleration,
 * acceleration the derivative of the speed. by limiting the (absolute) maximum jerk, the maximum
 * change of acceleration is limited (integral of maximum jerk over time), thus the speed change
 * is also limited to integral of integral of maximum jerk over time. as jerk is assumed
 * to be constant maximal in worst case, resulting acceleration change is a(t) = jerk * t,
 * speed change follows to be s(t) = 0.5 * jerk * t^2.
 */

/**
 * \brief Output of the ramp function.
 */
typedef struct MATH_Scalar_MinimalJerkOutputS {
  int16_t s16_Output; /**< Current value of the ramp. */
  bool b_Settled; /**< Ramp has reached its target value */
} MATH_Scalar_MinimalJerkOutputT;

/**
 * \brief Ramp parameters
 *
 * \warning s32_MaxIncrement must be positive
 * \warning s32_MinDecrement must be negative
 */
typedef struct MATH_Scalar_MinimalJerkParameterS {
  int16_t s16_MaximumJerk; /**< maximum allowed modification of the current acceleration to reach target speed */
  int32_t s32_MaximumAcceleration; /**< limit for how much the value should be incremented each call */
  int32_t s32_MinimumAcceleration; /**< limit for how much the value should be incremented each call */
} MATH_Scalar_MinimalJerkParameterT;

/**
 * \brief Internal state of the ramp
 */
typedef struct {
  /** current speed of the state automate, supposed to be in omega */
  int32_t s32_CurrentSpeed;
  /** current acceleration of the state automate, supposed to be in omega per ms */
  int32_t s32_CurrentAcceleration;
} MATH_Scalar_MinimalJerkStateT;

STATIC_INLINE void MATH_Scalar_MinimalJerk_Init(MATH_Scalar_MinimalJerkStateT *aps_State,
                                                int16_t as16_CurrentSpeed,
                                                int32_t as32_CurrentAcceleration);

STATIC_INLINE void MATH_Scalar_MinimalJerk_Update(MATH_Scalar_MinimalJerkStateT *aps_State,
                                                  const MATH_Scalar_MinimalJerkParameterT *aps_Parameter,
                                                  int16_t as16_SetPointSpeed,
                                                  MATH_Scalar_MinimalJerkOutputT *aps_Output);

/**
 * \brief Initializes the ramp with a start value.
 * \param[in,out] aps_State		Internal state of the ramp function
 * \param[in] as16_CurrentSpeed speed level to start with
 * \param[in] as32_CurrentAcceleration acceleration to start with
 */
STATIC_INLINE void MATH_Scalar_MinimalJerk_Init(MATH_Scalar_MinimalJerkStateT *aps_State,
                                                int16_t as16_CurrentSpeed,
                                                int32_t as32_CurrentAcceleration) {
  aps_State->s32_CurrentSpeed        = MATH_s16_Convert_s32(as16_CurrentSpeed);
  aps_State->s32_CurrentAcceleration = as32_CurrentAcceleration;
}

/**
 * \brief Ramp worker function.
 *
 * Computes maximum allowed acceleration and jerk according to concept description.
 * Outputs values where maximum acceleration and jerk is constrained.
 *
 * \warning Must be called in a regular interval for a linear ramp.
 * \warning Maximum acceleration may not exceed 2^30, minimum acceleration may not exceed -2^30
 *
 * \param[in,out] aps_State Internal state of the ramp function
 * \param[in] aps_Parameter Parameter for the ramp function
 * \param[out] aps_Output   Buffer for ramp function output
 * \param[in] as16_SetPointSpeed speed set point the function is targeting (must be in range -16383:16383)
 */
STATIC_INLINE void MATH_Scalar_MinimalJerk_Update(MATH_Scalar_MinimalJerkStateT *aps_State,
                                                  const MATH_Scalar_MinimalJerkParameterT *aps_Parameter,
                                                  int16_t as16_SetPointSpeed,
                                                  MATH_Scalar_MinimalJerkOutputT *aps_Output) {
  int32_t ls32_Difference;
  int32_t ls32_MaximumDifference;
  int16_t ls16_Jerk;
  int32_t ls32_NextAcceleration;
  int32_t ls32_SetPointSpeed;
  int16_t ls16_MaximumJerk;
  int32_t ls32_AbsCurrentAcceleration;

  ls32_SetPointSpeed = MATH_s16_Convert_s32(as16_SetPointSpeed);
  ls16_MaximumJerk   = aps_Parameter->s16_MaximumJerk;
  AXIVION_ASSERT(ls16_MaximumJerk > 0)
  AXIVION_ASSERT(ls32_SetPointSpeed < (16384 * 32768))
  AXIVION_ASSERT(ls32_SetPointSpeed > -(16384 * 32768))
  AXIVION_ASSERT(aps_State->s32_CurrentSpeed < (16384 * 32768))
  AXIVION_ASSERT(aps_State->s32_CurrentSpeed > -(16384 * 32768))
  AXIVION_ASSERT(aps_State->s32_CurrentAcceleration < (16383 * 32768))
  AXIVION_ASSERT(aps_State->s32_CurrentAcceleration > -(16383 * 32768))
  AXIVION_ASSERT(aps_Parameter->s32_MaximumAcceleration < (16384 * 32768))
  AXIVION_ASSERT(aps_Parameter->s32_MinimumAcceleration > -(16384 * 32768))

  ls32_AbsCurrentAcceleration = MATH_s32_Abs(aps_State->s32_CurrentAcceleration);
  ls32_NextAcceleration       = ls32_AbsCurrentAcceleration + (((int32_t) 2) * ls16_MaximumJerk);
  ls32_Difference             = ls32_SetPointSpeed - aps_State->s32_CurrentSpeed;

  if (ls32_NextAcceleration <= INT16_MAX) {
    ls32_MaximumDifference = (ls32_NextAcceleration * ls32_NextAcceleration) / ls16_MaximumJerk;
  } else {
    int64_t ls64_Product = ((int64_t) (ls32_NextAcceleration)) * ((int64_t) ls32_NextAcceleration);
    if (ls64_Product <= (int64_t) INT32_MAX) {
      ls32_MaximumDifference = ((int32_t) ls64_Product) / ls16_MaximumJerk;
    } else {
      /* AXIVION Next Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
      int32_t ls32_Highword = (int32_t) (ls64_Product >> 32);
      if (ls32_Highword < ls16_MaximumJerk) {
        /* the result of the division will be smaller than 32 bit */
        /* AXIVION Next Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
        int32_t ls32_Product                  = (int32_t) (ls64_Product >> 16);
        int32_t ls32_ShiftedMaximumDifference = ls32_Product / ((int32_t) ls16_MaximumJerk);
        AXIVION_ASSERT(ls32_ShiftedMaximumDifference < 32767)
        /* AXIVION Next Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
        ls32_MaximumDifference = (int32_t) (ls32_ShiftedMaximumDifference << 16);
      } else {
        ls32_MaximumDifference = INT32_MAX;
      }
    }
  }
  ls32_MaximumDifference      = MATH_s32_Div2(ls32_MaximumDifference);

  /* Rationale: For 64 bit, the shift operation has been chosen for performance reasons */
  int32_t ls32_AbsDifference = MATH_s32_Abs(ls32_Difference);
  /* AXIVION Next Codeline: MisraC2012-2.2,MisraC2012-14.3: The unit test proves Axivion to be incorrect on the dead condition analysis. */
  if ((MATH_s32_Convert_s16(ls32_AbsDifference) != 0) ||
      (ls32_AbsCurrentAcceleration > ls16_MaximumJerk)) {
    if (ls32_Difference < 0) {
      if (aps_State->s32_CurrentAcceleration > 0) {
        /* we have to get to 0 acceleration and are not limited */
        ls16_Jerk = -ls16_MaximumJerk;
      } else {
        if (ls32_Difference <= -ls32_MaximumDifference) {
          /* we can accelerate up to maximum speed and maximum acceleration */
          /* maximums checked later on */
          ls16_Jerk = -ls16_MaximumJerk;
        } else {
          /* we need to decelerate */
          ls16_Jerk = ls16_MaximumJerk;
        }
      }
    } else {
      if (aps_State->s32_CurrentAcceleration < 0) {
        ls16_Jerk = ls16_MaximumJerk;
      } else {
        if (ls32_Difference >= ls32_MaximumDifference) {
          ls16_Jerk = ls16_MaximumJerk;
        } else {
          ls16_Jerk = -ls16_MaximumJerk;
        }
      }
    }
    aps_Output->b_Settled = false;
  } else {
    aps_State->s32_CurrentSpeed        = ls32_SetPointSpeed;
    aps_State->s32_CurrentAcceleration = 0;
    ls16_Jerk = 0;
    aps_Output->b_Settled = true;
  }

  aps_State->s32_CurrentAcceleration += (int32_t) ls16_Jerk;
  if (aps_State->s32_CurrentAcceleration > aps_Parameter->s32_MaximumAcceleration) {
    aps_State->s32_CurrentAcceleration = aps_Parameter->s32_MaximumAcceleration;
  }
  if (aps_State->s32_CurrentAcceleration < aps_Parameter->s32_MinimumAcceleration) {
    aps_State->s32_CurrentAcceleration = aps_Parameter->s32_MinimumAcceleration;
  }

  /* AXIVION Next Codeline: MisraC2012Directive-4.1: Axivion is incorrect, the asserted boundaries do not allow for an overflow. */
  aps_State->s32_CurrentSpeed += aps_State->s32_CurrentAcceleration;
  aps_Output->s16_Output     = MATH_s32_Convert_s16(aps_State->s32_CurrentSpeed);
}

/** \}
 */
#endif /* MATH_SCALAR_MINIMALJERKRAMP_H */

/* end of file */

