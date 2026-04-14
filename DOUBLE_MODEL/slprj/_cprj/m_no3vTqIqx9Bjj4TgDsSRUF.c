/* Include files */

#include "modelInterface.h"
#include "m_no3vTqIqx9Bjj4TgDsSRUF.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF
  *moduleInstance)
{
  VectorAB_T local;
  VectorDQ_T b_local;
  local.s64_alpha = *(real_T *)&((char_T *)moduleInstance->u0)[0];
  local.s64_beta = *(real_T *)&((char_T *)moduleInstance->u0)[8];
  ParkTransform_uQ4LZkjVPWhiGNFOCSwL0(&local, &(*moduleInstance->u1)[0],
    &b_local);
  *(real_T *)&((char_T *)moduleInstance->b_y0)[0] = b_local.s64_d;
  *(real_T *)&((char_T *)moduleInstance->b_y0)[8] = b_local.s64_q;
}

static void cgxe_mdl_update(InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (VectorAB_T *)cgxertGetInputPortSignal(moduleInstance->S,
    0);
  moduleInstance->u1 = (real_T (*)[2])cgxertGetInputPortSignal(moduleInstance->S,
    1);
  moduleInstance->b_y0 = (VectorDQ_T *)cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
}

/* CGXE Glue Code */
static void mdlOutputs_no3vTqIqx9Bjj4TgDsSRUF(SimStruct *S, int_T tid)
{
  InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF *moduleInstance =
    (InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_no3vTqIqx9Bjj4TgDsSRUF(SimStruct *S)
{
  InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF *moduleInstance =
    (InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_no3vTqIqx9Bjj4TgDsSRUF(SimStruct *S, int_T tid)
{
  InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF *moduleInstance =
    (InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_no3vTqIqx9Bjj4TgDsSRUF(SimStruct *S)
{
  InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF *moduleInstance =
    (InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_no3vTqIqx9Bjj4TgDsSRUF(SimStruct *S)
{
  InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF *moduleInstance =
    (InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_no3vTqIqx9Bjj4TgDsSRUF(SimStruct *S)
{
  InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF *moduleInstance =
    (InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_no3vTqIqx9Bjj4TgDsSRUF(SimStruct *S)
{
  InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF *moduleInstance =
    (InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_no3vTqIqx9Bjj4TgDsSRUF(SimStruct *S)
{
  InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF *moduleInstance =
    (InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF *)calloc(1, sizeof
    (InstanceStruct_no3vTqIqx9Bjj4TgDsSRUF));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_no3vTqIqx9Bjj4TgDsSRUF);
  ssSetmdlInitializeConditions(S, mdlInitialize_no3vTqIqx9Bjj4TgDsSRUF);
  ssSetmdlUpdate(S, mdlUpdate_no3vTqIqx9Bjj4TgDsSRUF);
  ssSetmdlDerivatives(S, mdlDerivatives_no3vTqIqx9Bjj4TgDsSRUF);
  ssSetmdlTerminate(S, mdlTerminate_no3vTqIqx9Bjj4TgDsSRUF);
  ssSetmdlEnable(S, mdlEnable_no3vTqIqx9Bjj4TgDsSRUF);
  ssSetmdlDisable(S, mdlDisable_no3vTqIqx9Bjj4TgDsSRUF);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_no3vTqIqx9Bjj4TgDsSRUF(SimStruct *S)
{
}

void method_dispatcher_no3vTqIqx9Bjj4TgDsSRUF(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_no3vTqIqx9Bjj4TgDsSRUF(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_no3vTqIqx9Bjj4TgDsSRUF(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: no3vTqIqx9Bjj4TgDsSRUF.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_no3vTqIqx9Bjj4TgDsSRUF_BuildInfoUpdate(void)
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

mxArray *cgxe_no3vTqIqx9Bjj4TgDsSRUF_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleFunction");
  mxArray* incompatibleSymbol = mxCreateString("ParkTransform");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
