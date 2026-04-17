#ifndef JSCL_TRANSFORM_H
#define JSCL_TRANSFORM_H

#include <stdint.h>

/**
 * \brief 2D-vector for alpha/beta domain
 */
typedef struct VectorAB_S {
    double s64_alpha;   /**< alpha */
    double s64_beta;    /**< beta  */
} VectorAB_T;

/**
 * \brief 2D-vector for d/q domain
 */
typedef struct VectorDQ_S {
    double s64_d;       /**< d */
    double s64_q;       /**< q */
} VectorDQ_T;

/**
 * \brief 3D-vector in ABC domain
 */
typedef struct VectorUVW_S {
    double s64_u;       /**< phase U/A */
    double s64_v;       /**< phase V/B */
    double s64_w;       /**< phase W/C */
} VectorUVW_T;

typedef struct {
    double m_sin;
    double m_cos;
} SinCos_T;

typedef struct SpeedLoopOut_S {
    double s64_speed_cmd;  /**< ramped speed reference */
    double s64_iq_ref;     /**< q-axis current reference */
} SpeedLoopOut_T;

/* Clarke Transform: ABC -> alpha/beta */
void ClarkeTransform(const VectorUVW_T *ABC_in, VectorAB_T *AB_out);

/* Park Transform: alpha/beta -> dq */
void ParkTransform(const VectorAB_T *AB_in, const double sin_cos[2], VectorDQ_T *DQ_out);

/* Inverse Park Transform: dq -> alpha/beta */
void InverseParkTransform(const double sin_cos[2], const VectorDQ_T *in, VectorAB_T *out);

/* Inverse Clarke Transform: alpha/beta -> ABC */
void InverseClarkeTransform(const VectorAB_T *AB_in, VectorUVW_T *ABC_out);

void CalcZeroSequenceVoltage(const VectorUVW_T *u_abc, double *u_zero);

void SVPWM_CalcDutyCycle(double u_zero, const VectorUVW_T *u_abc, double vbus, double tABC[3]);

void sincos_func(double theta, double sin_cos[2]);

void SpeedRamp_Reset(double initial_speed);

void SpeedRamp_Step(double speed_ref,
                    double ts,
                    double maximum_jerk,
                    double maximum_acceleration,
                    double minimum_acceleration,
                    double *speed_cmd,
                    int32_t *settled);

void SpeedPI_Reset(double integral_init);

void SpeedPI_Controller(double speed_ref,
                        double speed_est,
                        double kp,
                        double ki,
                        double ts,
                        double upper_limit,
                        double lower_limit,
                        double *iq_ref);

void SpeedLoop_Reset(double initial_speed_cmd, double initial_iq_ref);

void SpeedLoop_Step(double speed_ref,
                    double speed_est,
                    double ts,
                    double maximum_jerk,
                    double maximum_acceleration,
                    double minimum_acceleration,
                    double kp,
                    double ki,
                    double iq_upper_limit,
                    double iq_lower_limit,
                    SpeedLoopOut_T *out);

#endif
