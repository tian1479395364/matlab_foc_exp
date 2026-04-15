/* Include files */

#include "modelInterface.h"
#include "m_WtvJoLlvf14Mld9AExiX3C.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_WtvJoLlvf14Mld9AExiX3C *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_WtvJoLlvf14Mld9AExiX3C
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_WtvJoLlvf14Mld9AExiX3C
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_WtvJoLlvf14Mld9AExiX3C
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_WtvJoLlvf14Mld9AExiX3C
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_WtvJoLlvf14Mld9AExiX3C
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_WtvJoLlvf14Mld9AExiX3C
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_WtvJoLlvf14Mld9AExiX3C
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_WtvJoLlvf14Mld9AExiX3C
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_WtvJoLlvf14Mld9AExiX3C *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_WtvJoLlvf14Mld9AExiX3C
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_WtvJoLlvf14Mld9AExiX3C
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

static void cgxe_mdl_update(InstanceStruct_WtvJoLlvf14Mld9AExiX3C
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_WtvJoLlvf14Mld9AExiX3C
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_WtvJoLlvf14Mld9AExiX3C
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_WtvJoLlvf14Mld9AExiX3C
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_WtvJoLlvf14Mld9AExiX3C
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_WtvJoLlvf14Mld9AExiX3C
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
static void mdlOutputs_WtvJoLlvf14Mld9AExiX3C(SimStruct *S, int_T tid)
{
  InstanceStruct_WtvJoLlvf14Mld9AExiX3C *moduleInstance =
    (InstanceStruct_WtvJoLlvf14Mld9AExiX3C *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_WtvJoLlvf14Mld9AExiX3C(SimStruct *S)
{
  InstanceStruct_WtvJoLlvf14Mld9AExiX3C *moduleInstance =
    (InstanceStruct_WtvJoLlvf14Mld9AExiX3C *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_WtvJoLlvf14Mld9AExiX3C(SimStruct *S, int_T tid)
{
  InstanceStruct_WtvJoLlvf14Mld9AExiX3C *moduleInstance =
    (InstanceStruct_WtvJoLlvf14Mld9AExiX3C *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_WtvJoLlvf14Mld9AExiX3C(SimStruct *S)
{
  InstanceStruct_WtvJoLlvf14Mld9AExiX3C *moduleInstance =
    (InstanceStruct_WtvJoLlvf14Mld9AExiX3C *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_WtvJoLlvf14Mld9AExiX3C(SimStruct *S)
{
  InstanceStruct_WtvJoLlvf14Mld9AExiX3C *moduleInstance =
    (InstanceStruct_WtvJoLlvf14Mld9AExiX3C *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_WtvJoLlvf14Mld9AExiX3C(SimStruct *S)
{
  InstanceStruct_WtvJoLlvf14Mld9AExiX3C *moduleInstance =
    (InstanceStruct_WtvJoLlvf14Mld9AExiX3C *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_WtvJoLlvf14Mld9AExiX3C(SimStruct *S)
{
  InstanceStruct_WtvJoLlvf14Mld9AExiX3C *moduleInstance =
    (InstanceStruct_WtvJoLlvf14Mld9AExiX3C *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_WtvJoLlvf14Mld9AExiX3C(SimStruct *S)
{
  InstanceStruct_WtvJoLlvf14Mld9AExiX3C *moduleInstance =
    (InstanceStruct_WtvJoLlvf14Mld9AExiX3C *)calloc(1, sizeof
    (InstanceStruct_WtvJoLlvf14Mld9AExiX3C));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_WtvJoLlvf14Mld9AExiX3C);
  ssSetmdlInitializeConditions(S, mdlInitialize_WtvJoLlvf14Mld9AExiX3C);
  ssSetmdlUpdate(S, mdlUpdate_WtvJoLlvf14Mld9AExiX3C);
  ssSetmdlDerivatives(S, mdlDerivatives_WtvJoLlvf14Mld9AExiX3C);
  ssSetmdlTerminate(S, mdlTerminate_WtvJoLlvf14Mld9AExiX3C);
  ssSetmdlEnable(S, mdlEnable_WtvJoLlvf14Mld9AExiX3C);
  ssSetmdlDisable(S, mdlDisable_WtvJoLlvf14Mld9AExiX3C);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_WtvJoLlvf14Mld9AExiX3C(SimStruct *S)
{
}

void method_dispatcher_WtvJoLlvf14Mld9AExiX3C(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_WtvJoLlvf14Mld9AExiX3C(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_WtvJoLlvf14Mld9AExiX3C(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: WtvJoLlvf14Mld9AExiX3C.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_WtvJoLlvf14Mld9AExiX3C_BuildInfoUpdate(void)
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

mxArray *cgxe_WtvJoLlvf14Mld9AExiX3C_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleFunction");
  mxArray* incompatibleSymbol = mxCreateString("ParkTransform");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
