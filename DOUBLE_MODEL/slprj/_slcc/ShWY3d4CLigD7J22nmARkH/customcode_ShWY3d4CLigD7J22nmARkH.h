#ifndef __customcode_ShWY3d4CLigD7J22nmARkH_h__
#define __customcode_ShWY3d4CLigD7J22nmARkH_h__

/* Include files */
#include "mex.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "tmwtypes.h"


/* Helper definitions for DLL support */
#if defined _WIN32 
  #define DLL_EXPORT_CC __declspec(dllexport)
#else
  #if __GNUC__ >= 4
    #define DLL_EXPORT_CC __attribute__ ((visibility ("default")))
  #else
    #define DLL_EXPORT_CC
  #endif
#endif
/* Custom Code from Simulation Target dialog */
#include "jscl_clarke.h"
#include "jscl_park.h"
#include "jscl_invpark.h"
#include "jscl_currentloop.h"

/* Function Declarations */
#ifdef __cplusplus
extern "C" {
#endif
#define customcode_ShWY3d4CLigD7J22nmARkH_initializer()

#define customcode_ShWY3d4CLigD7J22nmARkH_terminator()
#ifdef __cplusplus
}
#endif

#endif

