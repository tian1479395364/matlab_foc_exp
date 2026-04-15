#ifndef __a4luxM7sjft7hior8qnEQG_h__
#define __a4luxM7sjft7hior8qnEQG_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_a4luxM7sjft7hior8qnEQG
#define typedef_InstanceStruct_a4luxM7sjft7hior8qnEQG

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real_T *u0;
  VectorUVW_T *u1;
  real_T *u2;
  real_T (*b_y0)[3];
} InstanceStruct_a4luxM7sjft7hior8qnEQG;

#endif                                 /* typedef_InstanceStruct_a4luxM7sjft7hior8qnEQG */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_a4luxM7sjft7hior8qnEQG(SimStruct *S, int_T method,
  void* data);

#endif
