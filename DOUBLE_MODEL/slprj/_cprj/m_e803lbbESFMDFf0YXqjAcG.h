#ifndef __e803lbbESFMDFf0YXqjAcG_h__
#define __e803lbbESFMDFf0YXqjAcG_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_e803lbbESFMDFf0YXqjAcG
#define typedef_InstanceStruct_e803lbbESFMDFf0YXqjAcG

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  VectorDQ_T *u0;
  real_T (*u1)[2];
  VectorAB_T *b_y0;
} InstanceStruct_e803lbbESFMDFf0YXqjAcG;

#endif                                 /* typedef_InstanceStruct_e803lbbESFMDFf0YXqjAcG */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_e803lbbESFMDFf0YXqjAcG(SimStruct *S, int_T method,
  void* data);

#endif
