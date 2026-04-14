#ifndef __th8rE7raOlxcwWhukpab2F_h__
#define __th8rE7raOlxcwWhukpab2F_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_InstanceStruct_th8rE7raOlxcwWhukpab2F
#define typedef_InstanceStruct_th8rE7raOlxcwWhukpab2F

typedef struct {
  SimStruct *S;
  void *emlrtRootTLSGlobal;
  real_T *u0;
  real_T *u1;
  SinCosInput *u2;
  real_T *u3;
  real_T *u4;
  real_T *b_y0;
  real_T *b_y1;
} InstanceStruct_th8rE7raOlxcwWhukpab2F;

#endif                                 /* typedef_InstanceStruct_th8rE7raOlxcwWhukpab2F */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_th8rE7raOlxcwWhukpab2F(SimStruct *S, int_T method,
  void* data);

#endif
