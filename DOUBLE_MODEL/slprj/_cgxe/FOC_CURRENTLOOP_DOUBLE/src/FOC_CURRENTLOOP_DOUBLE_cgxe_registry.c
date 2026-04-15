#define S_FUNCTION_LEVEL               2
#define S_FUNCTION_NAME                FOC_CURRENTLOOP_DOUBLE_cgxe
#include "simstruc.h"
#include "FOC_CURRENTLOOP_DOUBLE_cgxe.h"
#define MDL_START

static void mdlStart(SimStruct* S)
{
  unsigned int success;
  success = cgxe_FOC_CURRENTLOOP_DOUBLE_method_dispatcher(S, SS_CALL_MDL_START,
    NULL);
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }
}

#define MDL_INITIALIZE_CONDITIONS

static void mdlInitializeConditions(SimStruct *S)
{
  mexPrintf("ERROR: Calling model mdlInitializeConditions method directly.\n");
}

#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
  mexPrintf("ERROR: Calling model mdlUpdate method directly.\n");
}

static void mdlOutputs(SimStruct* S, int_T tid)
{
  mexPrintf("ERROR: Calling model mdlOutputs method directly.\n");
}

static void mdlTerminate(SimStruct *S)
{
  mexPrintf("ERROR: Calling model mdlTerminate method directly.\n");
}

static void mdlInitializeSizes(SimStruct *S)
{
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
}

static mxArray* cgxe_get_supported_modules(void)
{
  mxArray* mxModules = mxCreateCellMatrix(7, 1);
  mxArray* mxChksum = NULL;
  uint32_T* checksumData = NULL;
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 97302878;
  checksumData[1] = 419233478;
  checksumData[2] = 2218853022;
  checksumData[3] = 3181918142;
  mxSetCell(mxModules, 0, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1314032114;
  checksumData[1] = 3023819285;
  checksumData[2] = 418901554;
  checksumData[3] = 1276012442;
  mxSetCell(mxModules, 1, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1435439338;
  checksumData[1] = 2900208937;
  checksumData[2] = 3037693351;
  checksumData[3] = 2771695903;
  mxSetCell(mxModules, 2, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1888843486;
  checksumData[1] = 2478909244;
  checksumData[2] = 3797962656;
  checksumData[3] = 2462879674;
  mxSetCell(mxModules, 3, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 2324948978;
  checksumData[1] = 3693653034;
  checksumData[2] = 1845497534;
  checksumData[3] = 4255671355;
  mxSetCell(mxModules, 4, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3940654882;
  checksumData[1] = 2197063264;
  checksumData[2] = 75382700;
  checksumData[3] = 4072926984;
  mxSetCell(mxModules, 5, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 4280118347;
  checksumData[1] = 3734727184;
  checksumData[2] = 876620975;
  checksumData[3] = 3464031599;
  mxSetCell(mxModules, 6, mxChksum);
  return mxModules;
}

static int cgxe_process_get_checksums(int nlhs, mxArray* plhs[], int nrhs, const
  mxArray* prhs[])
{
  const char* checksumFields[] = { "modules", "model", "makefile", "target",
    "overall" };

  mxArray* mxChecksum = mxCreateStructMatrix(1, 1, 5, checksumFields);
  mxSetField(mxChecksum, 0, "modules", cgxe_get_supported_modules());

  {
    mxArray* mxModelChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxModelChksum);
    checksumData[0] = 1924076188;
    checksumData[1] = 3469004305;
    checksumData[2] = 3635883228;
    checksumData[3] = 3040362440;
    mxSetField(mxChecksum, 0, "model", mxModelChksum);
  }

  {
    mxArray* mxMakefileChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxMakefileChksum);
    checksumData[0] = 3015160960;
    checksumData[1] = 214775689;
    checksumData[2] = 312829798;
    checksumData[3] = 1016819244;
    mxSetField(mxChecksum, 0, "makefile", mxMakefileChksum);
  }

  {
    mxArray* mxTargetChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxTargetChksum);
    checksumData[0] = 2911221907;
    checksumData[1] = 2308967934;
    checksumData[2] = 2419390157;
    checksumData[3] = 1906300239;
    mxSetField(mxChecksum, 0, "target", mxTargetChksum);
  }

  {
    mxArray* mxOverallChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxOverallChksum);
    checksumData[0] = 3206719947;
    checksumData[1] = 2141241334;
    checksumData[2] = 2342762295;
    checksumData[3] = 1575133707;
    mxSetField(mxChecksum, 0, "overall", mxOverallChksum);
  }

  plhs[0] = mxChecksum;
  return 1;
}

static int cgxe_mex_unlock_call(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  while (mexIsLocked()) {
    mexUnlock();
  }

  return 1;
}

static SimStruct* cgxe_unpack_simstruct(const mxArray *mxS)
{
  uint32_T *uintPtr = (uint32_T*)malloc(sizeof(SimStruct*));
  int nEl = sizeof(SimStruct*)/sizeof(uint32_T);
  uint32_T *uintDataPtr = (uint32_T *)mxGetData(mxS);
  int el;
  SimStruct *S;
  for (el=0; el < nEl; el++) {
    uintPtr[el] = uintDataPtr[el];
  }

  memcpy(&S,uintPtr,sizeof(SimStruct*));
  free(uintPtr);
  return S;
}

static int cgxe_get_sim_state(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  unsigned int success;
  SimStruct *S = cgxe_unpack_simstruct(prhs[1]);
  success = cgxe_FOC_CURRENTLOOP_DOUBLE_method_dispatcher(S,
    SS_CALL_MDL_GET_SIM_STATE, (void *) (plhs));
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }

  return 1;
}

static int cgxe_set_sim_state(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  unsigned int success;
  SimStruct *S = cgxe_unpack_simstruct(prhs[1]);
  success = cgxe_FOC_CURRENTLOOP_DOUBLE_method_dispatcher(S,
    SS_CALL_MDL_SET_SIM_STATE, (void *) prhs[2]);
  if (!success) {
    /* error */
    mexPrintf("ERROR: Failed to dispatch s-function method!\n");
  }

  return 1;
}

static int cgxe_get_BuildInfoUpdate(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(tpChksum, "unweDRdyki1td8msJpm6") == 0) {
    extern mxArray *cgxe_unweDRdyki1td8msJpm6_BuildInfoUpdate(void);
    plhs[0] = cgxe_unweDRdyki1td8msJpm6_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "PasACjSZhuUltCNKsbQw") == 0) {
    extern mxArray *cgxe_PasACjSZhuUltCNKsbQw_BuildInfoUpdate(void);
    plhs[0] = cgxe_PasACjSZhuUltCNKsbQw_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "wGa0Z4renqqLwHYDYhFKy") == 0) {
    extern mxArray *cgxe_wGa0Z4renqqLwHYDYhFKy_BuildInfoUpdate(void);
    plhs[0] = cgxe_wGa0Z4renqqLwHYDYhFKy_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "MaDgHuWbHkqTxwPW63XgKE") == 0) {
    extern mxArray *cgxe_MaDgHuWbHkqTxwPW63XgKE_BuildInfoUpdate(void);
    plhs[0] = cgxe_MaDgHuWbHkqTxwPW63XgKE_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "gsM9JXgEcsMzVGyPy5QdUF") == 0) {
    extern mxArray *cgxe_gsM9JXgEcsMzVGyPy5QdUF_BuildInfoUpdate(void);
    plhs[0] = cgxe_gsM9JXgEcsMzVGyPy5QdUF_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "MOLC88wviLzdgeX5uzlQBF") == 0) {
    extern mxArray *cgxe_MOLC88wviLzdgeX5uzlQBF_BuildInfoUpdate(void);
    plhs[0] = cgxe_MOLC88wviLzdgeX5uzlQBF_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "e803lbbESFMDFf0YXqjAcG") == 0) {
    extern mxArray *cgxe_e803lbbESFMDFf0YXqjAcG_BuildInfoUpdate(void);
    plhs[0] = cgxe_e803lbbESFMDFf0YXqjAcG_BuildInfoUpdate();
    return 1;
  }

  return 0;
}

static int cgxe_get_fallback_info(int nlhs, mxArray * plhs[], int nrhs, const
  mxArray * prhs[])
{
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(tpChksum, "unweDRdyki1td8msJpm6") == 0) {
    extern mxArray *cgxe_unweDRdyki1td8msJpm6_fallback_info(void);
    plhs[0] = cgxe_unweDRdyki1td8msJpm6_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "PasACjSZhuUltCNKsbQw") == 0) {
    extern mxArray *cgxe_PasACjSZhuUltCNKsbQw_fallback_info(void);
    plhs[0] = cgxe_PasACjSZhuUltCNKsbQw_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "wGa0Z4renqqLwHYDYhFKy") == 0) {
    extern mxArray *cgxe_wGa0Z4renqqLwHYDYhFKy_fallback_info(void);
    plhs[0] = cgxe_wGa0Z4renqqLwHYDYhFKy_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "MaDgHuWbHkqTxwPW63XgKE") == 0) {
    extern mxArray *cgxe_MaDgHuWbHkqTxwPW63XgKE_fallback_info(void);
    plhs[0] = cgxe_MaDgHuWbHkqTxwPW63XgKE_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "gsM9JXgEcsMzVGyPy5QdUF") == 0) {
    extern mxArray *cgxe_gsM9JXgEcsMzVGyPy5QdUF_fallback_info(void);
    plhs[0] = cgxe_gsM9JXgEcsMzVGyPy5QdUF_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "MOLC88wviLzdgeX5uzlQBF") == 0) {
    extern mxArray *cgxe_MOLC88wviLzdgeX5uzlQBF_fallback_info(void);
    plhs[0] = cgxe_MOLC88wviLzdgeX5uzlQBF_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "e803lbbESFMDFf0YXqjAcG") == 0) {
    extern mxArray *cgxe_e803lbbESFMDFf0YXqjAcG_fallback_info(void);
    plhs[0] = cgxe_e803lbbESFMDFf0YXqjAcG_fallback_info();
    return 1;
  }

  return 0;
}

#define PROCESS_MEX_SFUNCTION_CMD_LINE_CALL

static int ProcessMexSfunctionCmdLineCall(int nlhs, mxArray* plhs[], int nrhs,
  const mxArray* prhs[])
{
  char commandName[64];
  if (nrhs < 1 || !mxIsChar(prhs[0]))
    return 0;
  mxGetString(prhs[0], commandName, sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName, "get_checksums") == 0) {
    return cgxe_process_get_checksums(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "mex_unlock") == 0) {
    return cgxe_mex_unlock_call(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_sim_state") == 0) {
    return cgxe_get_sim_state(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "set_sim_state") == 0) {
    return cgxe_set_sim_state(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_BuildInfoUpdate") == 0) {
    return cgxe_get_BuildInfoUpdate(nlhs, plhs, nrhs, prhs);
  }

  if (strcmp(commandName, "get_fallback_info") == 0) {
    return cgxe_get_fallback_info(nlhs, plhs, nrhs, prhs);
  }

  return 0;
}

#include "simulink.c"
