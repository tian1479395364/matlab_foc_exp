#ifndef MATH_SCALAR_BASE_H
#define MATH_SCALAR_BASE_H

/**
 * \defgroup MATH Math functions for all CPUs
 * \brief Basic math operations using ANSI-C and no specific HW-extensions
 */

#include <stdint.h>
#include "math_sin.h"
#include "compiler.h"

/**
 * \ingroup MATH
 * \{
 *
 * \file math_scalar_base.h
 *
 * \brief This file provides general purpose fixed precision math functions.
 *
 * int16_t numbers use a Q1.15 semantics to map to floats: [-32767:32767] -> [-1:1]
 * int32_t numbers use a Q1.31 or a Q17.15 semantics to map to floats:
 *     [-2^31:2^31] -> [-1:1]          (Q1.31)
 *     [-2^31:2^31] -> [-65535:65535] (Q17.15)
 *
 * Compile-time conversion from float to int is provided by the macros Q1_15, Q17_15 and Q1_31.
 *
 * Thus, e.g. when multiplying 0.5 * 0.5 = 0.25, the int16_t domain calculates
 *      MATH_s16_Mul( Q1_15(0.5), Q1_15(0.5) ) = Q1_15(0.25)
 *      MATH_s16_Mul( 16383     ,      16383 ) = 8191
 *
 */

#ifdef QAC
/* PRQA S 3219 ++ */
/* PRQA S 3453 ++ */
/* Rationale: The macros are used for initialization of const structures, functions cannot be used here */

#pragma PRQA_NO_SIDE_EFFECTS MATH_s32_Abs
#pragma PRQA_NO_SIDE_EFFECTS MATH_s16_Abs
#pragma PRQA_NO_SIDE_EFFECTS MATH_s32_Limit
#pragma PRQA_NO_SIDE_EFFECTS MATH_s64_Limit
#pragma PRQA_NO_SIDE_EFFECTS MATH_s16_Sin
#pragma PRQA_NO_SIDE_EFFECTS MATH_s16_Cos
#pragma PRQA_NO_SIDE_EFFECTS MATH_s16_Convert_s32
#pragma PRQA_NO_SIDE_EFFECTS MATH_s32_Convert_s16
#pragma PRQA_NO_SIDE_EFFECTS MATH_s32_Round
#pragma PRQA_NO_SIDE_EFFECTS MATH_s32_RoundStatefull
#pragma PRQA_NO_SIDE_EFFECTS MATH_s32_DivByQ1_15
#pragma PRQA_NO_SIDE_EFFECTS MATH_s16_Div
#pragma PRQA_NO_SIDE_EFFECTS MATH_s16_Mul
#pragma PRQA_NO_SIDE_EFFECTS MATH_s32_Mul16
#pragma PRQA_NO_SIDE_EFFECTS MATH_s16_Div2
#pragma PRQA_NO_SIDE_EFFECTS MATH_s32_Div2
#pragma PRQA_NO_SIDE_EFFECTS MATH_s16_Div4
#pragma PRQA_NO_SIDE_EFFECTS MATH_s16_Sign
#pragma PRQA_NO_SIDE_EFFECTS MATH_s32_Sign
#pragma PRQA_NO_SIDE_EFFECTS MATH_Q1_31_Q17_15_Mul
#pragma PRQA_NO_SIDE_EFFECTS MATH_s16_Max
#pragma PRQA_NO_SIDE_EFFECTS MATH_s16_Min
#pragma PRQA_NO_SIDE_EFFECTS MATH_s32_Min
#pragma PRQA_NO_SIDE_EFFECTS MATH_s32_Max
#pragma PRQA_NO_SIDE_EFFECTS MATH_s16_Min3
#pragma PRQA_NO_SIDE_EFFECTS MATH_u16_Min
#pragma PRQA_NO_SIDE_EFFECTS MATH_u32_Sqrt
#endif

/** \brief MISRA-compliant type definition for double */
/* AXIVION Next Line : MisraC2012Directive-4.6: The type is not used in the runtime, but only at compile time to compute constants */
typedef double double64_T;
/** \brief MISRA-compliant type definition for float */
/* AXIVION Next Line : MisraC2012Directive-4.6: The type is not used in the runtime, but only at compile time to compute constants */
typedef float  float32_T;

/**
 * maximum ranges for fractional fixed precision integers in integers
 */
/** \brief two power 15 -1, maximum number symmetrically displayable in 15 bits */
#define Q1_15_MAX  32767
/** \brief two power 15, base for Q17.15 */
#define Q17_15_ONE 32768
/** \brief two power 31 -1, maximum number symmetrically displayable in 31 bits */
#define Q1_31_MAX  2147483647
/** \brief two power 16 -1, maximum number displayable in 16 bits */
#define UQ1_15_MAX 65535

/**
 * maximum ranges for fractional fixed precision integers in float
 */
/** \brief double representation of Q1_15_MAX */
#define Q1_15_MAX_F  ((double64_T)Q1_15_MAX)
/** \brief double representation of Q17_15_ONE */
#define Q17_15_ONE_F ((double64_T)Q17_15_ONE)
/** \brief double representation of Q1_31_MAX */
#define Q1_31_MAX_F  ((double64_T)Q1_31_MAX)
/** \brief double representation of UQ1_15_MAX */
#define UQ1_15_MAX_F  ((double64_T)UQ1_15_MAX)

/**
 * mathematical constants used in trigonometric functions
 */
/** \brief macro for 1/sqrt(3) */
#define ONE_OVER_SQRT3 0.57735026918962576451
/** \brief macro for sqrt(3)/2 */
#define SQRT3_OVER_TWO 0.86602540378443864676
/** \brief macro for sqrt(3) */
#define SQRT3          1.73205080756887729352
/** \brief macro for sqrt(2) */
#define SQRT2          1.4142135623730951
/** \brief macro for 1/3 */
#define ONE_OVER_THREE 0.33333333333333333333
/** \brief macro for PI */
#define CONSTANT_PI    3.14159265358979323846
/** \brief macro for 1/PI */
#define ONE_OVER_PI    0.318309886183790671537767526745028724

/**
 * conversion macros for converting floats to fixed precision integers
 *
 * \warning these macros do not do boundary checks. Overflow may occur.
 */
/** \brief construct a Q1.15 from a double ]-1;1[. the macro is not boundary checked. */
#define Q1_15_unchecked(x)  (((double64_T)(x)) * Q1_15_MAX_F )
/** \brief construct a Q17.15 from a double ]-65535;65535[. the macro is not boundary checked. */
#define Q17_15_unchecked(x) (((double64_T)(x)) * Q17_15_ONE_F)
/** \brief construct a Q1.31 from a double ]-1;1[. the macro is not boundary checked. */
#define Q1_31_unchecked(x)  (((double64_T)(x)) * Q1_31_MAX_F )

/**
 * conversion macros for converting floats to fixed precision integers
 *
 * These macros do overflow checking and saturate in case of overflow.
 */
/** \brief construct a Q1.15 from a double ]-1;1[. the macro is boundary checked and crops the input silently.  */
#define Q1_15(x)  ((int16_t)((Q1_15_unchecked(x)  > Q1_15_MAX_F) ?  Q1_15_MAX_F : ((Q1_15_unchecked(x)  < (-Q1_15_MAX_F)) ? (-Q1_15_MAX_F) : (Q1_15_unchecked(x) ))))
/** \brief construct a Q1.31 from a double ]-1;1[. the macro is boundary checked and crops the input silently. */
#define Q1_31(x)  ((int32_t)((Q1_31_unchecked(x)  > Q1_31_MAX_F) ?  Q1_31_MAX_F : ((Q1_31_unchecked(x)  < (-Q1_31_MAX_F)) ? (-Q1_31_MAX_F) : (Q1_31_unchecked(x) ))))
/** \brief construct a Q17.15 from a double ]-65535;65535[. the macro is boundary checked and crops the input silently. */
#define Q17_15(x) ((int32_t)((Q17_15_unchecked(x) > Q1_31_MAX_F) ?  Q1_31_MAX_F : ((Q17_15_unchecked(x) < (-Q1_31_MAX_F)) ? (-Q1_31_MAX_F) : (Q17_15_unchecked(x)))))
/** \brief construct a UQ1.15 (unsigned) from a double ]0;2[. the macro is boundary checked and crops the input silently. */
#define UQ1_15(x)  ((uint16_t)((Q1_15_unchecked(x)  > UQ1_15_MAX_F) ?  UQ1_15_MAX_F : ((Q1_15_unchecked(x)  < (0.0)) ? (0.0) : (Q1_15_unchecked(x) ))))

/** \brief convert a Q1.15 to Q1.31 */
/* AXIVION Next Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
#define MATH_s16_CONVERT_s32(x)      ((int32_t)(x) << 16)
/** \brief convert a Q1.15 to Q1.63 */
/* AXIVION Next Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
#define MATH_s16_CONVERT_s64(x)      ((int64_t)(x) << 16)

/** \brief absolute value of an integer, type independent because of type less macro syntax
 * does not create a function call / no impact on calls metric */
#define MATH_ABS(x) (((x) < (0)) ? -(x): (x))

STATIC_INLINE int32_t MATH_s32_Abs(int32_t as32_In);
STATIC_INLINE int16_t MATH_s16_Abs(int16_t as16_In);
STATIC_INLINE int32_t MATH_s32_Limit(int32_t as32_In, int32_t as32_LowerLimit, int32_t as32_UpperLimit);
STATIC_INLINE int64_t MATH_s64_Limit(int64_t as64_X, int64_t as64_LowerLimit, int64_t as64_UpperLimit);
STATIC_INLINE int16_t MATH_s16_Sin(int16_t as16_Angle);
STATIC_INLINE int16_t MATH_s16_Cos(int16_t as16_Angle);
STATIC_INLINE int32_t MATH_s16_Convert_s32(int16_t as16_In);
STATIC_INLINE int16_t MATH_s32_Convert_s16(int32_t as32_In);
STATIC_INLINE int32_t MATH_s48_Convert_s32(int64_t as64_In);
STATIC_INLINE int16_t MATH_s32_Round(int32_t as32_In);
STATIC_INLINE int16_t MATH_s32_RoundStatefull(int32_t as32_In, int32_t *aps32_Error);
STATIC_INLINE int16_t MATH_s32_DivByQ1_15(int32_t as32_In, int16_t as16_Divisor);
STATIC_INLINE int16_t MATH_s16_Div(int16_t as16_X, int16_t as16_Y);
STATIC_INLINE int16_t MATH_s16_Mul(int16_t as16_X, int16_t as16_Y);
STATIC_INLINE int32_t MATH_s32_Mul16(int16_t as16_X, int16_t as16_Y);
STATIC_INLINE int16_t MATH_s16_Difference(int16_t as16_X, int16_t as16_Y);
STATIC_INLINE int16_t MATH_s16_Div2(int16_t as16_X);
STATIC_INLINE int32_t MATH_s32_Div2(int32_t as32_X);
STATIC_INLINE int16_t MATH_s16_Div4(int16_t as16_X);
STATIC_INLINE int16_t MATH_s16_Sign(int16_t as16_Sign, int16_t as16_Value);
STATIC_INLINE int32_t MATH_s32_Sign(int32_t as32_Sign, int32_t as32_Value);
STATIC_INLINE int32_t MATH_Q1_31_Q17_15_Mul(int32_t as32_A, int32_t as32_B);
STATIC_INLINE int16_t MATH_s16_Max(int16_t as16_A, int16_t as16_B);
STATIC_INLINE int16_t MATH_s16_Min(int16_t as16_A, int16_t as16_B);
STATIC_INLINE int32_t MATH_s32_Min(int32_t as32_A, int32_t as32_B);
STATIC_INLINE int32_t MATH_s32_Max(int32_t as32_A, int32_t as32_B);
STATIC_INLINE int16_t MATH_s16_Min3(int16_t as16_A, int16_t as16_B, int16_t as16_C);
STATIC_INLINE uint16_t MATH_u16_Min(uint16_t au16_A, uint16_t au16_B);
STATIC_INLINE uint16_t MATH_u16_Max(uint16_t au16_A, uint16_t au16_B);
STATIC_INLINE uint16_t MATH_u32_Sqrt(uint32_t au32_Arg);
STATIC_INLINE int16_t MATH_s16_AddBoundaryChecked(int16_t as16_X, int16_t as16_Y);
STATIC_INLINE int16_t MATH_MulDiv(int16_t as16_Factor1, int16_t as16_Factor2, int16_t as16_Divider);
STATIC_INLINE int16_t MATH_Div(int32_t as32_Dividend, int16_t as16_Divisor);
STATIC_INLINE uint16_t MATH_DivU(int32_t as32_Dividend, uint16_t au16_Divisor);
STATIC_INLINE int16_t MATH_s16_MulAndRound(int16_t as16_X, int16_t as16_Y);
STATIC_INLINE uint16_t MATH_u16_MulU(uint16_t au16_X, uint16_t au16_Y);
STATIC_INLINE int32_t MATH_s16_ShiftLeft(int16_t as16_X, uint8_t au8_ShiftLeft);
STATIC_INLINE int32_t MATH_s32_ShiftLeft(int32_t as32_X, uint8_t au8_ShiftLeft);

/**
 * \brief absolute value of an int32_t
 *
 * \param as32_In input value
 * \return absolute of the input value, |input value|
 */
STATIC_INLINE int32_t MATH_s32_Abs(int32_t as32_In) {
  AXIVION_MATH(as32_In)
  return (as32_In >= 0) ? as32_In : (-as32_In);
}

/**
 * \brief absolute value of an int16_t
 * \param as16_In input value
 * \return absolute of the input value, |input value|
 */
STATIC_INLINE int16_t MATH_s16_Abs(int16_t as16_In) {
  int16_t ls16_Ret;

  AXIVION_MATH(as16_In)
  /* when input is positive, return unmodified */
  if (as16_In >= 0) {
    ls16_Ret = as16_In;
  } else {
    /* when input is negative, return inverted */
    ls16_Ret = -as16_In;
  }
  return ls16_Ret;
}

/**
 * \brief negative absolute value of an int16_t
 * \param as16_In input value
 * \return absolute of the input value, |input value|
 */
STATIC_INLINE int16_t MATH_s16_NAbs(int16_t as16_In) {
  int16_t ls16_Ret;

  if (as16_In >= 0) {
    ls16_Ret = -as16_In;
  } else {
    ls16_Ret = as16_In;
  }
  return ls16_Ret;
}

/**
 * \brief saturation function, checks input value against upper and lower boundary, adjusts when necessary
 *
 * The function checks the input value against a given upper and lower boundary. If the input value
 * exceeds a boundary, it is adjusted. Otherwise, it passes unchanged.
 *
 * \warning as32_LowerLimit <= as32_UpperLimit must be fulfilled.
 *
 * \param as32_In input value
 * \param as32_LowerLimit lower limit
 * \param as32_UpperLimit upper limit
 * \return input value when input < upper limit and input > lower limit, otherwise the appropriate limit
 */
STATIC_INLINE int32_t MATH_s32_Limit(int32_t as32_In, int32_t as32_LowerLimit, int32_t as32_UpperLimit) {
  int32_t ls32_Limit;

  /* crop in to either lower or upper limit */
  /* lower limit is checked first */
  if (as32_In < as32_LowerLimit) {
    ls32_Limit = as32_LowerLimit;
  } else if (as32_In > as32_UpperLimit) {
    ls32_Limit = as32_UpperLimit;
  } else {
    ls32_Limit = as32_In;
  }
  return ls32_Limit;
}

/**
 * \brief saturation function, checks input value against upper and lower boundary, adjusts when necessary
 *
 * The function checks the input value against a given upper and lower boundary. If the input value
 * exceeds a boundary, it is adjusted. Otherwise, it passes unchanged.
 *
 * \warning as64_LowerLimit <= as64_LowerLimit must be fulfilled.
 *
 * \param as64_X input value
 * \param as64_LowerLimit lower limit
 * \param as64_UpperLimit upper limit
 * \return input value when input < upper limit and input > lower limit, otherwise the appropriate limit
 */
STATIC_INLINE int64_t MATH_s64_Limit(int64_t as64_X, int64_t as64_LowerLimit, int64_t as64_UpperLimit) {
  return (as64_X < as64_UpperLimit) ? ((as64_X > as64_LowerLimit) ? as64_X : as64_LowerLimit) : as64_UpperLimit;
}

/**
 * \brief sine function
 *
 * The function calculates a table-based sine. It does not interpolate due to performance reasons.
 * Output value is Q1.15.
 *
 * Angle is [-32768;32767] = [-Pi:Pi]
 *
 * \param as16_Angle input angle according to Angle definition
 * \return sine value in Q1.15 range [-32767;32767] = [-1;1]
 */
STATIC_INLINE int16_t MATH_s16_Sin(int16_t as16_Angle) {
  /* AXIVION Next Line : MisraC2012-10.8 : The conversion is used to efficiently create an index, so the change of essential style is mandatory  */
  uint16_t index = ((uint16_t) (as16_Angle + 128)) >> 8;
  /* Rationale: The overflow is intended */
  /* AXIVION Next Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
  return ((int16_t) MATH_gs8_Sinus_Table[index]) << 8;
}

/**
 * \brief sine function with linear interpolation
 *
 * The function calculates a table-based sine. It does interpolate to reach a higher accuracy.
 * Output value is Q1.15.
 *
 * \param as16_Angle input angle according to Angle definition
 * \return sine value in Q1.15 range [-32767;32767] = [-1;1]
 */
STATIC_INLINE int16_t MATH_Q15_Sin(int16_t as16_Angle) {
  /* AXIVION Next Codeline : MisraC2012-Directive-4.1: Truncation is intentional and unit-tested over the full range */
  uint8_t lu8_index    = (uint8_t) (((uint16_t) as16_Angle) >> 8);
  /* AXIVION Next Codeline : MisraC2012-Directive-4.1: Truncation is intentional and unit-tested over the full range */
  uint8_t lu8_subindex = (uint8_t) as16_Angle;
  int16_t ls16_yn;
  int16_t ls16_ydiff;

  /* determine base value and gradient */
  /* gradient is controlled by the last byte, base value by the upper byte */
  ls16_yn    = MATH_gs16_SinusTable256[lu8_index];
  ls16_ydiff = (int16_t) (((int32_t) MATH_gs16_SinusTable256_Gradient[lu8_index] * (int32_t) lu8_subindex)
      >> 8); /* AXIVION Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
  /* AXIVION Next Codeline : MisraC2012Directive-4.1: The function is fully unit-tested to work correctly, the table is prepared not to overflow */
  return ls16_yn + ls16_ydiff;
}

/**
 * \brief cosine function
 *
 * The function calculates a table-based cosine. It does not interpolate due to performance reasons.
 * Output value is Q1.15.
 *
 * Angle is [-32768;32767] = [-Pi:Pi]
 *
 * \param as16_Angle input angle according to Angle definition
 * \return sine value in Q1.15 range [-32767;32767] = [-1;1]
 */
STATIC_INLINE int16_t MATH_s16_Cos(int16_t as16_Angle) {
  return MATH_s16_Sin(as16_Angle + Q1_15(0.5));
}

/**
 * \brief sine function with linear interpolation
 *
 * The function calculates a table-based sine. It does interpolate to reach a higher accuracy.
 * Output value is Q1.15.
 *
 * \param as16_Angle input angle according to Angle definition
 * \return sine value in Q1.15 range [-32767;32767] = [-1;1]
 */
STATIC_INLINE int16_t MATH_Q15_Cos(int16_t as16_Angle) {
  /* AXIVION Next Codeline : MisraC2012-Directive-4.1: Truncation is intentional and unit-tested over the full range */
  return MATH_Q15_Sin(as16_Angle + Q1_15(0.5));
}

/**
 * \brief convert a Q1.15 to a Q1.31
 *
 * The function converts a Q1.15 int16_t to a Q1.31 int32_t by shifting 16 bits.
 *
 * \param as16_In input value
 * \return upscaled int32_t value
 */
STATIC_INLINE int32_t MATH_s16_Convert_s32(int16_t as16_In) {
  int32_t ls32_In;

  ls32_In = as16_In;
  return ls32_In
      << 16; /* AXIVION Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
}

/**
 * \brief convert a Q1.31 to a Q1.15
 *
 * This function converts a Q1.31 int32_t to a Q1.15 int16_t by shifting 16 bits.
 * No rounding is performed.
 *
 * \param as32_In input value
 * \return downscaled int16_t value
 */
STATIC_INLINE int16_t MATH_s32_Convert_s16(int32_t as32_In) {
  return ((int16_t) (as32_In
      >> 16)); /* AXIVION Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
}

/**
 * \brief convert a Q15.31 to a Q15.15
 *
 * This function converts a Q15.31 int64_t to a Q15.15 int32_t by shifting 16 bits.
 * No rounding is performed.
 *
 * \param as64_In input value
 * \return downscaled int32_t value
 */
STATIC_INLINE int32_t MATH_s48_Convert_s32(int64_t as64_In) {
  return ((int32_t) (as64_In
      >> 16)); /* AXIVION Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
}

/**
 * \brief convert a Q1.31 to a Q1.15 by rounding
 *
 * This function converts a Q1.31 int32_t to a Q1.15 int16_t by shifting 16 bits.
 * Rounding is performed.
 *
 * \param as32_In input value
 * \return downscaled int16_t value
 */
STATIC_INLINE int16_t MATH_s32_Round(int32_t as32_In) {
  return ((int16_t) ((as32_In + 32768)
      >> 16)); /* AXIVION Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
}

/**
 * \brief convert a Q1.31 to a Q1.15 by rounding
 *
 * This function converts a Q1.31 int32_t to a Q1.15 int16_t by shifting 16 bits.
 * Rounding is performed and accumulated for later error compensation.
 *
 * \param as32_In input value
 * \param aps32_Error accumulated error across several rounding operations
 * \return downscaled int16_t value
 */
STATIC_INLINE int16_t MATH_s32_RoundStatefull(int32_t as32_In, int32_t *aps32_Error) {
  int16_t ls16_Rounded;
  int32_t ls32_Upscaled;

  ls16_Rounded = MATH_s32_Convert_s16(as32_In + *aps32_Error);

  /* calculate error and prepare error accumulation */
  ls32_Upscaled = MATH_s16_Convert_s32(ls16_Rounded);
  *aps32_Error = as32_In - ls32_Upscaled;

  return ls16_Rounded;
}

/**
 * \brief divide a Q1.31 by a Q1.15
 *
 * This function divides a Q1.31 by a Q1.15. The result is stored in a Q1.15.
 * Division by 0 is handled by returning 0.
 *
 * Q1.15(0.4) = MATH_s32_DivByQ1_15 ( Q1.31(0.2), Q1.15(0.5));
 *
 * \param as32_In dividend
 * \param as16_Divisor divisor
 * \return result in Q1.15
 */
STATIC_INLINE int16_t MATH_s32_DivByQ1_15(int32_t as32_In, int16_t as16_Divisor) {
  int16_t ls16_Ret;

  if (as16_Divisor != 0) {
    ls16_Ret = (int16_t) (as32_In / (((int32_t) as16_Divisor)
        << 1)); /* AXIVION Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
  } else {
    ls16_Ret = 0;
  }
  return ls16_Ret;
}

/**
 * \brief divide a Q1.15 by a Q1.15
 *
 * The function divides a Q1.15 by a Q1.15 and returns a Q1.15.
 * The function handles division by 0 by returning Q1.15(-1) for X < 0, Q1.15(1) for X > 0 and 0 for X == 0
 *
 * Q1.15(0.4) = MATH_s16_Div ( Q1.15(0.2), Q1.15(0.5));
 *
 * \param as16_X dividend
 * \param as16_Y divisor
 * \return result of the division
 */
STATIC_INLINE int16_t MATH_s16_Div(int16_t as16_X, int16_t as16_Y) {
  int32_t ls32_X;
  int32_t ls32_Res;
  int16_t ls16_Res;

  /* initial value check
   * when Y is 0, go for either positive or negative maximum
   */
  if (as16_Y == 0) {
    if (as16_X < 0) {
      ls16_Res = Q1_15(-1.0);
    } else if (as16_X > 0) {
      ls16_Res = Q1_15(1.0);
    } else {
      ls16_Res = Q1_15(0.0);
    }
  } else {
    /* execute division when either X and Y are sane */
    /* truncate the result to fit in 15 bit */
    /* AXIVION Next Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
    ls32_X   = ((int32_t) as16_X) << 15;
    ls32_Res = ls32_X / ((int32_t) as16_Y);
    ls16_Res = (int16_t) (MATH_s32_Limit(ls32_Res, Q1_15(-1.0), Q1_15(1.0)));
  }
  return ls16_Res;
}

/**
 * \brief multiply Q1.15 and Q1.15 and return Q1.15
 *
 * The function multiplies two Q1.15 values and returns a Q1.15.
 *
 * \param as16_X factor a in Q1.15
 * \param as16_Y factor b in Q1.15
 * \return result of the multiplication in Q1.15
 */
STATIC_INLINE int16_t MATH_s16_Mul(int16_t as16_X, int16_t as16_Y) {
  AXIVION_MATH(as16_X)
  AXIVION_MATH(as16_Y)
  return (int16_t) ((((int32_t) as16_X) * ((int32_t) as16_Y))
      >> 15); /* AXIVION Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
}

/**
 * \brief multiply Q1.15 and Q1.15 and return Q?.??.
 *
 * The function multiplies two Q1.15 values and returns a Q?.??.
 *
 * \param as16_X factor a in Q1.15
 * \param as16_Y factor b in Q1.15
 * \param as16_Z right shift in bits -1
 * \return result of the multiplication in Q?.??
 */
STATIC_INLINE int16_t MATH_s32_MulQx(int16_t as16_X, int16_t as16_Y, int16_t as16_Z) {
  /* AXIVION Next Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
  return (int16_t) ((((int32_t) as16_X) * ((int32_t) as16_Y)) >> (as16_Z + 1));
}

/**
 * \brief multiply Q1.15 and Q1.15 with rounding and return Q1.15
 *
 * The function multiplies two Q1.15 values and returns a Q1.15.
 *
 * \param as16_X factor a in Q1.15
 * \param as16_Y factor b in Q1.15
 * \return result of the multiplication in Q1.15
 */
STATIC_INLINE int16_t MATH_s16_MulRound(int16_t as16_X, int16_t as16_Y) {
  return (int16_t) ((16384 + (((int32_t) as16_X) * ((int32_t) as16_Y)))
      >> 15); /* AXIVION Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
}

/**
 * \brief multiply Q1.15 and Q1.15 and return Q1.31
 *
 * The function multiplies two Q1.15 values and returns a Q1.31.
 *
 * \param as16_X factor a in Q1.15
 * \param as16_Y factor b in Q1.15
 * \return result of the multiplication in Q1.31
 */
STATIC_INLINE int32_t MATH_s32_Mul16(int16_t as16_X, int16_t as16_Y) {
  return (int32_t) ((((int32_t) as16_X) * ((int32_t) as16_Y))
      << 1); /* AXIVION Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
}

/**
 * \brief divide Q1.15 by 2
 *
 * The function is a helper function for dividing a number in Q1.15 by two.
 *
 * \param as16_X input value
 * \return result of input value / 2
 */
STATIC_INLINE int16_t MATH_s16_Div2(int16_t as16_X) {
  /* AXIVION Next Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
  return as16_X >> 1;
}

/**
 * \brief divide Q1.31 by 2
 *
 * The function is a helper function for dividing a number in Q1.31 by two.
 *
 * \param as32_X input value
 * \return result of input value / 2
 */
STATIC_INLINE int32_t MATH_s32_Div2(int32_t as32_X) {
  /* AXIVION Next Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
  return as32_X >> 1;
}

/**
 * \brief divide Q1.15 by 4
 *
 * The function is a helper function for dividing a number in Q1.15 by four.
 *
 * \param as16_X input value
 * \return result of input value / 4
 */
STATIC_INLINE int16_t MATH_s16_Div4(int16_t as16_X) {
  /* AXIVION Next Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
  return as16_X >> 2;
}

/**
 * \brief sign transfer of as16_Sign to as16_Value (Q1.15)
 *
 * The function inverts as16_Value depending on the value of as16_Sign. So it's no pure signum function.
 * In contrast to the signum function, the often necessary multiplication is avoided.
 *
 * When as16_Sign < 0 then return -as16_Value, otherwise as16_Value
 *
 * This function generates
 * result = as16_Sign * as16_Value / | as16_Sign |
 *
 * \param as16_Sign sign giving parameter
 * \param as16_Value sign receiving parameter
 * \return result as defined above
 */
STATIC_INLINE int16_t MATH_s16_Sign(int16_t as16_Sign, int16_t as16_Value) {
  AXIVION_MATH(as16_Value)
  return (as16_Sign < 0) ? (-as16_Value) : (as16_Value);
}

/**
 * \brief sign transfer of as32_Sign to as32_Value (Q1.31)
 *
 * The function inverts as16_Value depending on the value of as32_Sign. So it's no pure signum function.
 * In contrast to the signum function, the often necessary multiplication is avoided.
 *
 * When as32_Sign < 0 then return -as32_Value, otherwise as32_Value
 *
 * This function generates
 * result = as32_Sign * as32_Value / | as32_Sign |
 *
 * \param as32_Sign sign giving parameter
 * \param as32_Value sign receiving parameter
 * \return result as defined above
 */
STATIC_INLINE int32_t MATH_s32_Sign(int32_t as32_Sign, int32_t as32_Value) {
  return (as32_Sign < 0) ? (-as32_Value) : (as32_Value);
}

/**
 * \brief multiply a Q1.31 and a Q17.15 and return a Q1.31
 *
 * This function calculates
 *
 * Q1.31(0.2) = MATH_Q1_31_Q17_15_Mul(Q1_31(0.1), Q17_15(2));
 *
 * \param as32_A factor a in Q1.31
 * \param as32_B factor b in Q17.15
 * \return product of both in Q1.31
 */
STATIC_INLINE int32_t MATH_Q1_31_Q17_15_Mul(int32_t as32_A, int32_t as32_B) {
  int64_t ls64_Res;

  ls64_Res = ((int64_t) as32_A) * ((int64_t) as32_B);
  /* AXIVION Next Line : MisraC2012-10.1 : The Shift operation has been verified to work correctly on Keil for ARM */
  return ((int32_t) (ls64_Res >> 15));
}

/**
 * \brief maximum function for int16_t
 *
 * \param as16_A parameter a
 * \param as16_B parameter b
 * \return max(parameter a, parameter b)
 */
STATIC_INLINE int16_t MATH_s16_Max(int16_t as16_A, int16_t as16_B) {
  return (as16_A > as16_B) ? as16_A : as16_B;
}

/**
 * \brief minimum function for int16_t
 *
 * \param as16_A parameter a
 * \param as16_B parameter b
 * \return min(parameter a, parameter b)
 */
STATIC_INLINE int16_t MATH_s16_Min(int16_t as16_A, int16_t as16_B) {
  return (as16_A < as16_B) ? as16_A : as16_B;
}

/**
 * \brief saturated difference of x - y
 * @param as16_X minuend
 * @param as16_Y subtrahend
 * @return saturation(minuend - subtrahend, -2^15, 2^15)
 */
STATIC_INLINE int16_t MATH_s16_Difference(int16_t as16_X, int16_t as16_Y) {
  int32_t ls32_Ret;

  ls32_Ret = ((int32_t) as16_X) - ((int32_t) as16_Y);
  if (ls32_Ret > INT16_MAX) {
    ls32_Ret = INT16_MAX;
  } else if (ls32_Ret < INT16_MIN) {
    ls32_Ret = INT16_MIN;
  } else {
    /* no cropping in this case */
  }
  return (int16_t) ls32_Ret;
}

/**
 * \brief ternary minimum function for int16_t
 *
 * \param as16_A parameter a
 * \param as16_B parameter b
 * \param as16_C parameter c
 * \return min(min(parameter a, parameter b), parameter c)
 */
STATIC_INLINE int16_t MATH_s16_Min3(int16_t as16_A, int16_t as16_B, int16_t as16_C) {
  return MATH_s16_Min(MATH_s16_Min(as16_A, as16_B), as16_C);
}

/**
 * \brief ternary minimum function for int16_t
 *
 * \param as16_A parameter a
 * \param as16_B parameter b
 * \param as16_C parameter c
 * \return max(max(parameter a, parameter b), parameter c)
 */
STATIC_INLINE int16_t MATH_s16_Max3(int16_t as16_A, int16_t as16_B, int16_t as16_C) {
  return MATH_s16_Max(MATH_s16_Max(as16_A, as16_B), as16_C);
}

/**
 * \brief minimum function for uint16_t
 *
 * \param au16_A parameter a
 * \param au16_B parameter b
 * \return min(parameter a, parameter b)
 */
STATIC_INLINE uint16_t MATH_u16_Min(uint16_t au16_A, uint16_t au16_B) {
  /* AXIVION Next Codeline: MisraC2012-2.2, MisraC2012-14.3 : The code is only redundant but re-used across other implementations. */
  return (au16_A < au16_B) ? au16_A : au16_B;
}

/**
 * \brief maximum function for uint16_t
 *
 * \param au16_A parameter a
 * \param au16_B parameter b
 * \return max(parameter a, parameter b)
 */
STATIC_INLINE uint16_t MATH_u16_Max(uint16_t au16_A, uint16_t au16_B) {
  return (au16_A > au16_B) ? au16_A : au16_B;
}

/**
 * \brief minimum for int32_t
 * \param as32_A first value
 * \param as32_B second value
 * \return smaller of first or second value
 */
STATIC_INLINE int32_t MATH_s32_Min(int32_t as32_A, int32_t as32_B) {
  /* determine minimum of two values */
  return (as32_A < as32_B) ? as32_A : as32_B;
}

/**
 * \brief maximum for int32_t
 * \param as32_A first value
 * \param as32_B second value
 * \return larger of first or second value
 */
STATIC_INLINE int32_t MATH_s32_Max(int32_t as32_A, int32_t as32_B) {
  /* determine maximum of two values */
  return (as32_A > as32_B) ? as32_A : as32_B;
}

/**
 * \brief integer square root function
 * \param au32_Arg square root input, integer based
 * \return sqrt of au32, integer based
 */
STATIC_INLINE uint16_t MATH_u32_Sqrt(uint32_t au32_Arg) {
  uint32_t op  = au32_Arg;
  uint32_t res = 0U;
  uint32_t one = (uint32_t) (1UL << 30U);
  /* The second-to-top bit is set: use 1u << 14 for uint16_t type; use 1uL<<30 for uint32_t type */

  /* "one" starts at the highest power of four <= than the argument. */
  while (one > op) {
    one >>= 2U;
  }

  while (one != 0U) {
    /* AXIVION Next Codeline: MisraC2012Directive-4.1 : The function is unit tested over the full value range to assert the function */
    if (op >= (res + one)) {
      /* AXIVION Next Codeline: MisraC2012Directive-4.1 : The function is unit tested over the full value range to assert the function */
      op  = op - (res + one);
      /* AXIVION Next Codeline: MisraC2012Directive-4.1 : The function is unit tested over the full value range to assert the function */
      res = res + (2U * one);
    }
    res >>= 1U;
    one >>= 2U;
  }
  /* AXIVION Next Codeline: MisraC2012Directive-4.1 : The function is unit tested over the full value range to assert the function */
  return (uint16_t) res;
}

/**
 * \brief square root approximation
 *
 * approximation using the babylonian method (heron), 3 iterations
 * accuracy: (subError <= 1 || 0.9995 < divError < 1.0005) where subError = abs(result - result_exact)
 *                                                           and divError = result / result_exact
 *                                                           and result_exact = floor(sqrt(au32_Arg))
 *
 * \param au32_Arg radicand (the number to compute the square root from) in the range [0, 2^{31}-1]
 * \return approximated square root result
 */
STATIC_INLINE uint16_t MATH_u32_Sqrt_approx(uint32_t au32_Arg) {
  uint32_t x1;
  uint32_t lu32_s;
  uint32_t g0;
  uint32_t g1;
  uint16_t lu16_Return;

  if (au32_Arg <= 1U) {
    lu16_Return = (uint16_t) au32_Arg;
  } else {
    lu32_s  = 1U;
    x1 = au32_Arg - 1U;

    /* count leading zeros, more than 16 bits non-zero */
    if (x1 > 65535U) {
      lu32_s += 8U;
      x1 >>= 16U;
    }

    /* count leading zeros, more than 8 bits non-zero */
    if (x1 > 255U) {
      lu32_s += 4U;
      x1 >>= 8U;
    }

    /* count leading zeros, more than 4 bits non-zero */
    if (x1 > 15U) {
      lu32_s += 2U;
      x1 >>= 4U;
    }

    /* count leading zeros, more than 2 bits non-zero */
    if (x1 > 3U) {
      lu32_s += 1U;
    }

    /* rough guess (1st iteration) */
    g0 = (uint32_t) (1UL << lu32_s);
    g1 = (g0 + (au32_Arg >> lu32_s)) >> 1U;

    /* iterate 2nd time */
    g0 = g1;
    g1 = (g0 + (au32_Arg / g0)) >> 1U;

    /* iterate 3rd time */
    g0 = g1;
    /* AXIVION Next Codeline : MisraCDirective-4.1: The unit test covers the full input range, thus the operation is safe */
    g1 = (g0 + (au32_Arg / g0)) >> 1U;

    /* AXIVION Next Codeline : MisraCDirective-4.1: The unit test covers the full input range, thus the operation is safe */
    lu16_Return = (uint16_t) g1;
  }
  return lu16_Return;
}

/**
 * \brief boundary checking addition of two int16_t
 * \param as16_X first operand
 * \param as16_Y second operand
 * \return sum, saturated at 32767 or -32767
 */
STATIC_INLINE int16_t MATH_s16_AddBoundaryChecked(int16_t as16_X, int16_t as16_Y) {
  uint16_t lu16_Res;
  int16_t  ls16_Res;

  if (as16_X >= 0) {
    if (as16_Y >= 0) {
      /* both signs are equal, this can create an overflow */
      lu16_Res = (uint16_t) as16_X + (uint16_t) as16_Y;
      if (lu16_Res > 32767U) {
        lu16_Res = 32767U;
      }
      ls16_Res = (int16_t) lu16_Res;
    } else {
      /* signs differ, overflow not possible */
      ls16_Res = as16_X + as16_Y;
    }
  } else {
    if (as16_Y >= 0) {
      /* signs differ, overflow not possible */
      ls16_Res = as16_X + as16_Y;
    } else {
      lu16_Res = (uint16_t) (-as16_X) + (uint16_t) (-as16_Y);
      if (lu16_Res > 32767U) {
        lu16_Res = 32767U;
      }
      ls16_Res = -((int16_t) lu16_Res);
    }
  }
  return ls16_Res;
}

/**
 * \brief generic multiply divide function for Q1.15
 * the function calculated y = f1 * f2 / d1;
 * the function is integer based and does not shift (not needed because
 * semantics is identical on Q1.15 and on integer
 *
 * the function uses 32 bit internally, thus cannot overflow.
 * however, when the divider is too small, the output is not cropped but
 * invalid for performance reasons.
 *
 * \warning d1 must be != 0
 * \param as16_Factor1 f1
 * \param as16_Factor2 f2
 * \param as16_Divider d1
 * \return y
 */
STATIC_INLINE int16_t MATH_MulDiv(int16_t as16_Factor1, int16_t as16_Factor2, int16_t as16_Divider) {
  int32_t as32_Result;

  AXIVION_ASSERT(as16_Divider != 0)
  /* multiply first for better precision at reasonable costs of 32 bits, then divide */
  as32_Result = ((int32_t) as16_Factor1 * (int32_t) as16_Factor2) / as16_Divider;
  /* AXIVION Next Codeline : MisraCDirective-4.1: The supply voltage is used as a divider, dynamic range is a factor of two, crop factor allows for a factor of 8 */
  return (int16_t) as32_Result;
}

/**
 * \brief calculate dividend / divisor using the H430 divider
 *
 * The calculation is performed in integer manner.
 *
 * \warning the function is not protected vs. division by 0
 *
 * \param as32_Dividend dividend
 * \param as16_Divisor divisor
 * \return the calculated result
 */
STATIC_INLINE int16_t MATH_Div(int32_t as32_Dividend, int16_t as16_Divisor) {
  /* AXIVION Next Codeline : MisraC2012Directive-4.1: THe caller must ensure that the divisor is not 0 */
  return (int16_t) (as32_Dividend / as16_Divisor);
}

/**
 * \brief calculate dividend / divisor using the H430 divider
 *
 * The calculation is performed in integer manner.
 *
 * \warning the function is not protected vs. division by 0
 *
 * \param as32_Dividend dividend
 * \param au16_Divisor divisor
 * \return the calculated result
 */
STATIC_INLINE uint16_t MATH_DivU(int32_t as32_Dividend, uint16_t au16_Divisor) {
  return (uint16_t) (((uint32_t) as32_Dividend) / au16_Divisor);
}

/**
 * \brief multiply Q1.15 and Q1.15 and return Q1.15
 *
 * The function multiplies two Q1.15 values and returns a Q1.15.
 * The result is rounded.
 *
 * \param as16_X factor a in Q1.15
 * \param as16_Y factor b in Q1.15
 * \return result of the multiplication in Q1.15
 */
STATIC_INLINE int16_t MATH_s16_MulAndRound(int16_t as16_X, int16_t as16_Y) {
  /* add an offset for rounding */
  /* AXIVION Next Line : MisraC2012-10.1 : Left shift is working correctly on Keil */
  return (16384 + ((int32_t) as16_X * (int32_t) as16_Y)) >> 15U;
}

/**
 * \brief multiply unsigned Q1.15 and Q1.15 and return unsigned Q1.15
 *
 * The sense of this function is to allow factors in the range of [0;2[
 * We need this e.g. for calibration of ADC-Values, where a Q17.15 would be
 * uninteresting from the performance side.
 *
 * \warning the result is limited to the same range, so a product of 2 * 2 is exceed the possible range
 *
 * \param au16_X
 * \param au16_Y
 * \return
 */
STATIC_INLINE uint16_t MATH_u16_MulU(uint16_t au16_X, uint16_t au16_Y) {
  uint32_t lu32_Result;

  AXIVION_UMATH(au16_X)
  /* multiply first, then shift for better precision */
  lu32_Result = (uint32_t) au16_X * (uint32_t) au16_Y;
  return (uint16_t) (lu32_Result >> 15u);
}

/**
 * \brief multiply two values as Q1.15 with rounding
 * \param au16_X first factor
 * \param au16_Y second factor
 * \return result of the Q1.15 multiplication of X and Y, rounded half up
 */
STATIC_INLINE uint16_t MATH_u16_MulUAndRound(uint16_t au16_X, uint16_t au16_Y) {
  uint32_t lu32_Result;

  lu32_Result = 16384U + (((uint32_t) au16_X) * (uint16_t) au16_Y);
  return (uint16_t) (lu32_Result >> 15U);
}

/**
 * \brief generic trigonometric calculation to calculate c = h^2 - a^2
 *
 * \param as16_Hypotenuse h of the triangle
 * \param as16_AdjacentSide a of the triangle
 * \return difference of h^2 and a^2 (square root must be executed separately)
 */
STATIC_INLINE int32_t MATH_SquaresSubtract(int16_t as16_Hypotenuse, int16_t as16_AdjacentSide) {
  int32_t ls32_SquareA;
  int32_t ls32_SquareB;

  /* calculate pythagoras but do not execute the sqrt */
  ls32_SquareA = (int32_t) as16_Hypotenuse * (int32_t) as16_Hypotenuse;
  ls32_SquareB = (int32_t) as16_AdjacentSide * (int32_t) as16_AdjacentSide;
  return ls32_SquareA - ls32_SquareB;
}

/**
 * \brief generic shift left of a Q1.15 input value
 * \param as16_X input value, Q1.15
 * \param au8_ShiftLeft in bits
 * \return shifted value
 */
STATIC_INLINE int32_t MATH_s16_ShiftLeft(int16_t as16_X, uint8_t au8_ShiftLeft) {
  /* generic shift left 16 bit */
  /* AXIVION Next Line : MisraC2012-10.1 : Left shift is working correctly on Keil */
  return (int32_t) as16_X << au8_ShiftLeft;
}

/**
 * \brief generic shift left of a Q1.31 input value
 * \param as32_X input value, Q1.31
 * \param au8_ShiftLeft in bits
 * \return shifted value
 */
STATIC_INLINE int32_t MATH_s32_ShiftLeft(int32_t as32_X, uint8_t au8_ShiftLeft) {
  /* generic shift left 32 bit */
  /* AXIVION Next Line : MisraC2012-10.1 : Left shift is working correctly on Keil */
  return as32_X << au8_ShiftLeft;
}

/* PRQA S 3219 -- */
/* PRQA S 3453 -- */

#endif /* MATH_SCALAR_BASE_H */
/** \}
 */
/* end of file */
