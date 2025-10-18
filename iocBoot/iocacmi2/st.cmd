#!../../bin/linux-x86_64/acmi2

#- You may have to change zpsc to something else
#- everywhere it appears in this file

< envPaths

epicsEnvSet("IOCNAME", "lab")

# PSC IP address
epicsEnvSet("ACMI2_IP", "10.0.142.128"); 

#epicsEnvSet("BLEN",100000);        # Snapshot DMA Length

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/acmi2.dbd"
acmi2_registerRecordDeviceDriver pdbbase

## Load record instances for PSC1
dbLoadRecords("db/lstats.db", "P=$(IOCNAME), NO=A")
dbLoadRecords("db/control.db", "P=$(IOCNAME), NO=A")
dbLoadRecords("db/pulse_stats.db", "P=$(IOCNAME), NO=A")
dbLoadRecords("db/eeprom.db", "P=$(IOCNAME), NO=A")
dbLoadRecords("db/adc_data.db", "P=$(IOCNAME), NO=A")





var(PSCDebug, 5)	#5 full debug

#psc1 Create the PSC
createPSC("PSCA", $(ACMI2_IP), 3000, 0)
#setPSCSendBlockSize("PSC1", 1100, 512)

cd "${TOP}/iocBoot/${IOC}"
iocInit

## Start any sequence programs
#seq reset_digout P=$(IOCNAME) NO=1 CHAN=1 &

epicsThreadSleep(1.0)
