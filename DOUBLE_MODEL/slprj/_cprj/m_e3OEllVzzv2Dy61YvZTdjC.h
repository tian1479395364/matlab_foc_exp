#ifndef __e3OEllVzzv2Dy61YvZTdjC_h__
#define __e3OEllVzzv2Dy61YvZTdjC_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_e3OEllVzzv2Dy61YvZTdjC
#define typedef_InstanceStruct_e3OEllVzzv2Dy61YvZTdjC

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  VectorAB_T *u0;
  VectorUVW_T *b_y0;
} InstanceStruct_e3OEllVzzv2Dy61YvZTdjC;

#endif                                 /* typedef_InstanceStruct_e3OEllVzzv2Dy61YvZTdjC */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_e3OEllVzzv2Dy61YvZTdjC(SimStruct *S, int_T method,
  void* data);

#endif
