/* Include files */

#include "modelInterface.h"
#include "m_th8rE7raOlxcwWhukpab2F.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_th8rE7raOlxcwWhukpab2F *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_th8rE7raOlxcwWhukpab2F
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_th8rE7raOlxcwWhukpab2F
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_th8rE7raOlxcwWhukpab2F
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_th8rE7raOlxcwWhukpab2F
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_th8rE7raOlxcwWhukpab2F
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_th8rE7raOlxcwWhukpab2F
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_th8rE7raOlxcwWhukpab2F
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_th8rE7raOlxcwWhukpab2F
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_th8rE7raOlxcwWhukpab2F *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_th8rE7raOlxcwWhukpab2F
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_th8rE7raOlxcwWhukpab2F
  *moduleInstance)
{
  SinCosInput local;
  local.m_sin = *(real_T *)&((char_T *)moduleInstance->u2)[0];
  local.m_cos = *(real_T *)&((char_T *)moduleInstance->u2)[8];
  *moduleInstance->b_y0 = *moduleInstance->u3;
  *moduleInstance->b_y1 = *moduleInstance->u4;
  ParkTransform_Qn5ICprfZEgXdsPGYmMeNC(*moduleInstance->u0, *moduleInstance->u1,
    &local, moduleInstance->b_y0, moduleInstance->b_y1);
}

static void cgxe_mdl_update(InstanceStruct_th8rE7raOlxcwWhukpab2F
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_th8rE7raOlxcwWhukpab2F
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_th8rE7raOlxcwWhukpab2F
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_th8rE7raOlxcwWhukpab2F
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_th8rE7raOlxcwWhukpab2F
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_th8rE7raOlxcwWhukpab2F
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 0);
  moduleInstance->u1 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 1);
  moduleInstance->u2 = (SinCosInput *)cgxertGetInputPortSignal(moduleInstance->S,
    2);
  moduleInstance->u3 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 3);
  moduleInstance->u4 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 4);
  moduleInstance->b_y0 = (real_T *)cgxertGetOutputPortSignal(moduleInstance->S,
    0);
  moduleInstance->b_y1 = (real_T *)cgxertGetOutputPortSignal(moduleInstance->S,
    1);
}

/* CGXE Glue Code */
static void mdlOutputs_th8rE7raOlxcwWhukpab2F(SimStruct *S, int_T tid)
{
  InstanceStruct_th8rE7raOlxcwWhukpab2F *moduleInstance =
    (InstanceStruct_th8rE7raOlxcwWhukpab2F *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_th8rE7raOlxcwWhukpab2F(SimStruct *S)
{
  InstanceStruct_th8rE7raOlxcwWhukpab2F *moduleInstance =
    (InstanceStruct_th8rE7raOlxcwWhukpab2F *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_th8rE7raOlxcwWhukpab2F(SimStruct *S, int_T tid)
{
  InstanceStruct_th8rE7raOlxcwWhukpab2F *moduleInstance =
    (InstanceStruct_th8rE7raOlxcwWhukpab2F *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_th8rE7raOlxcwWhukpab2F(SimStruct *S)
{
  InstanceStruct_th8rE7raOlxcwWhukpab2F *moduleInstance =
    (InstanceStruct_th8rE7raOlxcwWhukpab2F *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_th8rE7raOlxcwWhukpab2F(SimStruct *S)
{
  InstanceStruct_th8rE7raOlxcwWhukpab2F *moduleInstance =
    (InstanceStruct_th8rE7raOlxcwWhukpab2F *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_th8rE7raOlxcwWhukpab2F(SimStruct *S)
{
  InstanceStruct_th8rE7raOlxcwWhukpab2F *moduleInstance =
    (InstanceStruct_th8rE7raOlxcwWhukpab2F *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_th8rE7raOlxcwWhukpab2F(SimStruct *S)
{
  InstanceStruct_th8rE7raOlxcwWhukpab2F *moduleInstance =
    (InstanceStruct_th8rE7raOlxcwWhukpab2F *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_th8rE7raOlxcwWhukpab2F(SimStruct *S)
{
  InstanceStruct_th8rE7raOlxcwWhukpab2F *moduleInstance =
    (InstanceStruct_th8rE7raOlxcwWhukpab2F *)calloc(1, sizeof
    (InstanceStruct_th8rE7raOlxcwWhukpab2F));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_th8rE7raOlxcwWhukpab2F);
  ssSetmdlInitializeConditions(S, mdlInitialize_th8rE7raOlxcwWhukpab2F);
  ssSetmdlUpdate(S, mdlUpdate_th8rE7raOlxcwWhukpab2F);
  ssSetmdlDerivatives(S, mdlDerivatives_th8rE7raOlxcwWhukpab2F);
  ssSetmdlTerminate(S, mdlTerminate_th8rE7raOlxcwWhukpab2F);
  ssSetmdlEnable(S, mdlEnable_th8rE7raOlxcwWhukpab2F);
  ssSetmdlDisable(S, mdlDisable_th8rE7raOlxcwWhukpab2F);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_th8rE7raOlxcwWhukpab2F(SimStruct *S)
{
}

void method_dispatcher_th8rE7raOlxcwWhukpab2F(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_th8rE7raOlxcwWhukpab2F(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_th8rE7raOlxcwWhukpab2F(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: th8rE7raOlxcwWhukpab2F.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_th8rE7raOlxcwWhukpab2F_BuildInfoUpdate(void)
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

mxArray *cgxe_th8rE7raOlxcwWhukpab2F_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleFunction");
  mxArray* incompatibleSymbol = mxCreateString("ParkTransform");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
