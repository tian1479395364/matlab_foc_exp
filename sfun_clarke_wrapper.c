
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#define SIMPLIFIED_RTWTYPES_COMPATIBILITY
#include "rtwtypes.h"
#undef SIMPLIFIED_RTWTYPES_COMPATIBILITY
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define u_1_width 1
#define u_2_width 1
#define y_width 1
#define y_1_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void sfun_clarke_Outputs_wrapper(const real_T *ia,
			const real_T *ib,
			const real_T *ic,
			real_T *i_alpha,
			real_T *i_beta)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
real_T f64_ia;
real_T f64_ib;
real_T f64_ic;
real_T f64_i_alpha;
real_T f64_i_beta;

f64_ia = ia[0];
f64_ib = ib[0];
f64_ic = ic[0];

f64_i_alpha = 0.6666666666666666 * f64_ia
            - 0.3333333333333333 * (f64_ib + f64_ic);

f64_i_beta  = 0.5773502691896257 * (f64_ib - f64_ic);

i_alpha[0] = f64_i_alpha;
i_beta[0]  = f64_i_beta;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


