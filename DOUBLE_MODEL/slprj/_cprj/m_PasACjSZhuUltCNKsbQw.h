#ifndef __PasACjSZhuUltCNKsbQw_h__
#define __PasACjSZhuUltCNKsbQw_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_PasACjSZhuUltCNKsbQw
#define typedef_InstanceStruct_PasACjSZhuUltCNKsbQw

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real_T *u0;
  real_T *u1;
  real_T *u2;
  real_T *u3;
  real_T *u4;
  real_T *u5;
  real_T *u6;
  real_T *u7;
  VectorDQ_T *b_y0;
} InstanceStruct_PasACjSZhuUltCNKsbQw;

#endif                                 /* typedef_InstanceStruct_PasACjSZhuUltCNKsbQw */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_PasACjSZhuUltCNKsbQw(SimStruct *S, int_T method,
  void* data);

#endif
