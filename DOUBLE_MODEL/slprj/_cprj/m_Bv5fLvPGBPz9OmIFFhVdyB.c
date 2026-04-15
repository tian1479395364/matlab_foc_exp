/* Include files */

#include "modelInterface.h"
#include "m_Bv5fLvPGBPz9OmIFFhVdyB.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB
  *moduleInstance);
static void init_simulink_io_address(InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertSetSimStateCompliance(moduleInstance->S, 2);
}

static void cgxe_mdl_initialize(InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_outputs(InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB
  *moduleInstance)
{
  VectorAB_T b_local;
  VectorUVW_T local;
  local.s64_u = *(real_T *)&((char_T *)moduleInstance->u0)[0];
  local.s64_v = *(real_T *)&((char_T *)moduleInstance->u0)[8];
  local.s64_w = *(real_T *)&((char_T *)moduleInstance->u0)[16];
  ClarkeTransform_uQ4LZkjVPWhiGNFOCSwL0(&local, &b_local);
  *(real_T *)&((char_T *)moduleInstance->b_y0)[0] = b_local.s64_alpha;
  *(real_T *)&((char_T *)moduleInstance->b_y0)[8] = b_local.s64_beta;
}

static void cgxe_mdl_update(InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB
  *moduleInstance)
{
  (void)moduleInstance;
}

static void init_simulink_io_address(InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (VectorUVW_T *)cgxertGetInputPortSignal(moduleInstance->S,
    0);
  moduleInstance->b_y0 = (VectorAB_T *)cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
}

/* CGXE Glue Code */
static void mdlOutputs_Bv5fLvPGBPz9OmIFFhVdyB(SimStruct *S, int_T tid)
{
  InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB *moduleInstance =
    (InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_Bv5fLvPGBPz9OmIFFhVdyB(SimStruct *S)
{
  InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB *moduleInstance =
    (InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_Bv5fLvPGBPz9OmIFFhVdyB(SimStruct *S, int_T tid)
{
  InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB *moduleInstance =
    (InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_Bv5fLvPGBPz9OmIFFhVdyB(SimStruct *S)
{
  InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB *moduleInstance =
    (InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static void mdlTerminate_Bv5fLvPGBPz9OmIFFhVdyB(SimStruct *S)
{
  InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB *moduleInstance =
    (InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_Bv5fLvPGBPz9OmIFFhVdyB(SimStruct *S)
{
  InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB *moduleInstance =
    (InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_Bv5fLvPGBPz9OmIFFhVdyB(SimStruct *S)
{
  InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB *moduleInstance =
    (InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_Bv5fLvPGBPz9OmIFFhVdyB(SimStruct *S)
{
  InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB *moduleInstance =
    (InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB *)calloc(1, sizeof
    (InstanceStruct_Bv5fLvPGBPz9OmIFFhVdyB));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_Bv5fLvPGBPz9OmIFFhVdyB);
  ssSetmdlInitializeConditions(S, mdlInitialize_Bv5fLvPGBPz9OmIFFhVdyB);
  ssSetmdlUpdate(S, mdlUpdate_Bv5fLvPGBPz9OmIFFhVdyB);
  ssSetmdlDerivatives(S, mdlDerivatives_Bv5fLvPGBPz9OmIFFhVdyB);
  ssSetmdlTerminate(S, mdlTerminate_Bv5fLvPGBPz9OmIFFhVdyB);
  ssSetmdlEnable(S, mdlEnable_Bv5fLvPGBPz9OmIFFhVdyB);
  ssSetmdlDisable(S, mdlDisable_Bv5fLvPGBPz9OmIFFhVdyB);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_Bv5fLvPGBPz9OmIFFhVdyB(SimStruct *S)
{
}

void method_dispatcher_Bv5fLvPGBPz9OmIFFhVdyB(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_Bv5fLvPGBPz9OmIFFhVdyB(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_Bv5fLvPGBPz9OmIFFhVdyB(S);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: Bv5fLvPGBPz9OmIFFhVdyB.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_Bv5fLvPGBPz9OmIFFhVdyB_BuildInfoUpdate(void)
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

mxArray *cgxe_Bv5fLvPGBPz9OmIFFhVdyB_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("incompatibleFunction");
  mxArray* incompatibleSymbol = mxCreateString("ClarkeTransform");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
