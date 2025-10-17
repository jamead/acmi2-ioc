#!../../bin/linux-x86_64/acmi2

#- SPDX-FileCopyrightText: 2005 Argonne National Laboratory
#-
#- SPDX-License-Identifier: EPICS

#- You may have to change acmi2 to something else
#- everywhere it appears in this file

#< envPaths

## Register all support components
dbLoadDatabase "../../dbd/acmi2.dbd"
acmi2_registerRecordDeviceDriver(pdbbase) 

#define the zuDFE (PSC Driver) IP Address:
epicsEnvSet("PSC_IP","10.0.142.135")
#MOXA= 10.0.142.108::4029

## Load record instances
#dbLoadRecords("../../db/acmi2.db","user=diag")
#dbLoadRecords("../../db/zudfe.db","P=LN-BI{ACMI:A}","user=diag")
dbLoadRecords("../../db/ADC.db","P=LN-BI{ACMI:A}","user=diag")
dbLoadRecords("../../db/SYS.db","P=LN-BI{ACMI:A}","user=diag")
dbLoadRecords("../../db/TP1.db","P=LN-BI{ACMI:A}","user=diag")
dbLoadRecords("../../db/TP2.db","P=LN-BI{ACMI:A}","user=diag")
dbLoadRecords("../../db/TP3.db","P=LN-BI{ACMI:A}","user=diag")
dbLoadRecords("../../db/Beam.db","P=LN-BI{ACMI:A}","user=diag")

################################################################
# Set the debug level for PSC Driver
var(PSCDebug, 1)   #5 full dialog

#Create the PSC connections that will be used in this IOC:
createPSC("Tx", $(PSC_IP), 7, 0)
createPSC("Wfm", $(PSC_IP), 20, 1)
createPSC("Rx", $(PSC_IP), 600, 1)

iocInit()

## Start any sequence programs
#seq sncacmi2,"user=diag"
