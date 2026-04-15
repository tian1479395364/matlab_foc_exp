/* Include files */

#include "modelInterface.h"
#include "m_a4luxM7sjft7hior8qnEQG.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_a4luxM7sjft7hior8qnEQG *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_a4luxM7sjft7hior8qnEQG
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_a4luxM7sjft7hior8qnEQG
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_a4luxM7sjft7hior8qnEQG
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_a4luxM7sjft7hior8qnEQG
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_a4luxM7sjft7hior8qnEQG
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_a4luxM7sjft7hior8qnEQG
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_a4luxM7sjft7hior8qnEQG
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_a4luxM7sjft7hior8qnEQG
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_a4luxM7sjft7hior8qnEQG *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_a4luxM7sjft7hior8qnEQG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_a4luxM7sjft7hior8qnEQG
  *moduleInstance)
{
  VectorUVW_T local;
  local.s64_u = *(real_T *)&((char_T *)moduleInstance->u1)[0];
  local.s64_v = *(real_T *)&((char_T *)moduleInstance->u1)[8];
  local.s64_w = *(real_T *)&((char_T *)moduleInstance->u1)[16];
  SVPWM_CalcDutyCycle_uQ4LZkjVPWhiGNFOCSwL0(moduleInstance->u0, &local,
    *moduleInstance->u2, &(*moduleInstance->b_y0)[0]);
}

static void cgxe_mdl_update(InstanceStruct_a4luxM7sjft7hior8qnEQG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_a4luxM7sjft7hior8qnEQG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_a4luxM7sjft7hior8qnEQG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_a4luxM7sjft7hior8qnEQG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_a4luxM7sjft7hior8qnEQG
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_a4luxM7sjft7hior8qnEQG
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 0);
  moduleInstance->u1 = (VectorUVW_T *)cgxertGetInputPortSignal(moduleInstance->S,
    1);
  moduleInstance->u2 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 2);
  moduleInstance->b_y0 = (real_T (*)[3])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
}

/* CGXE Glue Code */
static void mdlOutputs_a4luxM7sjft7hior8qnEQG(SimStruct *S, int_T tid)
{
  InstanceStruct_a4luxM7sjft7hior8qnEQG *moduleInstance =
    (InstanceStruct_a4luxM7sjft7hior8qnEQG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_a4luxM7sjft7hior8qnEQG(SimStruct *S)
{
  InstanceStruct_a4luxM7sjft7hior8qnEQG *moduleInstance =
    (InstanceStruct_a4luxM7sjft7hior8qnEQG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_a4luxM7sjft7hior8qnEQG(SimStruct *S, int_T tid)
{
  InstanceStruct_a4luxM7sjft7hior8qnEQG *moduleInstance =
    (InstanceStruct_a4luxM7sjft7hior8qnEQG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_a4luxM7sjft7hior8qnEQG(SimStruct *S)
{
  InstanceStruct_a4luxM7sjft7hior8qnEQG *moduleInstance =
    (InstanceStruct_a4luxM7sjft7hior8qnEQG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_a4luxM7sjft7hior8qnEQG(SimStruct *S)
{
  InstanceStruct_a4luxM7sjft7hior8qnEQG *moduleInstance =
    (InstanceStruct_a4luxM7sjft7hior8qnEQG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_a4luxM7sjft7hior8qnEQG(SimStruct *S)
{
  InstanceStruct_a4luxM7sjft7hior8qnEQG *moduleInstance =
    (InstanceStruct_a4luxM7sjft7hior8qnEQG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_a4luxM7sjft7hior8qnEQG(SimStruct *S)
{
  InstanceStruct_a4luxM7sjft7hior8qnEQG *moduleInstance =
    (InstanceStruct_a4luxM7sjft7hior8qnEQG *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_a4luxM7sjft7hior8qnEQG(SimStruct *S)
{
  InstanceStruct_a4luxM7sjft7hior8qnEQG *moduleInstance =
    (InstanceStruct_a4luxM7sjft7hior8qnEQG *)calloc(1, sizeof
    (InstanceStruct_a4luxM7sjft7hior8qnEQG));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_a4luxM7sjft7hior8qnEQG);
  ssSetmdlInitializeConditions(S, mdlInitialize_a4luxM7sjft7hior8qnEQG);
  ssSetmdlUpdate(S, mdlUpdate_a4luxM7sjft7hior8qnEQG);
  ssSetmdlDerivatives(S, mdlDerivatives_a4luxM7sjft7hior8qnEQG);
  ssSetmdlTerminate(S, mdlTerminate_a4luxM7sjft7hior8qnEQG);
  ssSetmdlEnable(S, mdlEnable_a4luxM7sjft7hior8qnEQG);
  ssSetmdlDisable(S, mdlDisable_a4luxM7sjft7hior8qnEQG);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_a4luxM7sjft7hior8qnEQG(SimStruct *S)
{
}

void method_dispatcher_a4luxM7sjft7hior8qnEQG(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_a4luxM7sjft7hior8qnEQG(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_a4luxM7sjft7hior8qnEQG(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: a4luxM7sjft7hior8qnEQG.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_a4luxM7sjft7hior8qnEQG_BuildInfoUpdate(void)
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

mxArray *cgxe_a4luxM7sjft7hior8qnEQG_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleFunction");
  mxArray* incompatibleSymbol = mxCreateString("SVPWM_CalcDutyCycle");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
