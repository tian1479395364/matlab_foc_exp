#ifndef __81c06mwKmM3M9WFiPBm4GD_h__
#define __81c06mwKmM3M9WFiPBm4GD_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_81c06mwKmM3M9WFiPBm4GD
#define typedef_InstanceStruct_81c06mwKmM3M9WFiPBm4GD

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  ClarkeInput *u0;
  real_T *b_y0;
  real_T *b_y1;
} InstanceStruct_81c06mwKmM3M9WFiPBm4GD;

#endif                                 /* typedef_InstanceStruct_81c06mwKmM3M9WFiPBm4GD */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_81c06mwKmM3M9WFiPBm4GD(SimStruct *S, int_T method,
  void* data);

#endif
