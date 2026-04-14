#ifndef __tPqLTR99yKB88prL95J7jB_h__
#define __tPqLTR99yKB88prL95J7jB_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_tPqLTR99yKB88prL95J7jB
#define typedef_InstanceStruct_tPqLTR99yKB88prL95J7jB

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  VectorAB_T *u0;
  VectorUVW_T *b_y0;
} InstanceStruct_tPqLTR99yKB88prL95J7jB;

#endif                                 /* typedef_InstanceStruct_tPqLTR99yKB88prL95J7jB */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_tPqLTR99yKB88prL95J7jB(SimStruct *S, int_T method,
  void* data);

#endif
