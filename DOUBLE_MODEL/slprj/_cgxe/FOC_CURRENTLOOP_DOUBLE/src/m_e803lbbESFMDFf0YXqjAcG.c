/* Include files */

#include "modelInterface.h"
#include "m_e803lbbESFMDFf0YXqjAcG.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_e803lbbESFMDFf0YXqjAcG *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_e803lbbESFMDFf0YXqjAcG
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_e803lbbESFMDFf0YXqjAcG
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_e803lbbESFMDFf0YXqjAcG
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_e803lbbESFMDFf0YXqjAcG
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_e803lbbESFMDFf0YXqjAcG
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_e803lbbESFMDFf0YXqjAcG
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_e803lbbESFMDFf0YXqjAcG
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_e803lbbESFMDFf0YXqjAcG
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_e803lbbESFMDFf0YXqjAcG *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_e803lbbESFMDFf0YXqjAcG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_e803lbbESFMDFf0YXqjAcG
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

static void cgxe_mdl_update(InstanceStruct_e803lbbESFMDFf0YXqjAcG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_e803lbbESFMDFf0YXqjAcG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_e803lbbESFMDFf0YXqjAcG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_e803lbbESFMDFf0YXqjAcG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_e803lbbESFMDFf0YXqjAcG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_e803lbbESFMDFf0YXqjAcG
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
static void mdlOutputs_e803lbbESFMDFf0YXqjAcG(SimStruct *S, int_T tid)
{
  InstanceStruct_e803lbbESFMDFf0YXqjAcG *moduleInstance =
    (InstanceStruct_e803lbbESFMDFf0YXqjAcG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_e803lbbESFMDFf0YXqjAcG(SimStruct *S)
{
  InstanceStruct_e803lbbESFMDFf0YXqjAcG *moduleInstance =
    (InstanceStruct_e803lbbESFMDFf0YXqjAcG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_e803lbbESFMDFf0YXqjAcG(SimStruct *S, int_T tid)
{
  InstanceStruct_e803lbbESFMDFf0YXqjAcG *moduleInstance =
    (InstanceStruct_e803lbbESFMDFf0YXqjAcG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_e803lbbESFMDFf0YXqjAcG(SimStruct *S)
{
  InstanceStruct_e803lbbESFMDFf0YXqjAcG *moduleInstance =
    (InstanceStruct_e803lbbESFMDFf0YXqjAcG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_e803lbbESFMDFf0YXqjAcG(SimStruct *S)
{
  InstanceStruct_e803lbbESFMDFf0YXqjAcG *moduleInstance =
    (InstanceStruct_e803lbbESFMDFf0YXqjAcG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_e803lbbESFMDFf0YXqjAcG(SimStruct *S)
{
  InstanceStruct_e803lbbESFMDFf0YXqjAcG *moduleInstance =
    (InstanceStruct_e803lbbESFMDFf0YXqjAcG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_e803lbbESFMDFf0YXqjAcG(SimStruct *S)
{
  InstanceStruct_e803lbbESFMDFf0YXqjAcG *moduleInstance =
    (InstanceStruct_e803lbbESFMDFf0YXqjAcG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_e803lbbESFMDFf0YXqjAcG(SimStruct *S)
{
  InstanceStruct_e803lbbESFMDFf0YXqjAcG *moduleInstance =
    (InstanceStruct_e803lbbESFMDFf0YXqjAcG *)calloc(1, sizeof
    (InstanceStruct_e803lbbESFMDFf0YXqjAcG));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_e803lbbESFMDFf0YXqjAcG);
  ssSetmdlInitializeConditions(S, mdlInitialize_e803lbbESFMDFf0YXqjAcG);
  ssSetmdlUpdate(S, mdlUpdate_e803lbbESFMDFf0YXqjAcG);
  ssSetmdlDerivatives(S, mdlDerivatives_e803lbbESFMDFf0YXqjAcG);
  ssSetmdlTerminate(S, mdlTerminate_e803lbbESFMDFf0YXqjAcG);
  ssSetmdlEnable(S, mdlEnable_e803lbbESFMDFf0YXqjAcG);
  ssSetmdlDisable(S, mdlDisable_e803lbbESFMDFf0YXqjAcG);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_e803lbbESFMDFf0YXqjAcG(SimStruct *S)
{
}

void method_dispatcher_e803lbbESFMDFf0YXqjAcG(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_e803lbbESFMDFf0YXqjAcG(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_e803lbbESFMDFf0YXqjAcG(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: e803lbbESFMDFf0YXqjAcG.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_e803lbbESFMDFf0YXqjAcG_BuildInfoUpdate(void)
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

mxArray *cgxe_e803lbbESFMDFf0YXqjAcG_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleFunction");
  mxArray* incompatibleSymbol = mxCreateString("InverseParkTransform");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
