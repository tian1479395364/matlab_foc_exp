#ifndef __j28pSIu0gOhIgRCzODD5YC_h__
#define __j28pSIu0gOhIgRCzODD5YC_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_j28pSIu0gOhIgRCzODD5YC
#define typedef_InstanceStruct_j28pSIu0gOhIgRCzODD5YC

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real_T *u0;
  real_T *u1;
  SinCosInput *u2;
  real_T *b_y0;
  real_T *b_y1;
} InstanceStruct_j28pSIu0gOhIgRCzODD5YC;

#endif                                 /* typedef_InstanceStruct_j28pSIu0gOhIgRCzODD5YC */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_j28pSIu0gOhIgRCzODD5YC(SimStruct *S, int_T method,
  void* data);

#endif
