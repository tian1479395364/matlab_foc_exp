/* Include files */

#include "modelInterface.h"
#include "m_81c06mwKmM3M9WFiPBm4GD.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_81c06mwKmM3M9WFiPBm4GD *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_81c06mwKmM3M9WFiPBm4GD
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_81c06mwKmM3M9WFiPBm4GD
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_81c06mwKmM3M9WFiPBm4GD
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_81c06mwKmM3M9WFiPBm4GD
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_81c06mwKmM3M9WFiPBm4GD
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_81c06mwKmM3M9WFiPBm4GD
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_81c06mwKmM3M9WFiPBm4GD
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_81c06mwKmM3M9WFiPBm4GD
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_81c06mwKmM3M9WFiPBm4GD *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_81c06mwKmM3M9WFiPBm4GD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_81c06mwKmM3M9WFiPBm4GD
  *moduleInstance)
{
  ClarkeInput local;
  local.ia = *(real_T *)&((char_T *)moduleInstance->u0)[0];
  local.ib = *(real_T *)&((char_T *)moduleInstance->u0)[8];
  local.ic = *(real_T *)&((char_T *)moduleInstance->u0)[16];
  ClarkeTransform_Qn5ICprfZEgXdsPGYmMeNC(&local, moduleInstance->b_y0,
    moduleInstance->b_y1);
}

static void cgxe_mdl_update(InstanceStruct_81c06mwKmM3M9WFiPBm4GD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_81c06mwKmM3M9WFiPBm4GD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_81c06mwKmM3M9WFiPBm4GD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_81c06mwKmM3M9WFiPBm4GD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_81c06mwKmM3M9WFiPBm4GD
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_81c06mwKmM3M9WFiPBm4GD
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (ClarkeInput *)cgxertGetInputPortSignal(moduleInstance->S,
    0);
  moduleInstance->b_y0 = (real_T *)cgxertGetOutputPortSignal(moduleInstance->S,
    0);
  moduleInstance->b_y1 = (real_T *)cgxertGetOutputPortSignal(moduleInstance->S,
    1);
}

/* CGXE Glue Code */
static void mdlOutputs_81c06mwKmM3M9WFiPBm4GD(SimStruct *S, int_T tid)
{
  InstanceStruct_81c06mwKmM3M9WFiPBm4GD *moduleInstance =
    (InstanceStruct_81c06mwKmM3M9WFiPBm4GD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_81c06mwKmM3M9WFiPBm4GD(SimStruct *S)
{
  InstanceStruct_81c06mwKmM3M9WFiPBm4GD *moduleInstance =
    (InstanceStruct_81c06mwKmM3M9WFiPBm4GD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_81c06mwKmM3M9WFiPBm4GD(SimStruct *S, int_T tid)
{
  InstanceStruct_81c06mwKmM3M9WFiPBm4GD *moduleInstance =
    (InstanceStruct_81c06mwKmM3M9WFiPBm4GD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_81c06mwKmM3M9WFiPBm4GD(SimStruct *S)
{
  InstanceStruct_81c06mwKmM3M9WFiPBm4GD *moduleInstance =
    (InstanceStruct_81c06mwKmM3M9WFiPBm4GD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_81c06mwKmM3M9WFiPBm4GD(SimStruct *S)
{
  InstanceStruct_81c06mwKmM3M9WFiPBm4GD *moduleInstance =
    (InstanceStruct_81c06mwKmM3M9WFiPBm4GD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_81c06mwKmM3M9WFiPBm4GD(SimStruct *S)
{
  InstanceStruct_81c06mwKmM3M9WFiPBm4GD *moduleInstance =
    (InstanceStruct_81c06mwKmM3M9WFiPBm4GD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_81c06mwKmM3M9WFiPBm4GD(SimStruct *S)
{
  InstanceStruct_81c06mwKmM3M9WFiPBm4GD *moduleInstance =
    (InstanceStruct_81c06mwKmM3M9WFiPBm4GD *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_81c06mwKmM3M9WFiPBm4GD(SimStruct *S)
{
  InstanceStruct_81c06mwKmM3M9WFiPBm4GD *moduleInstance =
    (InstanceStruct_81c06mwKmM3M9WFiPBm4GD *)calloc(1, sizeof
    (InstanceStruct_81c06mwKmM3M9WFiPBm4GD));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_81c06mwKmM3M9WFiPBm4GD);
  ssSetmdlInitializeConditions(S, mdlInitialize_81c06mwKmM3M9WFiPBm4GD);
  ssSetmdlUpdate(S, mdlUpdate_81c06mwKmM3M9WFiPBm4GD);
  ssSetmdlDerivatives(S, mdlDerivatives_81c06mwKmM3M9WFiPBm4GD);
  ssSetmdlTerminate(S, mdlTerminate_81c06mwKmM3M9WFiPBm4GD);
  ssSetmdlEnable(S, mdlEnable_81c06mwKmM3M9WFiPBm4GD);
  ssSetmdlDisable(S, mdlDisable_81c06mwKmM3M9WFiPBm4GD);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_81c06mwKmM3M9WFiPBm4GD(SimStruct *S)
{
}

void method_dispatcher_81c06mwKmM3M9WFiPBm4GD(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_81c06mwKmM3M9WFiPBm4GD(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_81c06mwKmM3M9WFiPBm4GD(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: 81c06mwKmM3M9WFiPBm4GD.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_81c06mwKmM3M9WFiPBm4GD_BuildInfoUpdate(void)
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

mxArray *cgxe_81c06mwKmM3M9WFiPBm4GD_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleFunction");
  mxArray* incompatibleSymbol = mxCreateString("ClarkeTransform");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
