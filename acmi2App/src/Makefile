# SPDX-FileCopyrightText: 2003 Argonne National Laboratory
#
# SPDX-License-Identifier: EPICS

TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = acmi2
# acmi2.dbd will be created and installed
DBD += acmi2.dbd

# acmi2.dbd will be made up from these files:
acmi2_DBD += base.dbd

# Include dbd files from all support applications:
#acmi2_DBD += xxx.dbd
acmi2_DBD += acmi2Subs.dbd
acmi2_DBD += pscCore.dbd

# Add all the support libraries needed by this IOC
#acmi2_LIBS += xxx
acmi2_LIBS += pscCore

# acmi2_registerRecordDeviceDriver.cpp derives from acmi2.dbd
acmi2_SRCS += acmi2_registerRecordDeviceDriver.cpp
acmi2_SRCS += ADCsub.c
acmi2_SRCS += TPsub.c
acmi2_SRCS += BMsub.c
acmi2_SRCS += COWsub.c

# Build the main IOC entry point on workstation OSs.
acmi2_SRCS_DEFAULT += acmi2Main.cpp
acmi2_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#acmi2_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
acmi2_LIBS += $(EPICS_BASE_IOC_LIBS)
acmi2_SYS_LIBS += fftw3

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

