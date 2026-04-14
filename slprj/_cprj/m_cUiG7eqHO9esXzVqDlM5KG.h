#ifndef __cUiG7eqHO9esXzVqDlM5KG_h__
#define __cUiG7eqHO9esXzVqDlM5KG_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_cUiG7eqHO9esXzVqDlM5KG
#define typedef_InstanceStruct_cUiG7eqHO9esXzVqDlM5KG

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  VectorUVW_T *u0;
  VectorAB_T *b_y0;
} InstanceStruct_cUiG7eqHO9esXzVqDlM5KG;

#endif                                 /* typedef_InstanceStruct_cUiG7eqHO9esXzVqDlM5KG */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_cUiG7eqHO9esXzVqDlM5KG(SimStruct *S, int_T method,
  void* data);

#endif
