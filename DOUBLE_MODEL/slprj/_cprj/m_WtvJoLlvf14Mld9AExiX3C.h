#ifndef __WtvJoLlvf14Mld9AExiX3C_h__
#define __WtvJoLlvf14Mld9AExiX3C_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_WtvJoLlvf14Mld9AExiX3C
#define typedef_InstanceStruct_WtvJoLlvf14Mld9AExiX3C

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  VectorAB_T *u0;
  real_T (*u1)[2];
  VectorDQ_T *b_y0;
} InstanceStruct_WtvJoLlvf14Mld9AExiX3C;

#endif                                 /* typedef_InstanceStruct_WtvJoLlvf14Mld9AExiX3C */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_WtvJoLlvf14Mld9AExiX3C(SimStruct *S, int_T method,
  void* data);

#endif
