#ifndef PMSM_OBSERVER_H
#define PMSM_OBSERVER_H

#include "rtwtypes.h"
#include "jscl_transform.h"

typedef struct {
    double Rs;            /* stator resistance (ohm) */
    double Ls;            /* stator inductance (H) */
    double psi_f;         /* PM flux linkage (Wb) */
    double Ts;            /* sample time (s) */
    double pole_pairs;    /* motor pole pairs */
    double slide_gain;    /* current error correction gain (V) */
    double slide_limit;   /* boundary layer for sat() (A) */
    double emf_lpf_wc;    /* back-EMF LPF cutoff (rad/s) */
    double speed_lpf_wc;  /* speed output LPF cutoff (rad/s) */
    double pll_kp;        /* PLL proportional gain */
    double pll_ki;        /* PLL integral gain */
    double omega_min;     /* lower electrical speed limit (rad/s) */
    double omega_max;     /* upper electrical speed limit (rad/s) */
} PMSM_Observer_Param;

typedef struct {
    double i_alpha_hat;
    double i_beta_hat;
    double emf_alpha;
    double emf_beta;
    double theta;         /* electrical angle (rad) */
    double omega;         /* raw electrical speed for angle update (rad/s) */
    double omega_filt;    /* filtered electrical speed output (rad/s) */
    double omega_mech;    /* filtered mechanical speed output (rad/s) */
    double pll_integral;  /* electrical speed integral term (rad/s) */
} PMSM_Observer_State;

void PMSM_Observer_Init(void);
void PMSM_Observer_Reset(double theta0, double omega0);
void PMSM_Observer_SetParam(const PMSM_Observer_Param *param);
const PMSM_Observer_Param *PMSM_Observer_GetParam(void);
const PMSM_Observer_State *PMSM_Observer_GetState(void);

void PMSM_Observer_Step(
    const VectorAB_T *I_ab,
    const VectorAB_T *U_ab,
    double *theta_est,    /* electrical angle (rad) */
    double *omega_mech_est,/* filtered mechanical speed (rad/s) */
    double *omega_elec_est);/* filtered electrical speed (rad/s) */

#endif
