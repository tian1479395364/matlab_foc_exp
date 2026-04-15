#ifndef __mOxH7mQKhjczP4hb1vskQF_h__
#define __mOxH7mQKhjczP4hb1vskQF_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_mOxH7mQKhjczP4hb1vskQF
#define typedef_InstanceStruct_mOxH7mQKhjczP4hb1vskQF

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  VectorDQ_T *u0;
  real_T (*u1)[2];
  VectorAB_T *b_y0;
} InstanceStruct_mOxH7mQKhjczP4hb1vskQF;

#endif                                 /* typedef_InstanceStruct_mOxH7mQKhjczP4hb1vskQF */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_mOxH7mQKhjczP4hb1vskQF(SimStruct *S, int_T method,
  void* data);

#endif
