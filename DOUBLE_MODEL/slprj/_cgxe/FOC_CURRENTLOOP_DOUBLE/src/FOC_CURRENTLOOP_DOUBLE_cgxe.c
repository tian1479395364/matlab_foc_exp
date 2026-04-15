/* Include files */

#include "FOC_CURRENTLOOP_DOUBLE_cgxe.h"
#include "m_unweDRdyki1td8msJpm6.h"
#include "m_PasACjSZhuUltCNKsbQw.h"
#include "m_wGa0Z4renqqLwHYDYhFKy.h"
#include "m_MaDgHuWbHkqTxwPW63XgKE.h"
#include "m_gsM9JXgEcsMzVGyPy5QdUF.h"
#include "m_MOLC88wviLzdgeX5uzlQBF.h"
#include "m_e803lbbESFMDFf0YXqjAcG.h"

unsigned int cgxe_FOC_CURRENTLOOP_DOUBLE_method_dispatcher(SimStruct* S, int_T
  method, void* data)
{
  if (ssGetChecksum0(S) == 97302878 &&
      ssGetChecksum1(S) == 419233478 &&
      ssGetChecksum2(S) == 2218853022 &&
      ssGetChecksum3(S) == 3181918142) {
    method_dispatcher_unweDRdyki1td8msJpm6(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 1314032114 &&
      ssGetChecksum1(S) == 3023819285 &&
      ssGetChecksum2(S) == 418901554 &&
      ssGetChecksum3(S) == 1276012442) {
    method_dispatcher_PasACjSZhuUltCNKsbQw(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 1435439338 &&
      ssGetChecksum1(S) == 2900208937 &&
      ssGetChecksum2(S) == 3037693351 &&
      ssGetChecksum3(S) == 2771695903) {
    method_dispatcher_wGa0Z4renqqLwHYDYhFKy(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 1888843486 &&
      ssGetChecksum1(S) == 2478909244 &&
      ssGetChecksum2(S) == 3797962656 &&
      ssGetChecksum3(S) == 2462879674) {
    method_dispatcher_MaDgHuWbHkqTxwPW63XgKE(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2324948978 &&
      ssGetChecksum1(S) == 3693653034 &&
      ssGetChecksum2(S) == 1845497534 &&
      ssGetChecksum3(S) == 4255671355) {
    method_dispatcher_gsM9JXgEcsMzVGyPy5QdUF(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3940654882 &&
      ssGetChecksum1(S) == 2197063264 &&
      ssGetChecksum2(S) == 75382700 &&
      ssGetChecksum3(S) == 4072926984) {
    method_dispatcher_MOLC88wviLzdgeX5uzlQBF(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 4280118347 &&
      ssGetChecksum1(S) == 3734727184 &&
      ssGetChecksum2(S) == 876620975 &&
      ssGetChecksum3(S) == 3464031599) {
    method_dispatcher_e803lbbESFMDFf0YXqjAcG(S, method, data);
    return 1;
  }

  return 0;
}
