/* Include files */

#include "modelInterface.h"
#include "m_jCy4bKIhY7pemDeJFcrazF.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_jCy4bKIhY7pemDeJFcrazF *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_jCy4bKIhY7pemDeJFcrazF
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_jCy4bKIhY7pemDeJFcrazF
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_jCy4bKIhY7pemDeJFcrazF
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_jCy4bKIhY7pemDeJFcrazF
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_jCy4bKIhY7pemDeJFcrazF
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_jCy4bKIhY7pemDeJFcrazF
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_jCy4bKIhY7pemDeJFcrazF
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_jCy4bKIhY7pemDeJFcrazF
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_jCy4bKIhY7pemDeJFcrazF *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_jCy4bKIhY7pemDeJFcrazF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_jCy4bKIhY7pemDeJFcrazF
  *moduleInstance)
{
  VectorUVW_T local;
  local.s64_u = *(real_T *)&((char_T *)moduleInstance->u0)[0];
  local.s64_v = *(real_T *)&((char_T *)moduleInstance->u0)[8];
  local.s64_w = *(real_T *)&((char_T *)moduleInstance->u0)[16];
  CalcZeroSequenceVoltage_uQ4LZkjVPWhiGNFOCSwL0(&local, moduleInstance->b_y0);
}

static void cgxe_mdl_update(InstanceStruct_jCy4bKIhY7pemDeJFcrazF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_jCy4bKIhY7pemDeJFcrazF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_jCy4bKIhY7pemDeJFcrazF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_jCy4bKIhY7pemDeJFcrazF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_jCy4bKIhY7pemDeJFcrazF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_jCy4bKIhY7pemDeJFcrazF
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (VectorUVW_T *)cgxertGetInputPortSignal(moduleInstance->S,
    0);
  moduleInstance->b_y0 = (real_T *)cgxertGetOutputPortSignal(moduleInstance->S,
    0);
}

/* CGXE Glue Code */
static void mdlOutputs_jCy4bKIhY7pemDeJFcrazF(SimStruct *S, int_T tid)
{
  InstanceStruct_jCy4bKIhY7pemDeJFcrazF *moduleInstance =
    (InstanceStruct_jCy4bKIhY7pemDeJFcrazF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_jCy4bKIhY7pemDeJFcrazF(SimStruct *S)
{
  InstanceStruct_jCy4bKIhY7pemDeJFcrazF *moduleInstance =
    (InstanceStruct_jCy4bKIhY7pemDeJFcrazF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_jCy4bKIhY7pemDeJFcrazF(SimStruct *S, int_T tid)
{
  InstanceStruct_jCy4bKIhY7pemDeJFcrazF *moduleInstance =
    (InstanceStruct_jCy4bKIhY7pemDeJFcrazF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_jCy4bKIhY7pemDeJFcrazF(SimStruct *S)
{
  InstanceStruct_jCy4bKIhY7pemDeJFcrazF *moduleInstance =
    (InstanceStruct_jCy4bKIhY7pemDeJFcrazF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_jCy4bKIhY7pemDeJFcrazF(SimStruct *S)
{
  InstanceStruct_jCy4bKIhY7pemDeJFcrazF *moduleInstance =
    (InstanceStruct_jCy4bKIhY7pemDeJFcrazF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_jCy4bKIhY7pemDeJFcrazF(SimStruct *S)
{
  InstanceStruct_jCy4bKIhY7pemDeJFcrazF *moduleInstance =
    (InstanceStruct_jCy4bKIhY7pemDeJFcrazF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_jCy4bKIhY7pemDeJFcrazF(SimStruct *S)
{
  InstanceStruct_jCy4bKIhY7pemDeJFcrazF *moduleInstance =
    (InstanceStruct_jCy4bKIhY7pemDeJFcrazF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_jCy4bKIhY7pemDeJFcrazF(SimStruct *S)
{
  InstanceStruct_jCy4bKIhY7pemDeJFcrazF *moduleInstance =
    (InstanceStruct_jCy4bKIhY7pemDeJFcrazF *)calloc(1, sizeof
    (InstanceStruct_jCy4bKIhY7pemDeJFcrazF));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_jCy4bKIhY7pemDeJFcrazF);
  ssSetmdlInitializeConditions(S, mdlInitialize_jCy4bKIhY7pemDeJFcrazF);
  ssSetmdlUpdate(S, mdlUpdate_jCy4bKIhY7pemDeJFcrazF);
  ssSetmdlDerivatives(S, mdlDerivatives_jCy4bKIhY7pemDeJFcrazF);
  ssSetmdlTerminate(S, mdlTerminate_jCy4bKIhY7pemDeJFcrazF);
  ssSetmdlEnable(S, mdlEnable_jCy4bKIhY7pemDeJFcrazF);
  ssSetmdlDisable(S, mdlDisable_jCy4bKIhY7pemDeJFcrazF);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_jCy4bKIhY7pemDeJFcrazF(SimStruct *S)
{
}

void method_dispatcher_jCy4bKIhY7pemDeJFcrazF(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_jCy4bKIhY7pemDeJFcrazF(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_jCy4bKIhY7pemDeJFcrazF(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: jCy4bKIhY7pemDeJFcrazF.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_jCy4bKIhY7pemDeJFcrazF_BuildInfoUpdate(void)
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

mxArray *cgxe_jCy4bKIhY7pemDeJFcrazF_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleFunction");
  mxArray* incompatibleSymbol = mxCreateString("CalcZeroSequenceVoltage");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
