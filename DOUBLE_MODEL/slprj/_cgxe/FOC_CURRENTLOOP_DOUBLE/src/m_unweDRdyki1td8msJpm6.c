/* Include files */

#include "modelInterface.h"
#include "m_unweDRdyki1td8msJpm6.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_unweDRdyki1td8msJpm6 *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_unweDRdyki1td8msJpm6
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_unweDRdyki1td8msJpm6 *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_unweDRdyki1td8msJpm6 *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_unweDRdyki1td8msJpm6
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_unweDRdyki1td8msJpm6 *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_unweDRdyki1td8msJpm6 *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_unweDRdyki1td8msJpm6
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_unweDRdyki1td8msJpm6
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_unweDRdyki1td8msJpm6 *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_unweDRdyki1td8msJpm6
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_unweDRdyki1td8msJpm6 *moduleInstance)
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

static void cgxe_mdl_update(InstanceStruct_unweDRdyki1td8msJpm6 *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_unweDRdyki1td8msJpm6
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_unweDRdyki1td8msJpm6 *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_unweDRdyki1td8msJpm6 *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_unweDRdyki1td8msJpm6
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_unweDRdyki1td8msJpm6
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
static void mdlOutputs_unweDRdyki1td8msJpm6(SimStruct *S, int_T tid)
{
  InstanceStruct_unweDRdyki1td8msJpm6 *moduleInstance =
    (InstanceStruct_unweDRdyki1td8msJpm6 *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_unweDRdyki1td8msJpm6(SimStruct *S)
{
  InstanceStruct_unweDRdyki1td8msJpm6 *moduleInstance =
    (InstanceStruct_unweDRdyki1td8msJpm6 *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_unweDRdyki1td8msJpm6(SimStruct *S, int_T tid)
{
  InstanceStruct_unweDRdyki1td8msJpm6 *moduleInstance =
    (InstanceStruct_unweDRdyki1td8msJpm6 *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_unweDRdyki1td8msJpm6(SimStruct *S)
{
  InstanceStruct_unweDRdyki1td8msJpm6 *moduleInstance =
    (InstanceStruct_unweDRdyki1td8msJpm6 *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_unweDRdyki1td8msJpm6(SimStruct *S)
{
  InstanceStruct_unweDRdyki1td8msJpm6 *moduleInstance =
    (InstanceStruct_unweDRdyki1td8msJpm6 *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_unweDRdyki1td8msJpm6(SimStruct *S)
{
  InstanceStruct_unweDRdyki1td8msJpm6 *moduleInstance =
    (InstanceStruct_unweDRdyki1td8msJpm6 *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_unweDRdyki1td8msJpm6(SimStruct *S)
{
  InstanceStruct_unweDRdyki1td8msJpm6 *moduleInstance =
    (InstanceStruct_unweDRdyki1td8msJpm6 *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_unweDRdyki1td8msJpm6(SimStruct *S)
{
  InstanceStruct_unweDRdyki1td8msJpm6 *moduleInstance =
    (InstanceStruct_unweDRdyki1td8msJpm6 *)calloc(1, sizeof
    (InstanceStruct_unweDRdyki1td8msJpm6));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_unweDRdyki1td8msJpm6);
  ssSetmdlInitializeConditions(S, mdlInitialize_unweDRdyki1td8msJpm6);
  ssSetmdlUpdate(S, mdlUpdate_unweDRdyki1td8msJpm6);
  ssSetmdlDerivatives(S, mdlDerivatives_unweDRdyki1td8msJpm6);
  ssSetmdlTerminate(S, mdlTerminate_unweDRdyki1td8msJpm6);
  ssSetmdlEnable(S, mdlEnable_unweDRdyki1td8msJpm6);
  ssSetmdlDisable(S, mdlDisable_unweDRdyki1td8msJpm6);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_unweDRdyki1td8msJpm6(SimStruct *S)
{
}

void method_dispatcher_unweDRdyki1td8msJpm6(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_unweDRdyki1td8msJpm6(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_unweDRdyki1td8msJpm6(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: unweDRdyki1td8msJpm6.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_unweDRdyki1td8msJpm6_BuildInfoUpdate(void)
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

mxArray *cgxe_unweDRdyki1td8msJpm6_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleFunction");
  mxArray* incompatibleSymbol = mxCreateString("ParkTransform");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
