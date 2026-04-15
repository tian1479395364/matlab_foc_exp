#ifndef __MOLC88wviLzdgeX5uzlQBF_h__
#define __MOLC88wviLzdgeX5uzlQBF_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_MOLC88wviLzdgeX5uzlQBF
#define typedef_InstanceStruct_MOLC88wviLzdgeX5uzlQBF

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  VectorUVW_T *u0;
  real_T *b_y0;
} InstanceStruct_MOLC88wviLzdgeX5uzlQBF;

#endif                                 /* typedef_InstanceStruct_MOLC88wviLzdgeX5uzlQBF */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_MOLC88wviLzdgeX5uzlQBF(SimStruct *S, int_T method,
  void* data);

#endif
