/* Include files */

#include "modelInterface.h"
#include "m_mOxH7mQKhjczP4hb1vskQF.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_mOxH7mQKhjczP4hb1vskQF *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_mOxH7mQKhjczP4hb1vskQF
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_mOxH7mQKhjczP4hb1vskQF
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_mOxH7mQKhjczP4hb1vskQF
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_mOxH7mQKhjczP4hb1vskQF
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_mOxH7mQKhjczP4hb1vskQF
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_mOxH7mQKhjczP4hb1vskQF
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_mOxH7mQKhjczP4hb1vskQF
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_mOxH7mQKhjczP4hb1vskQF
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_mOxH7mQKhjczP4hb1vskQF *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_mOxH7mQKhjczP4hb1vskQF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_mOxH7mQKhjczP4hb1vskQF
  *moduleInstance)
{
  VectorAB_T b_local;
  VectorDQ_T local;
  local.s64_d = *(real_T *)&((char_T *)moduleInstance->u0)[0];
  local.s64_q = *(real_T *)&((char_T *)moduleInstance->u0)[8];
  InverseParkTransform_uQ4LZkjVPWhiGNFOCSwL0(&local, &(*moduleInstance->u1)[0],
    &b_local);
  *(real_T *)&((char_T *)moduleInstance->b_y0)[0] = b_local.s64_alpha;
  *(real_T *)&((char_T *)moduleInstance->b_y0)[8] = b_local.s64_beta;
}

static void cgxe_mdl_update(InstanceStruct_mOxH7mQKhjczP4hb1vskQF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_mOxH7mQKhjczP4hb1vskQF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_mOxH7mQKhjczP4hb1vskQF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_mOxH7mQKhjczP4hb1vskQF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_mOxH7mQKhjczP4hb1vskQF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_mOxH7mQKhjczP4hb1vskQF
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (VectorDQ_T *)cgxertGetInputPortSignal(moduleInstance->S,
    0);
  moduleInstance->u1 = (real_T (*)[2])cgxertGetInputPortSignal(moduleInstance->S,
    1);
  moduleInstance->b_y0 = (VectorAB_T *)cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
}

/* CGXE Glue Code */
static void mdlOutputs_mOxH7mQKhjczP4hb1vskQF(SimStruct *S, int_T tid)
{
  InstanceStruct_mOxH7mQKhjczP4hb1vskQF *moduleInstance =
    (InstanceStruct_mOxH7mQKhjczP4hb1vskQF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_mOxH7mQKhjczP4hb1vskQF(SimStruct *S)
{
  InstanceStruct_mOxH7mQKhjczP4hb1vskQF *moduleInstance =
    (InstanceStruct_mOxH7mQKhjczP4hb1vskQF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_mOxH7mQKhjczP4hb1vskQF(SimStruct *S, int_T tid)
{
  InstanceStruct_mOxH7mQKhjczP4hb1vskQF *moduleInstance =
    (InstanceStruct_mOxH7mQKhjczP4hb1vskQF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_mOxH7mQKhjczP4hb1vskQF(SimStruct *S)
{
  InstanceStruct_mOxH7mQKhjczP4hb1vskQF *moduleInstance =
    (InstanceStruct_mOxH7mQKhjczP4hb1vskQF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_mOxH7mQKhjczP4hb1vskQF(SimStruct *S)
{
  InstanceStruct_mOxH7mQKhjczP4hb1vskQF *moduleInstance =
    (InstanceStruct_mOxH7mQKhjczP4hb1vskQF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_mOxH7mQKhjczP4hb1vskQF(SimStruct *S)
{
  InstanceStruct_mOxH7mQKhjczP4hb1vskQF *moduleInstance =
    (InstanceStruct_mOxH7mQKhjczP4hb1vskQF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_mOxH7mQKhjczP4hb1vskQF(SimStruct *S)
{
  InstanceStruct_mOxH7mQKhjczP4hb1vskQF *moduleInstance =
    (InstanceStruct_mOxH7mQKhjczP4hb1vskQF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_mOxH7mQKhjczP4hb1vskQF(SimStruct *S)
{
  InstanceStruct_mOxH7mQKhjczP4hb1vskQF *moduleInstance =
    (InstanceStruct_mOxH7mQKhjczP4hb1vskQF *)calloc(1, sizeof
    (InstanceStruct_mOxH7mQKhjczP4hb1vskQF));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_mOxH7mQKhjczP4hb1vskQF);
  ssSetmdlInitializeConditions(S, mdlInitialize_mOxH7mQKhjczP4hb1vskQF);
  ssSetmdlUpdate(S, mdlUpdate_mOxH7mQKhjczP4hb1vskQF);
  ssSetmdlDerivatives(S, mdlDerivatives_mOxH7mQKhjczP4hb1vskQF);
  ssSetmdlTerminate(S, mdlTerminate_mOxH7mQKhjczP4hb1vskQF);
  ssSetmdlEnable(S, mdlEnable_mOxH7mQKhjczP4hb1vskQF);
  ssSetmdlDisable(S, mdlDisable_mOxH7mQKhjczP4hb1vskQF);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_mOxH7mQKhjczP4hb1vskQF(SimStruct *S)
{
}

void method_dispatcher_mOxH7mQKhjczP4hb1vskQF(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_mOxH7mQKhjczP4hb1vskQF(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_mOxH7mQKhjczP4hb1vskQF(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: mOxH7mQKhjczP4hb1vskQF.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_mOxH7mQKhjczP4hb1vskQF_BuildInfoUpdate(void)
{
  mxArray * mxBIArgs;
  mxArray * elem_1;
  mxArray * elem_2;
  mxArray * elem_3;
  double * pointer;
  mxBIArgs = mxCreateCellMatrix(1,3);
  elem_1 = mxCreateDoubleMatrix(0,0, mxREAL);
  pointer = mxGetPr(elem_1);
  mxSetCell(mxBIArgs,0,elem_1);
  elem_2 = mxCreateDoubleMatrix(0,0, mxREAL);
  pointer = mxGetPr(elem_2);
  mxSetCell(mxBIArgs,1,elem_2);
  elem_3 = mxCreateCellMatrix(1,0);
  mxSetCell(mxBIArgs,2,elem_3);
  return mxBIArgs;
}

mxArray *cgxe_mOxH7mQKhjczP4hb1vskQF_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleFunction");
  mxArray* incompatibleSymbol = mxCreateString("InverseParkTransform");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
