#ifndef __brgiCrLfjCAKSVXxdxwlJ_h__
#define __brgiCrLfjCAKSVXxdxwlJ_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_brgiCrLfjCAKSVXxdxwlJ
#define typedef_InstanceStruct_brgiCrLfjCAKSVXxdxwlJ

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  ClarkeInput *u0;
  real_T *u1;
  real_T *u2;
  real_T *b_y0;
  real_T *b_y1;
} InstanceStruct_brgiCrLfjCAKSVXxdxwlJ;

#endif                                 /* typedef_InstanceStruct_brgiCrLfjCAKSVXxdxwlJ */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_brgiCrLfjCAKSVXxdxwlJ(SimStruct *S, int_T method,
  void* data);

#endif
