#ifndef __unweDRdyki1td8msJpm6_h__
#define __unweDRdyki1td8msJpm6_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_unweDRdyki1td8msJpm6
#define typedef_InstanceStruct_unweDRdyki1td8msJpm6

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  VectorAB_T *u0;
  real_T (*u1)[2];
  VectorDQ_T *b_y0;
} InstanceStruct_unweDRdyki1td8msJpm6;

#endif                                 /* typedef_InstanceStruct_unweDRdyki1td8msJpm6 */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_unweDRdyki1td8msJpm6(SimStruct *S, int_T method,
  void* data);

#endif
