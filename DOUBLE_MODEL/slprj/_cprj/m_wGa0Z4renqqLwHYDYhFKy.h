#ifndef __wGa0Z4renqqLwHYDYhFKy_h__
#define __wGa0Z4renqqLwHYDYhFKy_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_wGa0Z4renqqLwHYDYhFKy
#define typedef_InstanceStruct_wGa0Z4renqqLwHYDYhFKy

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real_T *u0;
  VectorUVW_T *u1;
  real_T *u2;
  real_T (*b_y0)[3];
} InstanceStruct_wGa0Z4renqqLwHYDYhFKy;

#endif                                 /* typedef_InstanceStruct_wGa0Z4renqqLwHYDYhFKy */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_wGa0Z4renqqLwHYDYhFKy(SimStruct *S, int_T method,
  void* data);

#endif
