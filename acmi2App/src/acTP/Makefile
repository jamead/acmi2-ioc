TOP=..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

PROD_HOST += acTP
acTP_SRCS	+= acTP.c
acTP_LIBS	+= $(EPICS_BASE_HOST_LIBS)

PROD_HOST += acSYS
acSYS_SRCS	+= acSYS.c
acSYS_LIBS	+= $(EPICS_BASE_HOST_LIBS)

PROD_HOST += acBM
acBM_SRCS	+= acBM.c
acBM_LIBS	+= $(EPICS_BASE_HOST_LIBS)

PROD_HOST += caSimpleUDPsend
caSimpleUPDsend_SRCS	+= caSimpleUDPsend.c
caSimpleUDPsend_LIBS	+= $(EPICS_BASE_HOST_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

