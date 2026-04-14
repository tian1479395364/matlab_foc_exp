/* Include files */

#include "modelInterface.h"
#include "m_tNEsk2P6znbBW5oV8mFkpD.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_tNEsk2P6znbBW5oV8mFkpD *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_tNEsk2P6znbBW5oV8mFkpD
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_tNEsk2P6znbBW5oV8mFkpD
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_tNEsk2P6znbBW5oV8mFkpD
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_tNEsk2P6znbBW5oV8mFkpD
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_tNEsk2P6znbBW5oV8mFkpD
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_tNEsk2P6znbBW5oV8mFkpD
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_tNEsk2P6znbBW5oV8mFkpD
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_tNEsk2P6znbBW5oV8mFkpD
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_tNEsk2P6znbBW5oV8mFkpD *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_tNEsk2P6znbBW5oV8mFkpD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_tNEsk2P6znbBW5oV8mFkpD
  *moduleInstance)
{
  SinCosInput local;
  local.m_sin = *(real_T *)&((char_T *)moduleInstance->u2)[0];
  local.m_cos = *(real_T *)&((char_T *)moduleInstance->u2)[8];
  ParkTransform_UzqYPFkYz5CpfIuUN0S0WG(*moduleInstance->u0, *moduleInstance->u1,
    &local, moduleInstance->b_y0, moduleInstance->b_y1);
}

static void cgxe_mdl_update(InstanceStruct_tNEsk2P6znbBW5oV8mFkpD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_tNEsk2P6znbBW5oV8mFkpD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_tNEsk2P6znbBW5oV8mFkpD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_tNEsk2P6znbBW5oV8mFkpD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_tNEsk2P6znbBW5oV8mFkpD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_tNEsk2P6znbBW5oV8mFkpD
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
static void mdlOutputs_tNEsk2P6znbBW5oV8mFkpD(SimStruct *S, int_T tid)
{
  InstanceStruct_tNEsk2P6znbBW5oV8mFkpD *moduleInstance =
    (InstanceStruct_tNEsk2P6znbBW5oV8mFkpD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_tNEsk2P6znbBW5oV8mFkpD(SimStruct *S)
{
  InstanceStruct_tNEsk2P6znbBW5oV8mFkpD *moduleInstance =
    (InstanceStruct_tNEsk2P6znbBW5oV8mFkpD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_tNEsk2P6znbBW5oV8mFkpD(SimStruct *S, int_T tid)
{
  InstanceStruct_tNEsk2P6znbBW5oV8mFkpD *moduleInstance =
    (InstanceStruct_tNEsk2P6znbBW5oV8mFkpD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_tNEsk2P6znbBW5oV8mFkpD(SimStruct *S)
{
  InstanceStruct_tNEsk2P6znbBW5oV8mFkpD *moduleInstance =
    (InstanceStruct_tNEsk2P6znbBW5oV8mFkpD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_tNEsk2P6znbBW5oV8mFkpD(SimStruct *S)
{
  InstanceStruct_tNEsk2P6znbBW5oV8mFkpD *moduleInstance =
    (InstanceStruct_tNEsk2P6znbBW5oV8mFkpD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_tNEsk2P6znbBW5oV8mFkpD(SimStruct *S)
{
  InstanceStruct_tNEsk2P6znbBW5oV8mFkpD *moduleInstance =
    (InstanceStruct_tNEsk2P6znbBW5oV8mFkpD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_tNEsk2P6znbBW5oV8mFkpD(SimStruct *S)
{
  InstanceStruct_tNEsk2P6znbBW5oV8mFkpD *moduleInstance =
    (InstanceStruct_tNEsk2P6znbBW5oV8mFkpD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_tNEsk2P6znbBW5oV8mFkpD(SimStruct *S)
{
  InstanceStruct_tNEsk2P6znbBW5oV8mFkpD *moduleInstance =
    (InstanceStruct_tNEsk2P6znbBW5oV8mFkpD *)calloc(1, sizeof
    (InstanceStruct_tNEsk2P6znbBW5oV8mFkpD));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_tNEsk2P6znbBW5oV8mFkpD);
  ssSetmdlInitializeConditions(S, mdlInitialize_tNEsk2P6znbBW5oV8mFkpD);
  ssSetmdlUpdate(S, mdlUpdate_tNEsk2P6znbBW5oV8mFkpD);
  ssSetmdlDerivatives(S, mdlDerivatives_tNEsk2P6znbBW5oV8mFkpD);
  ssSetmdlTerminate(S, mdlTerminate_tNEsk2P6znbBW5oV8mFkpD);
  ssSetmdlEnable(S, mdlEnable_tNEsk2P6znbBW5oV8mFkpD);
  ssSetmdlDisable(S, mdlDisable_tNEsk2P6znbBW5oV8mFkpD);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_tNEsk2P6znbBW5oV8mFkpD(SimStruct *S)
{
}

void method_dispatcher_tNEsk2P6znbBW5oV8mFkpD(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_tNEsk2P6znbBW5oV8mFkpD(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_tNEsk2P6znbBW5oV8mFkpD(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: tNEsk2P6znbBW5oV8mFkpD.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_tNEsk2P6znbBW5oV8mFkpD_BuildInfoUpdate(void)
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

mxArray *cgxe_tNEsk2P6znbBW5oV8mFkpD_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleFunction");
  mxArray* incompatibleSymbol = mxCreateString("ParkTransform");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
