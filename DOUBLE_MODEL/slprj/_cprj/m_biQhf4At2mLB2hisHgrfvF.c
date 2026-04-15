/* Include files */

#include "modelInterface.h"
#include "m_biQhf4At2mLB2hisHgrfvF.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_biQhf4At2mLB2hisHgrfvF *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_biQhf4At2mLB2hisHgrfvF
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_biQhf4At2mLB2hisHgrfvF
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_biQhf4At2mLB2hisHgrfvF
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_biQhf4At2mLB2hisHgrfvF
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_biQhf4At2mLB2hisHgrfvF
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_biQhf4At2mLB2hisHgrfvF
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_biQhf4At2mLB2hisHgrfvF
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_biQhf4At2mLB2hisHgrfvF
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_biQhf4At2mLB2hisHgrfvF *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_biQhf4At2mLB2hisHgrfvF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_biQhf4At2mLB2hisHgrfvF
  *moduleInstance)
{
  VectorDQ_T local;
  CurrentLoopDQ_uQ4LZkjVPWhiGNFOCSwL0(*moduleInstance->u0, *moduleInstance->u1, *
    moduleInstance->u2, *moduleInstance->u3, *moduleInstance->u4,
    *moduleInstance->u5, *moduleInstance->u6, *moduleInstance->u7, &local);
  *(real_T *)&((char_T *)moduleInstance->b_y0)[0] = local.s64_d;
  *(real_T *)&((char_T *)moduleInstance->b_y0)[8] = local.s64_q;
}

static void cgxe_mdl_update(InstanceStruct_biQhf4At2mLB2hisHgrfvF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_biQhf4At2mLB2hisHgrfvF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_biQhf4At2mLB2hisHgrfvF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_biQhf4At2mLB2hisHgrfvF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_biQhf4At2mLB2hisHgrfvF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_biQhf4At2mLB2hisHgrfvF
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 0);
  moduleInstance->u1 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 1);
  moduleInstance->u2 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 2);
  moduleInstance->u3 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 3);
  moduleInstance->u4 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 4);
  moduleInstance->u5 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 5);
  moduleInstance->u6 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 6);
  moduleInstance->u7 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 7);
  moduleInstance->b_y0 = (VectorDQ_T *)cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
}

/* CGXE Glue Code */
static void mdlOutputs_biQhf4At2mLB2hisHgrfvF(SimStruct *S, int_T tid)
{
  InstanceStruct_biQhf4At2mLB2hisHgrfvF *moduleInstance =
    (InstanceStruct_biQhf4At2mLB2hisHgrfvF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_biQhf4At2mLB2hisHgrfvF(SimStruct *S)
{
  InstanceStruct_biQhf4At2mLB2hisHgrfvF *moduleInstance =
    (InstanceStruct_biQhf4At2mLB2hisHgrfvF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_biQhf4At2mLB2hisHgrfvF(SimStruct *S, int_T tid)
{
  InstanceStruct_biQhf4At2mLB2hisHgrfvF *moduleInstance =
    (InstanceStruct_biQhf4At2mLB2hisHgrfvF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_biQhf4At2mLB2hisHgrfvF(SimStruct *S)
{
  InstanceStruct_biQhf4At2mLB2hisHgrfvF *moduleInstance =
    (InstanceStruct_biQhf4At2mLB2hisHgrfvF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_biQhf4At2mLB2hisHgrfvF(SimStruct *S)
{
  InstanceStruct_biQhf4At2mLB2hisHgrfvF *moduleInstance =
    (InstanceStruct_biQhf4At2mLB2hisHgrfvF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_biQhf4At2mLB2hisHgrfvF(SimStruct *S)
{
  InstanceStruct_biQhf4At2mLB2hisHgrfvF *moduleInstance =
    (InstanceStruct_biQhf4At2mLB2hisHgrfvF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_biQhf4At2mLB2hisHgrfvF(SimStruct *S)
{
  InstanceStruct_biQhf4At2mLB2hisHgrfvF *moduleInstance =
    (InstanceStruct_biQhf4At2mLB2hisHgrfvF *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_biQhf4At2mLB2hisHgrfvF(SimStruct *S)
{
  InstanceStruct_biQhf4At2mLB2hisHgrfvF *moduleInstance =
    (InstanceStruct_biQhf4At2mLB2hisHgrfvF *)calloc(1, sizeof
    (InstanceStruct_biQhf4At2mLB2hisHgrfvF));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_biQhf4At2mLB2hisHgrfvF);
  ssSetmdlInitializeConditions(S, mdlInitialize_biQhf4At2mLB2hisHgrfvF);
  ssSetmdlUpdate(S, mdlUpdate_biQhf4At2mLB2hisHgrfvF);
  ssSetmdlDerivatives(S, mdlDerivatives_biQhf4At2mLB2hisHgrfvF);
  ssSetmdlTerminate(S, mdlTerminate_biQhf4At2mLB2hisHgrfvF);
  ssSetmdlEnable(S, mdlEnable_biQhf4At2mLB2hisHgrfvF);
  ssSetmdlDisable(S, mdlDisable_biQhf4At2mLB2hisHgrfvF);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_biQhf4At2mLB2hisHgrfvF(SimStruct *S)
{
}

void method_dispatcher_biQhf4At2mLB2hisHgrfvF(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_biQhf4At2mLB2hisHgrfvF(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_biQhf4At2mLB2hisHgrfvF(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: biQhf4At2mLB2hisHgrfvF.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_biQhf4At2mLB2hisHgrfvF_BuildInfoUpdate(void)
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

mxArray *cgxe_biQhf4At2mLB2hisHgrfvF_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleFunction");
  mxArray* incompatibleSymbol = mxCreateString("CurrentLoopDQ");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
