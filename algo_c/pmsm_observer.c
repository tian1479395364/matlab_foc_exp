#include "pmsm_observer.h"

#include <math.h>
#include <stddef.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

static PMSM_Observer_Param g_obs_param = {
    .Rs          = 0.45,
    .Ls          = 0.0045,
    .psi_f       = 0.085,
    .Ts          = 0.0001,
    .pole_pairs  = 5.0,
    .slide_gain  = 40.0,
    .slide_limit = 0.5,
    .emf_lpf_wc  = 1200.0,
    .speed_lpf_wc = 120.0,
    .pll_kp      = 120.0,
    .pll_ki      = 4000.0,
    .omega_min   = -4000.0,
    .omega_max   = 4000.0
};

static PMSM_Observer_State g_obs_state = {0};

static double clamp_value(double value, double lower, double upper)
{
    if (value > upper) {
        return upper;
    }
    if (value < lower) {
        return lower;
    }
    return value;
}

static double wrap_angle(double theta)
{
    while (theta >= 2.0 * M_PI) {
        theta -= 2.0 * M_PI;
    }
    while (theta < 0.0) {
        theta += 2.0 * M_PI;
    }
    return theta;
}

static double sat_value(double value, double limit)
{
    if (limit <= 0.0) {
        return (value >= 0.0) ? 1.0 : -1.0;
    }
    return clamp_value(value / limit, -1.0, 1.0);
}

static double lpf_alpha_from_wc(double wc, double ts)
{
    if (wc <= 0.0) {
        return 1.0;
    }
    return 1.0 - exp(-wc * ts);
}

void PMSM_Observer_Init(void)
{
    PMSM_Observer_Reset(0.0, 0.0);
}

void PMSM_Observer_Reset(double theta0, double omega0)
{
    g_obs_state.i_alpha_hat = 0.0;
    g_obs_state.i_beta_hat = 0.0;
    g_obs_state.emf_alpha = 0.0;
    g_obs_state.emf_beta = 0.0;
    g_obs_state.theta = wrap_angle(theta0);
    g_obs_state.omega = clamp_value(omega0, g_obs_param.omega_min, g_obs_param.omega_max);
    g_obs_state.omega_filt = g_obs_state.omega;
    g_obs_state.omega_mech = g_obs_state.omega_filt / g_obs_param.pole_pairs;
    g_obs_state.pll_integral = g_obs_state.omega;
}

void PMSM_Observer_SetParam(const PMSM_Observer_Param *param)
{
    if (param == NULL) {
        return;
    }

    g_obs_param = *param;

    if (g_obs_param.Ls < 1.0e-7) {
        g_obs_param.Ls = 1.0e-7;
    }
    if (g_obs_param.Ts < 1.0e-7) {
        g_obs_param.Ts = 1.0e-7;
    }
    if (g_obs_param.pole_pairs < 1.0) {
        g_obs_param.pole_pairs = 1.0;
    }
    if (g_obs_param.slide_limit < 1.0e-6) {
        g_obs_param.slide_limit = 1.0e-6;
    }
    if (g_obs_param.emf_lpf_wc < 0.0) {
        g_obs_param.emf_lpf_wc = 0.0;
    }
    if (g_obs_param.speed_lpf_wc < 0.0) {
        g_obs_param.speed_lpf_wc = 0.0;
    }
    if (g_obs_param.omega_min > g_obs_param.omega_max) {
        double tmp = g_obs_param.omega_min;
        g_obs_param.omega_min = g_obs_param.omega_max;
        g_obs_param.omega_max = tmp;
    }

    g_obs_state.omega = clamp_value(g_obs_state.omega, g_obs_param.omega_min, g_obs_param.omega_max);
    g_obs_state.pll_integral = clamp_value(g_obs_state.pll_integral,
                                           g_obs_param.omega_min,
                                           g_obs_param.omega_max);
    g_obs_state.omega_filt = clamp_value(g_obs_state.omega_filt,
                                         g_obs_param.omega_min,
                                         g_obs_param.omega_max);
    g_obs_state.omega_mech = g_obs_state.omega_filt / g_obs_param.pole_pairs;
}

const PMSM_Observer_Param *PMSM_Observer_GetParam(void)
{
    return &g_obs_param;
}

const PMSM_Observer_State *PMSM_Observer_GetState(void)
{
    return &g_obs_state;
}

void PMSM_Observer_Step(
    const VectorAB_T *I_ab,
    const VectorAB_T *U_ab,
    double *theta_est,
    double *omega_mech_est,
    double *omega_elec_est)
{
    double err_alpha;
    double err_beta;
    double z_alpha;
    double z_beta;
    double di_alpha;
    double di_beta;
    double emf_lpf_alpha;
    double emf_amp;
    double cos_theta;
    double sin_theta;
    double emf_d;
    double emf_q;
    double emf_q_abs;
    double pll_error;
    double omega_prop;
    double omega_cmd;
    double speed_alpha;

    if ((I_ab == NULL) || (U_ab == NULL)) {
        return;
    }

    err_alpha = I_ab->s64_alpha - g_obs_state.i_alpha_hat;
    err_beta = I_ab->s64_beta - g_obs_state.i_beta_hat;

    z_alpha = g_obs_param.slide_gain * sat_value(err_alpha, g_obs_param.slide_limit);
    z_beta = g_obs_param.slide_gain * sat_value(err_beta, g_obs_param.slide_limit);

    di_alpha = (U_ab->s64_alpha
                - g_obs_param.Rs * g_obs_state.i_alpha_hat
                - g_obs_state.emf_alpha
                + z_alpha) / g_obs_param.Ls;
    di_beta = (U_ab->s64_beta
               - g_obs_param.Rs * g_obs_state.i_beta_hat
               - g_obs_state.emf_beta
               + z_beta) / g_obs_param.Ls;

    g_obs_state.i_alpha_hat += g_obs_param.Ts * di_alpha;
    g_obs_state.i_beta_hat += g_obs_param.Ts * di_beta;

    emf_lpf_alpha = lpf_alpha_from_wc(g_obs_param.emf_lpf_wc, g_obs_param.Ts);
    g_obs_state.emf_alpha += emf_lpf_alpha * (z_alpha - g_obs_state.emf_alpha);
    g_obs_state.emf_beta += emf_lpf_alpha * (z_beta - g_obs_state.emf_beta);

    emf_amp = sqrt(g_obs_state.emf_alpha * g_obs_state.emf_alpha +
                   g_obs_state.emf_beta * g_obs_state.emf_beta);

    cos_theta = cos(g_obs_state.theta);
    sin_theta = sin(g_obs_state.theta);

    /* PMSM back-EMF should lie on q-axis; force estimated d-axis EMF to zero. */
    emf_d = g_obs_state.emf_alpha * cos_theta + g_obs_state.emf_beta * sin_theta;
    emf_q = -g_obs_state.emf_alpha * sin_theta + g_obs_state.emf_beta * cos_theta;
    emf_q_abs = fabs(emf_q);

    if (emf_q < 0.0) {
        emf_d = -emf_d;
    }

    pll_error = -emf_d / (emf_q_abs + 0.05 * g_obs_param.psi_f + 1.0e-6);
    pll_error = clamp_value(pll_error, -1.0, 1.0);

    omega_prop = g_obs_param.pll_kp * pll_error;
    omega_cmd = g_obs_state.pll_integral + omega_prop;

    if (((omega_cmd < g_obs_param.omega_max) || (pll_error < 0.0)) &&
        ((omega_cmd > g_obs_param.omega_min) || (pll_error > 0.0))) {
        g_obs_state.pll_integral += g_obs_param.pll_ki * pll_error * g_obs_param.Ts;
        g_obs_state.pll_integral = clamp_value(g_obs_state.pll_integral,
                                               g_obs_param.omega_min,
                                               g_obs_param.omega_max);
    }

    g_obs_state.omega = g_obs_state.pll_integral + omega_prop;
    g_obs_state.omega = clamp_value(g_obs_state.omega,
                                    g_obs_param.omega_min,
                                    g_obs_param.omega_max);

    g_obs_state.theta += g_obs_state.omega * g_obs_param.Ts;
    g_obs_state.theta = wrap_angle(g_obs_state.theta);

    if (emf_amp < 0.02 * g_obs_param.psi_f) {
        speed_alpha = 0.02;
    } else {
        speed_alpha = lpf_alpha_from_wc(g_obs_param.speed_lpf_wc, g_obs_param.Ts);
    }

    g_obs_state.omega_filt += speed_alpha * (g_obs_state.omega - g_obs_state.omega_filt);
    g_obs_state.omega_mech = g_obs_state.omega_filt / g_obs_param.pole_pairs;

    if (theta_est != NULL) {
        *theta_est = g_obs_state.theta;
    }
    if (omega_mech_est != NULL) {
        *omega_mech_est = g_obs_state.omega_mech;
    }
    if (omega_elec_est != NULL) {
        *omega_elec_est = g_obs_state.omega_filt;
    }
}
