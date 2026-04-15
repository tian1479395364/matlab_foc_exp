#ifndef __MaDgHuWbHkqTxwPW63XgKE_h__
#define __MaDgHuWbHkqTxwPW63XgKE_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_MaDgHuWbHkqTxwPW63XgKE
#define typedef_InstanceStruct_MaDgHuWbHkqTxwPW63XgKE

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  VectorUVW_T *u0;
  VectorAB_T *b_y0;
} InstanceStruct_MaDgHuWbHkqTxwPW63XgKE;

#endif                                 /* typedef_InstanceStruct_MaDgHuWbHkqTxwPW63XgKE */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_MaDgHuWbHkqTxwPW63XgKE(SimStruct *S, int_T method,
  void* data);

#endif
