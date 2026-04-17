#include "jscl_transform.h"

#include <float.h>
#include <math.h>
#include <stddef.h>

typedef struct {
    double integral;
} SpeedPIState_T;

typedef struct {
    double current_speed;
    double current_acceleration_step;
} SpeedRampState_T;

typedef struct {
    SpeedRampState_T ramp;
    SpeedPIState_T pi;
} SpeedLoopState_T;

static SpeedRampState_T g_speed_ramp_state = {0.0, 0.0};
static SpeedPIState_T g_speed_pi_state = {0.0};
static SpeedLoopState_T g_speed_loop_state = {{0.0, 0.0}, {0.0}};

static double jscl_abs(double value)
{
    return (value >= 0.0) ? value : -value;
}

static double jscl_clamp(double value, double lower, double upper)
{
    double limited_value = value;

    if (lower > upper) {
        double temp = lower;
        lower = upper;
        upper = temp;
    }

    if (limited_value > upper) {
        limited_value = upper;
    }
    if (limited_value < lower) {
        limited_value = lower;
    }
    return limited_value;
}

static double jscl_sanitize_ts(double ts)
{
    return (ts > DBL_EPSILON) ? ts : 1.0e-6;
}

static void jscl_speed_pi_step_from_error(SpeedPIState_T *state,
                                          double speed_error,
                                          double kp,
                                          double ki,
                                          double ts,
                                          double upper_limit,
                                          double lower_limit,
                                          double *iq_ref)
{
    double integral_candidate;
    double output_candidate;

    if ((state == NULL) || (iq_ref == NULL)) {
        return;
    }

    ts = jscl_sanitize_ts(ts);
    integral_candidate = state->integral + (ki * speed_error * ts);
    integral_candidate = jscl_clamp(integral_candidate, lower_limit, upper_limit);

    output_candidate = integral_candidate + (kp * speed_error);
    output_candidate = jscl_clamp(output_candidate, lower_limit, upper_limit);

    state->integral = integral_candidate;
    *iq_ref = output_candidate;
}

static void jscl_speed_ramp_step(SpeedRampState_T *state,
                                 double speed_ref,
                                 double ts,
                                 double maximum_jerk,
                                 double maximum_acceleration,
                                 double minimum_acceleration,
                                 double *speed_cmd,
                                 int32_t *settled)
{
    double jerk_step;
    double maximum_acceleration_step;
    double minimum_acceleration_step;
    double difference;
    double abs_current_acceleration;
    double next_acceleration;
    double maximum_difference;
    double jerk;
    int32_t local_settled;

    if ((state == NULL) || (speed_cmd == NULL)) {
        return;
    }

    ts = jscl_sanitize_ts(ts);
    maximum_jerk = jscl_abs(maximum_jerk);
    maximum_acceleration = jscl_abs(maximum_acceleration);
    minimum_acceleration = -jscl_abs(minimum_acceleration);

    jerk_step = maximum_jerk * ts * ts;
    maximum_acceleration_step = maximum_acceleration * ts;
    minimum_acceleration_step = minimum_acceleration * ts;

    if (jerk_step <= DBL_EPSILON) {
        difference = speed_ref - state->current_speed;
        state->current_acceleration_step =
            jscl_clamp(difference, minimum_acceleration_step, maximum_acceleration_step);

        if (jscl_abs(difference) <= jscl_abs(state->current_acceleration_step)) {
            state->current_speed = speed_ref;
            state->current_acceleration_step = 0.0;
            local_settled = 1;
        } else {
            state->current_speed += state->current_acceleration_step;
            local_settled = 0;
        }

        *speed_cmd = state->current_speed;
        if (settled != NULL) {
            *settled = local_settled;
        }
        return;
    }

    abs_current_acceleration = jscl_abs(state->current_acceleration_step);
    next_acceleration = abs_current_acceleration + (2.0 * jerk_step);
    difference = speed_ref - state->current_speed;
    maximum_difference = 0.5 * next_acceleration * next_acceleration / jerk_step;

    if ((jscl_abs(difference) > DBL_EPSILON) || (abs_current_acceleration > jerk_step)) {
        if (difference < 0.0) {
            if (state->current_acceleration_step > 0.0) {
                jerk = -jerk_step;
            } else if (difference <= -maximum_difference) {
                jerk = -jerk_step;
            } else {
                jerk = jerk_step;
            }
        } else {
            if (state->current_acceleration_step < 0.0) {
                jerk = jerk_step;
            } else if (difference >= maximum_difference) {
                jerk = jerk_step;
            } else {
                jerk = -jerk_step;
            }
        }
        local_settled = 0;
    } else {
        state->current_speed = speed_ref;
        state->current_acceleration_step = 0.0;
        jerk = 0.0;
        local_settled = 1;
    }

    state->current_acceleration_step += jerk;
    state->current_acceleration_step = jscl_clamp(state->current_acceleration_step,
                                                  minimum_acceleration_step,
                                                  maximum_acceleration_step);
    state->current_speed += state->current_acceleration_step;

    *speed_cmd = state->current_speed;
    if (settled != NULL) {
        *settled = local_settled;
    }
}

/* ====================== Clarke Transform ====================== */
void ClarkeTransform(const VectorUVW_T *ABC_in, VectorAB_T *AB_out)
{
    AB_out->s64_alpha = 0.6666666666666666 * ABC_in->s64_u
                      - 0.3333333333333333 * (ABC_in->s64_v + ABC_in->s64_w);

    AB_out->s64_beta  = 0.5773502691896257 * (ABC_in->s64_v - ABC_in->s64_w);
}

/* ====================== Park Transform ====================== */
void ParkTransform(const VectorAB_T *AB_in, const double sin_cos[2], VectorDQ_T *DQ_out)
{
    double cos_theta = sin_cos[1];
    double sin_theta = sin_cos[0];

    DQ_out->s64_d =  AB_in->s64_alpha * cos_theta + AB_in->s64_beta * sin_theta;
    DQ_out->s64_q = -AB_in->s64_alpha * sin_theta + AB_in->s64_beta * cos_theta;
}

/* ====================== Inverse Park Transform ====================== */
void InverseParkTransform(const double sin_cos[2], const VectorDQ_T *in, VectorAB_T *out)
{
    double cos_theta = sin_cos[1];
    double sin_theta = sin_cos[0];

    out->s64_alpha = in->s64_d * cos_theta - in->s64_q * sin_theta;
    out->s64_beta  = in->s64_d * sin_theta + in->s64_q * cos_theta;
}

/* ====================== Inverse Clarke Transform ====================== */
void InverseClarkeTransform(const VectorAB_T *in, VectorUVW_T *out)
{
    out->s64_u = in->s64_alpha;
    out->s64_v = -0.5 * in->s64_alpha + 0.8660254037844386 * in->s64_beta;
    out->s64_w = -0.5 * in->s64_alpha - 0.8660254037844386 * in->s64_beta;
}

void CalcZeroSequenceVoltage(const VectorUVW_T *u_abc, double *u_zero)
{
    double max_val;
    double min_val;

    max_val = u_abc->s64_u;
    min_val = u_abc->s64_u;

    if (u_abc->s64_v > max_val) {
        max_val = u_abc->s64_v;
    }
    if (u_abc->s64_v < min_val) {
        min_val = u_abc->s64_v;
    }

    if (u_abc->s64_w > max_val) {
        max_val = u_abc->s64_w;
    }
    if (u_abc->s64_w < min_val) {
        min_val = u_abc->s64_w;
    }

    *u_zero = -0.5 * (max_val + min_val);
}

void SVPWM_CalcDutyCycle(double u_zero, const VectorUVW_T *u_abc, double vbus, double tABC[3])
{
    double pwm_scale = 4199.0;
    int i;

    tABC[0] = (-(u_abc->s64_u + u_zero) / vbus + 0.5) * pwm_scale;
    tABC[1] = (-(u_abc->s64_v + u_zero) / vbus + 0.5) * pwm_scale;
    tABC[2] = (-(u_abc->s64_w + u_zero) / vbus + 0.5) * pwm_scale;

    for (i = 0; i < 3; i++) {
        if (tABC[i] > pwm_scale * 0.995) {
            tABC[i] = pwm_scale * 0.995;
        } else if (tABC[i] < pwm_scale * 0.005) {
            tABC[i] = pwm_scale * 0.005;
        }
    }
}

void sincos_func(double theta, double sin_cos[2])
{
    sin_cos[0] = sin(theta);
    sin_cos[1] = cos(theta);
}

void SpeedRamp_Reset(double initial_speed)
{
    g_speed_ramp_state.current_speed = initial_speed;
    g_speed_ramp_state.current_acceleration_step = 0.0;
}

void SpeedRamp_Step(double speed_ref,
                    double ts,
                    double maximum_jerk,
                    double maximum_acceleration,
                    double minimum_acceleration,
                    double *speed_cmd,
                    int32_t *settled)
{
    jscl_speed_ramp_step(&g_speed_ramp_state,
                         speed_ref,
                         ts,
                         maximum_jerk,
                         maximum_acceleration,
                         minimum_acceleration,
                         speed_cmd,
                         settled);
}

void SpeedPI_Reset(double integral_init)
{
    g_speed_pi_state.integral = integral_init;
}

void SpeedPI_Controller(double speed_ref,
                        double speed_est,
                        double kp,
                        double ki,
                        double ts,
                        double upper_limit,
                        double lower_limit,
                        double *iq_ref)
{
    double speed_error = speed_ref - speed_est;

    jscl_speed_pi_step_from_error(&g_speed_pi_state,
                                  speed_error,
                                  kp,
                                  ki,
                                  ts,
                                  upper_limit,
                                  lower_limit,
                                  iq_ref);
}

void SpeedLoop_Reset(double initial_speed_cmd, double initial_iq_ref)
{
    g_speed_loop_state.ramp.current_speed = initial_speed_cmd;
    g_speed_loop_state.ramp.current_acceleration_step = 0.0;
    g_speed_loop_state.pi.integral = initial_iq_ref;
}

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
                    SpeedLoopOut_T *out)
{
    double speed_error;

    if (out == NULL) {
        return;
    }

    jscl_speed_ramp_step(&g_speed_loop_state.ramp,
                         speed_ref,
                         ts,
                         maximum_jerk,
                         maximum_acceleration,
                         minimum_acceleration,
                         &out->s64_speed_cmd,
                         NULL);

    speed_error = out->s64_speed_cmd - speed_est;

    jscl_speed_pi_step_from_error(&g_speed_loop_state.pi,
                                  speed_error,
                                  kp,
                                  ki,
                                  ts,
                                  iq_upper_limit,
                                  iq_lower_limit,
                                  &out->s64_iq_ref);
}
