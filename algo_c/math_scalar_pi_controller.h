#ifndef MATH_SCALAR_PI_CONTROLLER_H
#define MATH_SCALAR_PI_CONTROLLER_H

#include "math_scalar_base.h"

/** \brief access macro for selecting the PI controller's lower limit and automatically convert it to Q1.31 */
#define PARAMETER_LOWER_LIMIT MATH_s16_CONVERT_s32(as_Parameter->s16_LowerLimit)
/** \brief access macro for selecting the PI controller's upper limit and automatically convert it to Q1.31 */
#define PARAMETER_UPPER_LIMIT MATH_s16_CONVERT_s32(as_Parameter->s16_UpperLimit)
/** \brief access macro for selecting the PI controller's lower limit and automatically convert it to Q1.63 */
#define PARAMETER_LOWER_LIMIT64 MATH_s16_CONVERT_s64(as_Parameter->s16_LowerLimit)
/** \brief access macro for selecting the PI controller's upper limit and automatically convert it to Q1.63 */
#define PARAMETER_UPPER_LIMIT64 MATH_s16_CONVERT_s64(as_Parameter->s16_UpperLimit)

/**
 * \file math_scalar_pi_controller.h
 *
 * This file contains generic pi controllers, one with a standard range of 16 bit, the other with a 32 bit input range.
 * Both controllers use the parallel form of the pi controller.
 *
 * The gains are in the quite uncommon Q16.16 format for performance reasons.
 */

/** \brief macro to fill a PI controller parameter structure with KP, KI */
#define PI(kp,ki) .s32_KP = (kp), .s32_KI = (ki)

/**
 * \brief pi controller parameters
 *
 * \warning s16_LowerLimit must be smaller than s16_UpperLimit
 */
typedef struct MATH_Scalar_PI_Controller_ParameterS {
  int16_t s16_LowerLimit; /**< lower limit for y and integral part in Q1.15 */
  int16_t s16_UpperLimit; /**< upper limit for y and integral part in Q1.15 */
  int32_t s32_KP;         /**< proportional gain in Q16.16 */
  int32_t s32_KI;         /**< integral gain in Q16.16 */
} MATH_Scalar_PI_Controller_Parameter_T;

/**
 * \brief pi controller state
 *
 * The pi controller just contains an integral state in Q1.31 notation.
 */
typedef struct MATH_Scalar_PI_Controller_State_S {
  int32_t s32_i_n; /**< integral part in Q1.31 */
} MATH_Scalar_PI_Controller_State_T;

/* PRQA S 3219 ++ */

STATIC_INLINE int16_t MATH_Scalar_PI_Controller(MATH_Scalar_PI_Controller_State_T *aps_State,
                                                const MATH_Scalar_PI_Controller_Parameter_T *as_Parameter,
                                                int16_t as16_Error);
STATIC_INLINE int16_t MATH_Scalar_PI_Controller32(MATH_Scalar_PI_Controller_State_T *aps_State,
                                                  const MATH_Scalar_PI_Controller_Parameter_T *as_Parameter,
                                                  int32_t as32_Error);
STATIC_INLINE void MATH_Scalar_PI_Controller_Init(MATH_Scalar_PI_Controller_State_T *aps_State, int16_t as16_i_n);
STATIC_INLINE void MATH_Scalar_PI_Controller_SetLimit(MATH_Scalar_PI_Controller_Parameter_T *as_Parameter,
                                                      int16_t as16_LowerLimit,
                                                      int16_t as16_UpperLimit);
STATIC_INLINE int16_t MATH_Scalar_PI_Controller_GetIntegralPart(const MATH_Scalar_PI_Controller_State_T *aps_State);

/**
 * \brief pi controller worker function with Q1.15 input range
 *
 * The function takes an input error value and returns a new control value. The parallel form of the pi controller is used.
 * The limits are applied internally to the integral part and the control value.
 *
 * \warning s16_LowerLimit must be <= s16_UpperLimit
 * \warning The product of the input range and the gain is limited to 31 bit in the integer domain. It silently overflows when bigger values are processed.
 *
 * \param[in,out] aps_State pi controller state
 * \param[in]     as_Parameter pi controller parameter
 * \param[in]     as16_Error difference between set point and measurement in Q1.15
 * \return        updated control value in Q1.15
 */
STATIC_INLINE int16_t MATH_Scalar_PI_Controller(MATH_Scalar_PI_Controller_State_T *aps_State,
                                                const MATH_Scalar_PI_Controller_Parameter_T *as_Parameter,
                                                int16_t as16_Error) {
  int32_t ls32_ErrorKp;
  int32_t ls32_ErrorKi;
  int32_t ls32_y_n;
  int32_t ls32_UpperLimit;
  int32_t ls32_LowerLimit;
  int32_t ls32_i_n;

  /* parallel pi controller implementation */
  /* anti-windup is done by absolute limits */
  /* no overflow protection for KP/KI * error */
  /* the caller must make sure that this is not violated */
  /* AXIVION Next Codeline : MisraC2012Directive-4.1: The function is intended for a limited parameter range, this is documented behavior */
  ls32_ErrorKp = as_Parameter->s32_KP * ((int32_t) as16_Error);
  /* AXIVION Next Codeline : MisraC2012Directive-4.1: The function is intended for a limited parameter range, this is documented behavior */
  ls32_ErrorKi = as_Parameter->s32_KI * ((int32_t) as16_Error);

  AXIVION_MATH32(aps_State->s32_i_n)
  AXIVION_MATH32(ls32_ErrorKi)
  AXIVION_MATH32(ls32_ErrorKp)
  AXIVION_MATH(as_Parameter->s16_UpperLimit)
  AXIVION_MATH(as_Parameter->s16_LowerLimit)

  ls32_i_n = aps_State->s32_i_n + ls32_ErrorKi;
  ls32_y_n = ls32_i_n + ls32_ErrorKp;

  /* AXIVION Next Codeline : MisraC2012Directive-4.1: The expression cannot overflow because the base parameter is 15 bits */
  ls32_UpperLimit = PARAMETER_UPPER_LIMIT;
  if (ls32_i_n > ls32_UpperLimit) {
    ls32_i_n = ls32_UpperLimit;
  }
  if (ls32_y_n > ls32_UpperLimit) {
    ls32_y_n = ls32_UpperLimit;
  }

  /* AXIVION Next Codeline : MisraC2012Directive-4.1: The expression cannot overflow because the base parameter is 15 bits */
  ls32_LowerLimit = PARAMETER_LOWER_LIMIT;
  if (ls32_i_n < ls32_LowerLimit) {
    ls32_i_n = ls32_LowerLimit;
  }

  if (ls32_y_n < ls32_LowerLimit) {
    ls32_y_n = ls32_LowerLimit;
  }

  aps_State->s32_i_n = ls32_i_n;
  return MATH_s32_Convert_s16(ls32_y_n);
}

/**
 * \brief pi controller worker function with Q17.15 input range
 *
 * The function takes an input error value and returns a new control value. The parallel form of the pi controller is used.
 * The limits are applied internally to the integral part and the control value.
 *
 * In contrast to the faster Q1.15 implementation, this implementation can take much larger input differences. This proves
 * quite helpful on larger inputs like multi turn angle differences.
 *
 * \warning s16_LowerLimit must be <= s16_UpperLimit
 * \warning The product of the input range and the gain is limited to 63 bit in the integer domain. It silently overflows when bigger values are processed.
 *
 * \param[in,out] aps_State pi controller state
 * \param[in]     as_Parameter pi controller parameter
 * \param[in]     as32_Error difference between set point and measurement in Q17.15
 * \return        updated control value in Q1.15
 */
STATIC_INLINE int16_t MATH_Scalar_PI_Controller32(MATH_Scalar_PI_Controller_State_T *aps_State,
                                                  const MATH_Scalar_PI_Controller_Parameter_T *as_Parameter,
                                                  int32_t as32_Error) {
  int64_t ls64_ErrorKp;
  int64_t ls64_ErrorKi;
  int32_t ls32_ErrorKp;
  int32_t ls32_ErrorKi;
  int32_t ls32_y_n;
  int32_t ls32_UpperLimit;
  int32_t ls32_LowerLimit;
  int32_t ls32_i_n;

  /* parallel pi controller implementation */
  /* anti-windup is done by absolute limits */
  /* internal calculation is performed in 64 bit and cropped numerically correct */
  /* this implementation requires 64 bit and thus is slow
   * it uses the MATH_s64_Limit function to crop the values */

  ls64_ErrorKp = ((int64_t) as_Parameter->s32_KP) * ((int64_t) as32_Error);
  ls64_ErrorKi = ((int64_t) as_Parameter->s32_KI) * ((int64_t) as32_Error);

  /* crop by anti-windup limits */

  ls32_ErrorKp = ((int32_t) MATH_s64_Limit(ls64_ErrorKp,
                                           PARAMETER_LOWER_LIMIT64,
                                           PARAMETER_UPPER_LIMIT64));
  ls32_ErrorKi = ((int32_t) MATH_s64_Limit(ls64_ErrorKi,
                                           PARAMETER_LOWER_LIMIT64,
                                           PARAMETER_UPPER_LIMIT64));

  /* build simple sum, rectangular integration */

  ls32_i_n = aps_State->s32_i_n + ls32_ErrorKi;
  ls32_y_n = ls32_i_n + ls32_ErrorKp;

  ls32_UpperLimit = PARAMETER_UPPER_LIMIT;
  if (ls32_i_n > ls32_UpperLimit) {
    ls32_i_n = ls32_UpperLimit;
  }

  if (ls32_y_n > ls32_UpperLimit) {
    ls32_y_n = ls32_UpperLimit;
  }

  ls32_LowerLimit = PARAMETER_LOWER_LIMIT;
  if (ls32_i_n < ls32_LowerLimit) {
    ls32_i_n = ls32_LowerLimit;
  }

  if (ls32_y_n < ls32_LowerLimit) {
    ls32_y_n = ls32_LowerLimit;
  }

  /* save new integral part, convert to 16 for output */

  aps_State->s32_i_n = ls32_i_n;
  return MATH_s32_Convert_s16(ls32_y_n);
}

/**
 * \brief initialize the pi controller state
 *
 * This function initializes the pi controller state ( the integral part ) to a specific value. It is passed in in the
 * same dimension which is used for the output (Q1.15), so the scaling is done internally.
 *
 * \param[in,out] aps_State pi controller state
 * \param[in] as16_i_n new integral part in Q1.15
 */
STATIC_INLINE void MATH_Scalar_PI_Controller_Init(MATH_Scalar_PI_Controller_State_T *aps_State, int16_t as16_i_n) {
  /* convert 16 bit input state to 32 bit internal state */
  aps_State->s32_i_n = MATH_s16_Convert_s32(as16_i_n);
}

/**
 * \brief update the limits of the pi controller
 *
 * This function updates the limits within the pi controller parameters. The main reason for this function is to provide some
 * information hiding regarding the internal Q1.31 storage format of the lower, upper limit and the integral part.
 *
 * So the up scaling from Q1.15 to Q1.31 is done internally.
 *
 * \param[in,out] as_Parameter parameter structure to update
 * \param[in] as16_LowerLimit lower limit in Q1.15 format
 * \param[in] as16_UpperLimit upper limit in Q1.15 format
 */
STATIC_INLINE void MATH_Scalar_PI_Controller_SetLimit(MATH_Scalar_PI_Controller_Parameter_T *as_Parameter,
                                                      int16_t as16_LowerLimit,
                                                      int16_t as16_UpperLimit) {
  /* set boundaries of the anti-windup mechanism */
  as_Parameter->s16_LowerLimit = as16_LowerLimit;
  as_Parameter->s16_UpperLimit = as16_UpperLimit;
}

/**
 * \brief get integral state of the pi controller
 * the result must be in the same dimension of the output. internal scaling must be hidden from the caller.
 *
 * \param aps_State pi controller state
 * \return integral part of the pi controller in the domain of the output value
 */
STATIC_INLINE int16_t MATH_Scalar_PI_Controller_GetIntegralPart(const MATH_Scalar_PI_Controller_State_T *aps_State) {
  /* get integral part and convert it to 16 bit */
  return MATH_s32_Convert_s16(aps_State->s32_i_n);
}

/* PRQA S 3219 -- */

#endif /* MATH_SCALAR_PI_CONTROLLER_H */

/* end of file */
