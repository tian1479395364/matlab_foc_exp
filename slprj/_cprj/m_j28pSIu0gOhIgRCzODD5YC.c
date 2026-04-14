/* Include files */

#include "modelInterface.h"
#include "m_j28pSIu0gOhIgRCzODD5YC.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_j28pSIu0gOhIgRCzODD5YC *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_j28pSIu0gOhIgRCzODD5YC
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_j28pSIu0gOhIgRCzODD5YC
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_j28pSIu0gOhIgRCzODD5YC
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_j28pSIu0gOhIgRCzODD5YC
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_j28pSIu0gOhIgRCzODD5YC
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_j28pSIu0gOhIgRCzODD5YC
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_j28pSIu0gOhIgRCzODD5YC
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_j28pSIu0gOhIgRCzODD5YC
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_j28pSIu0gOhIgRCzODD5YC *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_j28pSIu0gOhIgRCzODD5YC
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_j28pSIu0gOhIgRCzODD5YC
  *moduleInstance)
{
  SinCosInput local;
  local.m_sin = *(real_T *)&((char_T *)moduleInstance->u2)[0];
  local.m_cos = *(real_T *)&((char_T *)moduleInstance->u2)[8];
  ParkTransform_Qn5ICprfZEgXdsPGYmMeNC(*moduleInstance->u0, *moduleInstance->u1,
    &local, moduleInstance->b_y0, moduleInstance->b_y1);
}

static void cgxe_mdl_update(InstanceStruct_j28pSIu0gOhIgRCzODD5YC
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_j28pSIu0gOhIgRCzODD5YC
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_j28pSIu0gOhIgRCzODD5YC
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_j28pSIu0gOhIgRCzODD5YC
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_j28pSIu0gOhIgRCzODD5YC
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_j28pSIu0gOhIgRCzODD5YC
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 0);
  moduleInstance->u1 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 1);
  moduleInstance->u2 = (SinCosInput *)cgxertGetInputPortSignal(moduleInstance->S,
    2);
  moduleInstance->b_y0 = (real_T *)cgxertGetOutputPortSignal(moduleInstance->S,
    0);
  moduleInstance->b_y1 = (real_T *)cgxertGetOutputPortSignal(moduleInstance->S,
    1);
}

/* CGXE Glue Code */
static void mdlOutputs_j28pSIu0gOhIgRCzODD5YC(SimStruct *S, int_T tid)
{
  InstanceStruct_j28pSIu0gOhIgRCzODD5YC *moduleInstance =
    (InstanceStruct_j28pSIu0gOhIgRCzODD5YC *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_j28pSIu0gOhIgRCzODD5YC(SimStruct *S)
{
  InstanceStruct_j28pSIu0gOhIgRCzODD5YC *moduleInstance =
    (InstanceStruct_j28pSIu0gOhIgRCzODD5YC *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_j28pSIu0gOhIgRCzODD5YC(SimStruct *S, int_T tid)
{
  InstanceStruct_j28pSIu0gOhIgRCzODD5YC *moduleInstance =
    (InstanceStruct_j28pSIu0gOhIgRCzODD5YC *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_j28pSIu0gOhIgRCzODD5YC(SimStruct *S)
{
  InstanceStruct_j28pSIu0gOhIgRCzODD5YC *moduleInstance =
    (InstanceStruct_j28pSIu0gOhIgRCzODD5YC *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_j28pSIu0gOhIgRCzODD5YC(SimStruct *S)
{
  InstanceStruct_j28pSIu0gOhIgRCzODD5YC *moduleInstance =
    (InstanceStruct_j28pSIu0gOhIgRCzODD5YC *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_j28pSIu0gOhIgRCzODD5YC(SimStruct *S)
{
  InstanceStruct_j28pSIu0gOhIgRCzODD5YC *moduleInstance =
    (InstanceStruct_j28pSIu0gOhIgRCzODD5YC *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_j28pSIu0gOhIgRCzODD5YC(SimStruct *S)
{
  InstanceStruct_j28pSIu0gOhIgRCzODD5YC *moduleInstance =
    (InstanceStruct_j28pSIu0gOhIgRCzODD5YC *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_j28pSIu0gOhIgRCzODD5YC(SimStruct *S)
{
  InstanceStruct_j28pSIu0gOhIgRCzODD5YC *moduleInstance =
    (InstanceStruct_j28pSIu0gOhIgRCzODD5YC *)calloc(1, sizeof
    (InstanceStruct_j28pSIu0gOhIgRCzODD5YC));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_j28pSIu0gOhIgRCzODD5YC);
  ssSetmdlInitializeConditions(S, mdlInitialize_j28pSIu0gOhIgRCzODD5YC);
  ssSetmdlUpdate(S, mdlUpdate_j28pSIu0gOhIgRCzODD5YC);
  ssSetmdlDerivatives(S, mdlDerivatives_j28pSIu0gOhIgRCzODD5YC);
  ssSetmdlTerminate(S, mdlTerminate_j28pSIu0gOhIgRCzODD5YC);
  ssSetmdlEnable(S, mdlEnable_j28pSIu0gOhIgRCzODD5YC);
  ssSetmdlDisable(S, mdlDisable_j28pSIu0gOhIgRCzODD5YC);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_j28pSIu0gOhIgRCzODD5YC(SimStruct *S)
{
}

void method_dispatcher_j28pSIu0gOhIgRCzODD5YC(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_j28pSIu0gOhIgRCzODD5YC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_j28pSIu0gOhIgRCzODD5YC(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: j28pSIu0gOhIgRCzODD5YC.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_j28pSIu0gOhIgRCzODD5YC_BuildInfoUpdate(void)
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

mxArray *cgxe_j28pSIu0gOhIgRCzODD5YC_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleFunction");
  mxArray* incompatibleSymbol = mxCreateString("ParkTransform");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
