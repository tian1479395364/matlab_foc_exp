/* Include files */

#include "FOC_CURRENTLOOP_DOUBLE_cgxe.h"
#include "m_tPqLTR99yKB88prL95J7jB.h"
#include "m_cUiG7eqHO9esXzVqDlM5KG.h"
#include "m_0SDQI7GoIcxIbgmUWNzcNH.h"
#include "m_no3vTqIqx9Bjj4TgDsSRUF.h"
#include "m_jCy4bKIhY7pemDeJFcrazF.h"

unsigned int cgxe_FOC_CURRENTLOOP_DOUBLE_method_dispatcher(SimStruct* S, int_T
  method, void* data)
{
  if (ssGetChecksum0(S) == 5122494 &&
      ssGetChecksum1(S) == 1592182627 &&
      ssGetChecksum2(S) == 3594438196 &&
      ssGetChecksum3(S) == 3006530733) {
    method_dispatcher_tPqLTR99yKB88prL95J7jB(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 1167920396 &&
      ssGetChecksum1(S) == 848566064 &&
      ssGetChecksum2(S) == 1561904804 &&
      ssGetChecksum3(S) == 913325549) {
    method_dispatcher_cUiG7eqHO9esXzVqDlM5KG(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 1391327766 &&
      ssGetChecksum1(S) == 2858637699 &&
      ssGetChecksum2(S) == 98643047 &&
      ssGetChecksum3(S) == 2339477886) {
    method_dispatcher_0SDQI7GoIcxIbgmUWNzcNH(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 1450177247 &&
      ssGetChecksum1(S) == 3658810323 &&
      ssGetChecksum2(S) == 825773964 &&
      ssGetChecksum3(S) == 2003097642) {
    method_dispatcher_no3vTqIqx9Bjj4TgDsSRUF(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3518178340 &&
      ssGetChecksum1(S) == 3001763263 &&
      ssGetChecksum2(S) == 3668121048 &&
      ssGetChecksum3(S) == 3364948015) {
    method_dispatcher_jCy4bKIhY7pemDeJFcrazF(S, method, data);
    return 1;
  }

  return 0;
}
