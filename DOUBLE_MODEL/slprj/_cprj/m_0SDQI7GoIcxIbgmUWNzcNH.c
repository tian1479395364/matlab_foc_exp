/* Include files */

#include "modelInterface.h"
#include "m_0SDQI7GoIcxIbgmUWNzcNH.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH
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

static void cgxe_mdl_update(InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH
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
static void mdlOutputs_0SDQI7GoIcxIbgmUWNzcNH(SimStruct *S, int_T tid)
{
  InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH *moduleInstance =
    (InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_0SDQI7GoIcxIbgmUWNzcNH(SimStruct *S)
{
  InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH *moduleInstance =
    (InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_0SDQI7GoIcxIbgmUWNzcNH(SimStruct *S, int_T tid)
{
  InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH *moduleInstance =
    (InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_0SDQI7GoIcxIbgmUWNzcNH(SimStruct *S)
{
  InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH *moduleInstance =
    (InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_0SDQI7GoIcxIbgmUWNzcNH(SimStruct *S)
{
  InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH *moduleInstance =
    (InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_0SDQI7GoIcxIbgmUWNzcNH(SimStruct *S)
{
  InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH *moduleInstance =
    (InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_0SDQI7GoIcxIbgmUWNzcNH(SimStruct *S)
{
  InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH *moduleInstance =
    (InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_0SDQI7GoIcxIbgmUWNzcNH(SimStruct *S)
{
  InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH *moduleInstance =
    (InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH *)calloc(1, sizeof
    (InstanceStruct_0SDQI7GoIcxIbgmUWNzcNH));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_0SDQI7GoIcxIbgmUWNzcNH);
  ssSetmdlInitializeConditions(S, mdlInitialize_0SDQI7GoIcxIbgmUWNzcNH);
  ssSetmdlUpdate(S, mdlUpdate_0SDQI7GoIcxIbgmUWNzcNH);
  ssSetmdlDerivatives(S, mdlDerivatives_0SDQI7GoIcxIbgmUWNzcNH);
  ssSetmdlTerminate(S, mdlTerminate_0SDQI7GoIcxIbgmUWNzcNH);
  ssSetmdlEnable(S, mdlEnable_0SDQI7GoIcxIbgmUWNzcNH);
  ssSetmdlDisable(S, mdlDisable_0SDQI7GoIcxIbgmUWNzcNH);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_0SDQI7GoIcxIbgmUWNzcNH(SimStruct *S)
{
}

void method_dispatcher_0SDQI7GoIcxIbgmUWNzcNH(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_0SDQI7GoIcxIbgmUWNzcNH(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_0SDQI7GoIcxIbgmUWNzcNH(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: 0SDQI7GoIcxIbgmUWNzcNH.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_0SDQI7GoIcxIbgmUWNzcNH_BuildInfoUpdate(void)
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

mxArray *cgxe_0SDQI7GoIcxIbgmUWNzcNH_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleFunction");
  mxArray* incompatibleSymbol = mxCreateString("InverseParkTransform");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
