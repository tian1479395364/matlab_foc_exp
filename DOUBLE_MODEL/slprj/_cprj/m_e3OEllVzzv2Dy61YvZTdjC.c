/* Include files */

#include "modelInterface.h"
#include "m_e3OEllVzzv2Dy61YvZTdjC.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_e3OEllVzzv2Dy61YvZTdjC *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_e3OEllVzzv2Dy61YvZTdjC
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_e3OEllVzzv2Dy61YvZTdjC
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_e3OEllVzzv2Dy61YvZTdjC
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_e3OEllVzzv2Dy61YvZTdjC
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_e3OEllVzzv2Dy61YvZTdjC
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_e3OEllVzzv2Dy61YvZTdjC
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_e3OEllVzzv2Dy61YvZTdjC
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_e3OEllVzzv2Dy61YvZTdjC
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_e3OEllVzzv2Dy61YvZTdjC *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_e3OEllVzzv2Dy61YvZTdjC
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_e3OEllVzzv2Dy61YvZTdjC
  *moduleInstance)
{
  VectorAB_T local;
  VectorUVW_T b_local;
  local.s64_alpha = *(real_T *)&((char_T *)moduleInstance->u0)[0];
  local.s64_beta = *(real_T *)&((char_T *)moduleInstance->u0)[8];
  InverseClarkeTransform_uQ4LZkjVPWhiGNFOCSwL0(&local, &b_local);
  *(real_T *)&((char_T *)moduleInstance->b_y0)[0] = b_local.s64_u;
  *(real_T *)&((char_T *)moduleInstance->b_y0)[8] = b_local.s64_v;
  *(real_T *)&((char_T *)moduleInstance->b_y0)[16] = b_local.s64_w;
}

static void cgxe_mdl_update(InstanceStruct_e3OEllVzzv2Dy61YvZTdjC
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_e3OEllVzzv2Dy61YvZTdjC
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_e3OEllVzzv2Dy61YvZTdjC
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_e3OEllVzzv2Dy61YvZTdjC
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_e3OEllVzzv2Dy61YvZTdjC
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_e3OEllVzzv2Dy61YvZTdjC
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (VectorAB_T *)cgxertGetInputPortSignal(moduleInstance->S,
    0);
  moduleInstance->b_y0 = (VectorUVW_T *)cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
}

/* CGXE Glue Code */
static void mdlOutputs_e3OEllVzzv2Dy61YvZTdjC(SimStruct *S, int_T tid)
{
  InstanceStruct_e3OEllVzzv2Dy61YvZTdjC *moduleInstance =
    (InstanceStruct_e3OEllVzzv2Dy61YvZTdjC *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_e3OEllVzzv2Dy61YvZTdjC(SimStruct *S)
{
  InstanceStruct_e3OEllVzzv2Dy61YvZTdjC *moduleInstance =
    (InstanceStruct_e3OEllVzzv2Dy61YvZTdjC *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_e3OEllVzzv2Dy61YvZTdjC(SimStruct *S, int_T tid)
{
  InstanceStruct_e3OEllVzzv2Dy61YvZTdjC *moduleInstance =
    (InstanceStruct_e3OEllVzzv2Dy61YvZTdjC *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_e3OEllVzzv2Dy61YvZTdjC(SimStruct *S)
{
  InstanceStruct_e3OEllVzzv2Dy61YvZTdjC *moduleInstance =
    (InstanceStruct_e3OEllVzzv2Dy61YvZTdjC *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_e3OEllVzzv2Dy61YvZTdjC(SimStruct *S)
{
  InstanceStruct_e3OEllVzzv2Dy61YvZTdjC *moduleInstance =
    (InstanceStruct_e3OEllVzzv2Dy61YvZTdjC *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_e3OEllVzzv2Dy61YvZTdjC(SimStruct *S)
{
  InstanceStruct_e3OEllVzzv2Dy61YvZTdjC *moduleInstance =
    (InstanceStruct_e3OEllVzzv2Dy61YvZTdjC *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_e3OEllVzzv2Dy61YvZTdjC(SimStruct *S)
{
  InstanceStruct_e3OEllVzzv2Dy61YvZTdjC *moduleInstance =
    (InstanceStruct_e3OEllVzzv2Dy61YvZTdjC *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_e3OEllVzzv2Dy61YvZTdjC(SimStruct *S)
{
  InstanceStruct_e3OEllVzzv2Dy61YvZTdjC *moduleInstance =
    (InstanceStruct_e3OEllVzzv2Dy61YvZTdjC *)calloc(1, sizeof
    (InstanceStruct_e3OEllVzzv2Dy61YvZTdjC));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_e3OEllVzzv2Dy61YvZTdjC);
  ssSetmdlInitializeConditions(S, mdlInitialize_e3OEllVzzv2Dy61YvZTdjC);
  ssSetmdlUpdate(S, mdlUpdate_e3OEllVzzv2Dy61YvZTdjC);
  ssSetmdlDerivatives(S, mdlDerivatives_e3OEllVzzv2Dy61YvZTdjC);
  ssSetmdlTerminate(S, mdlTerminate_e3OEllVzzv2Dy61YvZTdjC);
  ssSetmdlEnable(S, mdlEnable_e3OEllVzzv2Dy61YvZTdjC);
  ssSetmdlDisable(S, mdlDisable_e3OEllVzzv2Dy61YvZTdjC);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_e3OEllVzzv2Dy61YvZTdjC(SimStruct *S)
{
}

void method_dispatcher_e3OEllVzzv2Dy61YvZTdjC(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_e3OEllVzzv2Dy61YvZTdjC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_e3OEllVzzv2Dy61YvZTdjC(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: e3OEllVzzv2Dy61YvZTdjC.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_e3OEllVzzv2Dy61YvZTdjC_BuildInfoUpdate(void)
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

mxArray *cgxe_e3OEllVzzv2Dy61YvZTdjC_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleFunction");
  mxArray* incompatibleSymbol = mxCreateString("InverseClarkeTransform");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
