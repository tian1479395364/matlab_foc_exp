/* Include files */

#include "modelInterface.h"
#include "m_MaDgHuWbHkqTxwPW63XgKE.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_MaDgHuWbHkqTxwPW63XgKE *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_MaDgHuWbHkqTxwPW63XgKE
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_MaDgHuWbHkqTxwPW63XgKE
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_MaDgHuWbHkqTxwPW63XgKE
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_MaDgHuWbHkqTxwPW63XgKE
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_MaDgHuWbHkqTxwPW63XgKE
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_MaDgHuWbHkqTxwPW63XgKE
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_MaDgHuWbHkqTxwPW63XgKE
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_MaDgHuWbHkqTxwPW63XgKE
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_MaDgHuWbHkqTxwPW63XgKE *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_MaDgHuWbHkqTxwPW63XgKE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_MaDgHuWbHkqTxwPW63XgKE
  *moduleInstance)
{
  VectorAB_T b_local;
  VectorUVW_T local;
  local.s64_u = *(real_T *)&((char_T *)moduleInstance->u0)[0];
  local.s64_v = *(real_T *)&((char_T *)moduleInstance->u0)[8];
  local.s64_w = *(real_T *)&((char_T *)moduleInstance->u0)[16];
  ClarkeTransform_uQ4LZkjVPWhiGNFOCSwL0(&local, &b_local);
  *(real_T *)&((char_T *)moduleInstance->b_y0)[0] = b_local.s64_alpha;
  *(real_T *)&((char_T *)moduleInstance->b_y0)[8] = b_local.s64_beta;
}

static void cgxe_mdl_update(InstanceStruct_MaDgHuWbHkqTxwPW63XgKE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_MaDgHuWbHkqTxwPW63XgKE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_MaDgHuWbHkqTxwPW63XgKE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_MaDgHuWbHkqTxwPW63XgKE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_MaDgHuWbHkqTxwPW63XgKE
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_MaDgHuWbHkqTxwPW63XgKE
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (VectorUVW_T *)cgxertGetInputPortSignal(moduleInstance->S,
    0);
  moduleInstance->b_y0 = (VectorAB_T *)cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
}

/* CGXE Glue Code */
static void mdlOutputs_MaDgHuWbHkqTxwPW63XgKE(SimStruct *S, int_T tid)
{
  InstanceStruct_MaDgHuWbHkqTxwPW63XgKE *moduleInstance =
    (InstanceStruct_MaDgHuWbHkqTxwPW63XgKE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_MaDgHuWbHkqTxwPW63XgKE(SimStruct *S)
{
  InstanceStruct_MaDgHuWbHkqTxwPW63XgKE *moduleInstance =
    (InstanceStruct_MaDgHuWbHkqTxwPW63XgKE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_MaDgHuWbHkqTxwPW63XgKE(SimStruct *S, int_T tid)
{
  InstanceStruct_MaDgHuWbHkqTxwPW63XgKE *moduleInstance =
    (InstanceStruct_MaDgHuWbHkqTxwPW63XgKE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_MaDgHuWbHkqTxwPW63XgKE(SimStruct *S)
{
  InstanceStruct_MaDgHuWbHkqTxwPW63XgKE *moduleInstance =
    (InstanceStruct_MaDgHuWbHkqTxwPW63XgKE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_MaDgHuWbHkqTxwPW63XgKE(SimStruct *S)
{
  InstanceStruct_MaDgHuWbHkqTxwPW63XgKE *moduleInstance =
    (InstanceStruct_MaDgHuWbHkqTxwPW63XgKE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_MaDgHuWbHkqTxwPW63XgKE(SimStruct *S)
{
  InstanceStruct_MaDgHuWbHkqTxwPW63XgKE *moduleInstance =
    (InstanceStruct_MaDgHuWbHkqTxwPW63XgKE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_MaDgHuWbHkqTxwPW63XgKE(SimStruct *S)
{
  InstanceStruct_MaDgHuWbHkqTxwPW63XgKE *moduleInstance =
    (InstanceStruct_MaDgHuWbHkqTxwPW63XgKE *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_MaDgHuWbHkqTxwPW63XgKE(SimStruct *S)
{
  InstanceStruct_MaDgHuWbHkqTxwPW63XgKE *moduleInstance =
    (InstanceStruct_MaDgHuWbHkqTxwPW63XgKE *)calloc(1, sizeof
    (InstanceStruct_MaDgHuWbHkqTxwPW63XgKE));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_MaDgHuWbHkqTxwPW63XgKE);
  ssSetmdlInitializeConditions(S, mdlInitialize_MaDgHuWbHkqTxwPW63XgKE);
  ssSetmdlUpdate(S, mdlUpdate_MaDgHuWbHkqTxwPW63XgKE);
  ssSetmdlDerivatives(S, mdlDerivatives_MaDgHuWbHkqTxwPW63XgKE);
  ssSetmdlTerminate(S, mdlTerminate_MaDgHuWbHkqTxwPW63XgKE);
  ssSetmdlEnable(S, mdlEnable_MaDgHuWbHkqTxwPW63XgKE);
  ssSetmdlDisable(S, mdlDisable_MaDgHuWbHkqTxwPW63XgKE);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_MaDgHuWbHkqTxwPW63XgKE(SimStruct *S)
{
}

void method_dispatcher_MaDgHuWbHkqTxwPW63XgKE(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_MaDgHuWbHkqTxwPW63XgKE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_MaDgHuWbHkqTxwPW63XgKE(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: MaDgHuWbHkqTxwPW63XgKE.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_MaDgHuWbHkqTxwPW63XgKE_BuildInfoUpdate(void)
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

mxArray *cgxe_MaDgHuWbHkqTxwPW63XgKE_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleFunction");
  mxArray* incompatibleSymbol = mxCreateString("ClarkeTransform");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
