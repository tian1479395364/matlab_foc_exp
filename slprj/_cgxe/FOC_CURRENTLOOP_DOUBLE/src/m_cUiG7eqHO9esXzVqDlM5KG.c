/* Include files */

#include "modelInterface.h"
#include "m_cUiG7eqHO9esXzVqDlM5KG.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_cUiG7eqHO9esXzVqDlM5KG *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_cUiG7eqHO9esXzVqDlM5KG
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_cUiG7eqHO9esXzVqDlM5KG
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_cUiG7eqHO9esXzVqDlM5KG
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_cUiG7eqHO9esXzVqDlM5KG
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_cUiG7eqHO9esXzVqDlM5KG
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_cUiG7eqHO9esXzVqDlM5KG
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_cUiG7eqHO9esXzVqDlM5KG
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_cUiG7eqHO9esXzVqDlM5KG
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_cUiG7eqHO9esXzVqDlM5KG *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_cUiG7eqHO9esXzVqDlM5KG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_cUiG7eqHO9esXzVqDlM5KG
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

static void cgxe_mdl_update(InstanceStruct_cUiG7eqHO9esXzVqDlM5KG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_cUiG7eqHO9esXzVqDlM5KG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_cUiG7eqHO9esXzVqDlM5KG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_cUiG7eqHO9esXzVqDlM5KG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_cUiG7eqHO9esXzVqDlM5KG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_cUiG7eqHO9esXzVqDlM5KG
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
static void mdlOutputs_cUiG7eqHO9esXzVqDlM5KG(SimStruct *S, int_T tid)
{
  InstanceStruct_cUiG7eqHO9esXzVqDlM5KG *moduleInstance =
    (InstanceStruct_cUiG7eqHO9esXzVqDlM5KG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_cUiG7eqHO9esXzVqDlM5KG(SimStruct *S)
{
  InstanceStruct_cUiG7eqHO9esXzVqDlM5KG *moduleInstance =
    (InstanceStruct_cUiG7eqHO9esXzVqDlM5KG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_cUiG7eqHO9esXzVqDlM5KG(SimStruct *S, int_T tid)
{
  InstanceStruct_cUiG7eqHO9esXzVqDlM5KG *moduleInstance =
    (InstanceStruct_cUiG7eqHO9esXzVqDlM5KG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_cUiG7eqHO9esXzVqDlM5KG(SimStruct *S)
{
  InstanceStruct_cUiG7eqHO9esXzVqDlM5KG *moduleInstance =
    (InstanceStruct_cUiG7eqHO9esXzVqDlM5KG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_cUiG7eqHO9esXzVqDlM5KG(SimStruct *S)
{
  InstanceStruct_cUiG7eqHO9esXzVqDlM5KG *moduleInstance =
    (InstanceStruct_cUiG7eqHO9esXzVqDlM5KG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_cUiG7eqHO9esXzVqDlM5KG(SimStruct *S)
{
  InstanceStruct_cUiG7eqHO9esXzVqDlM5KG *moduleInstance =
    (InstanceStruct_cUiG7eqHO9esXzVqDlM5KG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_cUiG7eqHO9esXzVqDlM5KG(SimStruct *S)
{
  InstanceStruct_cUiG7eqHO9esXzVqDlM5KG *moduleInstance =
    (InstanceStruct_cUiG7eqHO9esXzVqDlM5KG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_cUiG7eqHO9esXzVqDlM5KG(SimStruct *S)
{
  InstanceStruct_cUiG7eqHO9esXzVqDlM5KG *moduleInstance =
    (InstanceStruct_cUiG7eqHO9esXzVqDlM5KG *)calloc(1, sizeof
    (InstanceStruct_cUiG7eqHO9esXzVqDlM5KG));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_cUiG7eqHO9esXzVqDlM5KG);
  ssSetmdlInitializeConditions(S, mdlInitialize_cUiG7eqHO9esXzVqDlM5KG);
  ssSetmdlUpdate(S, mdlUpdate_cUiG7eqHO9esXzVqDlM5KG);
  ssSetmdlDerivatives(S, mdlDerivatives_cUiG7eqHO9esXzVqDlM5KG);
  ssSetmdlTerminate(S, mdlTerminate_cUiG7eqHO9esXzVqDlM5KG);
  ssSetmdlEnable(S, mdlEnable_cUiG7eqHO9esXzVqDlM5KG);
  ssSetmdlDisable(S, mdlDisable_cUiG7eqHO9esXzVqDlM5KG);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_cUiG7eqHO9esXzVqDlM5KG(SimStruct *S)
{
}

void method_dispatcher_cUiG7eqHO9esXzVqDlM5KG(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_cUiG7eqHO9esXzVqDlM5KG(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_cUiG7eqHO9esXzVqDlM5KG(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: cUiG7eqHO9esXzVqDlM5KG.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_cUiG7eqHO9esXzVqDlM5KG_BuildInfoUpdate(void)
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

mxArray *cgxe_cUiG7eqHO9esXzVqDlM5KG_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleFunction");
  mxArray* incompatibleSymbol = mxCreateString("ClarkeTransform");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
