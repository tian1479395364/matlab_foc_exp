# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


CPU = AMD64

MODEL  = FOC_CURRENTLOOP_DOUBLE
TARGET = cgxe
MODULE_SRCS 	= m_tPqLTR99yKB88prL95J7jB.c m_cUiG7eqHO9esXzVqDlM5KG.c m_0SDQI7GoIcxIbgmUWNzcNH.c m_no3vTqIqx9Bjj4TgDsSRUF.c m_jCy4bKIhY7pemDeJFcrazF.c
MODEL_SRC	= FOC_CURRENTLOOP_DOUBLE_cgxe.c
MODEL_REG = FOC_CURRENTLOOP_DOUBLE_cgxe_registry.c
MAKEFILE    = FOC_CURRENTLOOP_DOUBLE_cgxe.mak
MATLAB_ROOT	= D:\software\matlab2024_install
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------


USER_INCLUDES   =  /I "E:\Exp_G431\num1_currentloop\slprj\_cgxe\foc_currentloop_double\src" /I "E:\Exp_G431\num1_currentloop" /I "E:\Exp_G431\num1_currentloop\double_model" /I "E:\Exp_G431\NUM1_CURRENTLOOP\slprj\_cprj"

MLSL_INCLUDES     = \
    /I "D:\software\matlab2024_install\extern\include" \
    /I "D:\software\matlab2024_install\simulink\include" \
    /I "D:\software\matlab2024_install\rtw\c\src"
COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

THIRD_PARTY_INCLUDES   =  /I "E:\Exp_G431\NUM1_CURRENTLOOP\slprj\_cgxe\FOC_CURRENTLOOP_DOUBLE\src" /I "E:\Exp_G431\NUM1_CURRENTLOOP" /I "E:\Exp_G431\NUM1_CURRENTLOOP\slprj\_slcc\uQ4LZkjVPWhiGNFOCSwL0"
INCLUDE_PATH = $(MLSL_INCLUDES) $(USER_INCLUDES) $(THIRD_PARTY_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"
CFLAGS = /c /Zp8 /GR /w /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMX_COMPAT_64 /DMATLAB_MEXCMD_RELEASE=R2018a /DMATLAB_MEX_FILE /nologo /MD   
LDFLAGS = /nologo /dll /MANIFEST /OPT:NOREF /export:mexFunction /export:mexfilerequiredapiversion  
#----------------------------- Source Files -----------------------------------

USER_OBJS =

AUX_SRCS = D:\software\matlab2024_install\extern\version\c_mexapi_version.c  

REQ_SRCS  = $(MODEL_SRC) $(MODEL_REG) $(MODULE_SRCS) $(AUX_SRCS)
REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_OBJS) $(AUX_ABS_OBJS)
OBJLIST_FILE = FOC_CURRENTLOOP_DOUBLE_cgxe.mol
TMWLIB = "D:\software\matlab2024_install\extern\lib\win64\microsoft\libmx.lib" "D:\software\matlab2024_install\extern\lib\win64\microsoft\libmex.lib" "D:\software\matlab2024_install\extern\lib\win64\microsoft\libmat.lib" "D:\software\matlab2024_install\extern\lib\win64\microsoft\libfixedpoint.lib" "D:\software\matlab2024_install\extern\lib\win64\microsoft\libut.lib" "D:\software\matlab2024_install\extern\lib\win64\microsoft\libmwmathutil.lib" "D:\software\matlab2024_install\extern\lib\win64\microsoft\libemlrt.lib" "D:\software\matlab2024_install\extern\lib\win64\microsoft\libmwcgxert.lib" "D:\software\matlab2024_install\extern\lib\win64\microsoft\libmwcgxeooprt.lib" "D:\software\matlab2024_install\extern\lib\win64\microsoft\libmwslexec_simbridge.lib" "D:\software\matlab2024_install\extern\lib\win64\microsoft\libmwslccrt.lib" "D:\software\matlab2024_install\extern\lib\win64\microsoft\libmwstringutil.lib" "D:\software\matlab2024_install\extern\lib\win64\microsoft\libcovrt.lib" "D:\software\matlab2024_install\extern\lib\win64\microsoft\libmwsl_sfcn_cov_bridge.lib" "D:\software\matlab2024_install\extern\lib\win64\microsoft\libmwdsp_halidesim.lib" 
THIRD_PARTY_LIBS = "E:\Exp_G431\NUM1_CURRENTLOOP\slprj\_slcc\uQ4LZkjVPWhiGNFOCSwL0\uQ4LZkjVPWhiGNFOCSwL0_cclib.lib" 

#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MODEL)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
all : $(MEX_FILE_NAME) 


$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS)
	@echo ### Linking ...
	$(LD) $(LDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map" $(TMWLIB) $(THIRD_PARTY_LIBS) @$(OBJLIST_FILE)
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

