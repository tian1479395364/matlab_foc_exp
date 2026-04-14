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
  mxArray* mxModules = mxCreateCellMatrix(5, 1);
  mxArray* mxChksum = NULL;
  uint32_T* checksumData = NULL;
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 5122494;
  checksumData[1] = 1592182627;
  checksumData[2] = 3594438196;
  checksumData[3] = 3006530733;
  mxSetCell(mxModules, 0, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1167920396;
  checksumData[1] = 848566064;
  checksumData[2] = 1561904804;
  checksumData[3] = 913325549;
  mxSetCell(mxModules, 1, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1391327766;
  checksumData[1] = 2858637699;
  checksumData[2] = 98643047;
  checksumData[3] = 2339477886;
  mxSetCell(mxModules, 2, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 1450177247;
  checksumData[1] = 3658810323;
  checksumData[2] = 825773964;
  checksumData[3] = 2003097642;
  mxSetCell(mxModules, 3, mxChksum);
  mxChksum = mxCreateNumericMatrix(1, 4, mxUINT32_CLASS, mxREAL);
  checksumData = (uint32_T*) mxGetData(mxChksum);
  checksumData[0] = 3518178340;
  checksumData[1] = 3001763263;
  checksumData[2] = 3668121048;
  checksumData[3] = 3364948015;
  mxSetCell(mxModules, 4, mxChksum);
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
    checksumData[0] = 1448508573;
    checksumData[1] = 3089343339;
    checksumData[2] = 3171138811;
    checksumData[3] = 602021655;
    mxSetField(mxChecksum, 0, "model", mxModelChksum);
  }

  {
    mxArray* mxMakefileChksum = mxCreateDoubleMatrix(1, 4, mxREAL);
    double* checksumData = (double*) mxGetData(mxMakefileChksum);
    checksumData[0] = 3477062515;
    checksumData[1] = 2125385738;
    checksumData[2] = 3498980604;
    checksumData[3] = 3146961751;
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
    checksumData[0] = 893850397;
    checksumData[1] = 3378960645;
    checksumData[2] = 1350019159;
    checksumData[3] = 73852057;
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
  if (strcmp(tpChksum, "tPqLTR99yKB88prL95J7jB") == 0) {
    extern mxArray *cgxe_tPqLTR99yKB88prL95J7jB_BuildInfoUpdate(void);
    plhs[0] = cgxe_tPqLTR99yKB88prL95J7jB_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "cUiG7eqHO9esXzVqDlM5KG") == 0) {
    extern mxArray *cgxe_cUiG7eqHO9esXzVqDlM5KG_BuildInfoUpdate(void);
    plhs[0] = cgxe_cUiG7eqHO9esXzVqDlM5KG_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "0SDQI7GoIcxIbgmUWNzcNH") == 0) {
    extern mxArray *cgxe_0SDQI7GoIcxIbgmUWNzcNH_BuildInfoUpdate(void);
    plhs[0] = cgxe_0SDQI7GoIcxIbgmUWNzcNH_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "no3vTqIqx9Bjj4TgDsSRUF") == 0) {
    extern mxArray *cgxe_no3vTqIqx9Bjj4TgDsSRUF_BuildInfoUpdate(void);
    plhs[0] = cgxe_no3vTqIqx9Bjj4TgDsSRUF_BuildInfoUpdate();
    return 1;
  }

  if (strcmp(tpChksum, "jCy4bKIhY7pemDeJFcrazF") == 0) {
    extern mxArray *cgxe_jCy4bKIhY7pemDeJFcrazF_BuildInfoUpdate(void);
    plhs[0] = cgxe_jCy4bKIhY7pemDeJFcrazF_BuildInfoUpdate();
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
  if (strcmp(tpChksum, "tPqLTR99yKB88prL95J7jB") == 0) {
    extern mxArray *cgxe_tPqLTR99yKB88prL95J7jB_fallback_info(void);
    plhs[0] = cgxe_tPqLTR99yKB88prL95J7jB_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "cUiG7eqHO9esXzVqDlM5KG") == 0) {
    extern mxArray *cgxe_cUiG7eqHO9esXzVqDlM5KG_fallback_info(void);
    plhs[0] = cgxe_cUiG7eqHO9esXzVqDlM5KG_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "0SDQI7GoIcxIbgmUWNzcNH") == 0) {
    extern mxArray *cgxe_0SDQI7GoIcxIbgmUWNzcNH_fallback_info(void);
    plhs[0] = cgxe_0SDQI7GoIcxIbgmUWNzcNH_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "no3vTqIqx9Bjj4TgDsSRUF") == 0) {
    extern mxArray *cgxe_no3vTqIqx9Bjj4TgDsSRUF_fallback_info(void);
    plhs[0] = cgxe_no3vTqIqx9Bjj4TgDsSRUF_fallback_info();
    return 1;
  }

  if (strcmp(tpChksum, "jCy4bKIhY7pemDeJFcrazF") == 0) {
    extern mxArray *cgxe_jCy4bKIhY7pemDeJFcrazF_fallback_info(void);
    plhs[0] = cgxe_jCy4bKIhY7pemDeJFcrazF_fallback_info();
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
