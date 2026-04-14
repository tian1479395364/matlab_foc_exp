#ifndef __0SDQI7GoIcxIbgmUWNzcNH_h__
#define __0SDQI7GoIcxIbgmUWNzcNH_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH
#define typedef_InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  VectorDQ_T *u0;
  real_T (*u1)[2];
  VectorAB_T *b_y0;
} InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH;

#endif                                 /* typedef_InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_0SDQI7GoIcxIbgmUWNzcNH(SimStruct *S, int_T method,
  void* data);

#endif
