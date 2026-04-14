#ifndef __TxdjStq52qvaT6VgvmAIrC_h__
#define __TxdjStq52qvaT6VgvmAIrC_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_TxdjStq52qvaT6VgvmAIrC
#define typedef_InstanceStruct_TxdjStq52qvaT6VgvmAIrC

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  ClarkeInput *u0;
  real_T *b_y0;
  real_T *b_y1;
} InstanceStruct_TxdjStq52qvaT6VgvmAIrC;

#endif                                 /* typedef_InstanceStruct_TxdjStq52qvaT6VgvmAIrC */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_TxdjStq52qvaT6VgvmAIrC(SimStruct *S, int_T method,
  void* data);

#endif
