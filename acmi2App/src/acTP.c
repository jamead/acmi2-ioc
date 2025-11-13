#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdint.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include "cadef.h"

#define PREFIX "LN-BI{ACMI:A}"

chid TP1in[30],TP1out[30],TP2in[30],TP2out[30],TP3in[30],TP3out[30];
chid SYSin[30],SYSout[30],PM[30];

int initialize_pvs()
{
    int status;
    char pvname[100];

    status = ca_context_create(ca_disable_preemptive_callback);
// System Input PVs:
    strcpy(pvname,PREFIX);
    strcat(pvname,"ADC-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[0]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TrigCnt-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[1]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:Qcal-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[2]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"faults_tp-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[3]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EVR:TS_Sec-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[4]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"acTP:Counter-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[5]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"acTP:Timer-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[6]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"faults_lat-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[7]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"faults_live-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[8]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"CRC:file-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[9]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"CRC:eeprom-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[10]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"CRC:artix-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[11]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EVR:TS_nSec-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[12]);


// TP1 Input PVs:
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP1:adcDelay-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1in[0]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1in[1]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1in[2]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1in[3]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1in[4]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1in[5]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP1:posLevel-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1in[6]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP1:negLevel-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1in[7]);

// TP1 Output PVs:
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:IOC:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[0]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:IOC:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[1]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:IOC:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[2]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:IOC:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[3]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:IOC:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[4]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:IOC:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[5]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[6]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:Q-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[7]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:peak-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[8]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:base-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[9]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[10]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:IOC:Qavg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[11]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:IOC:Qstd-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[12]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:Fault-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[13]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:Fault:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[14]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:Fault:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[15]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:Fault:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[16]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:Fault:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[17]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:Fault:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[18]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:Fault:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[19]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:Fault:date-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[20]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:IOC:PKavg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[21]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:IOC:PKstd-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[22]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:IOC:BLavg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[23]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:IOC:BLstd-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP1out[24]);


// TP2 Input PVs:
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP2:adcDelay-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2in[0]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2in[1]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2in[2]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2in[3]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2in[4]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2in[5]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP2:posLevel-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2in[6]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP2:negLevel-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2in[7]);

// TP2 Output PVs:
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:IOC:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[0]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:IOC:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[1]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:IOC:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[2]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:IOC:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[3]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:IOC:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[4]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:IOC:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[5]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[6]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:Q-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[7]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:peak-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[8]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:base-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[9]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[10]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:IOC:Qavg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[11]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:IOC:Qstd-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[12]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:Fault-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[13]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:Fault:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[14]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:Fault:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[15]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:Fault:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[16]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:Fault:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[17]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:Fault:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[18]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:Fault:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[19]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:Fault:date-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[20]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:IOC:PKavg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[21]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:IOC:PKstd-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[22]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:IOC:BLavg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[23]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:IOC:BLstd-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP2out[24]);

// TP3 Input PVs:
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP3:adcDelay-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3in[0]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3in[1]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3in[2]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3in[3]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3in[4]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3in[5]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP3:posLevel-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3in[6]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP3:negLevel-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3in[7]);

// TP3 Output PVs:
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:IOC:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[0]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:IOC:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[1]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:IOC:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[2]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:IOC:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[3]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:IOC:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[4]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:IOC:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[5]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[6]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:Q-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[7]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:peak-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[8]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:base-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[9]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[10]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:IOC:Qavg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[11]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:IOC:Qstd-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[12]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:Fault-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[13]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:Fault:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[14]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:Fault:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[15]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:Fault:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[16]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:Fault:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[17]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:Fault:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[18]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:Fault:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[19]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:Fault:date-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[20]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:IOC:PKavg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[21]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:IOC:PKstd-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[22]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:IOC:BLavg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[23]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:IOC:BLstd-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&TP3out[24]);

// Post Mortem PVs:

    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:PM:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[0]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:PM:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[1]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:PM:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[2]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:PM:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[3]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:PM:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[4]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:PM:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[5]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP1:PM-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[6]);

    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:PM:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[7]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:PM:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[8]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:PM:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[9]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:PM:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[10]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:PM:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[11]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:PM:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[12]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP2:PM-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[13]);

    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:PM:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[14]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:PM:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[15]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:PM:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[16]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:PM:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[17]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:PM:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[18]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:PM:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[19]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3:PM-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[20]);

    strcpy(pvname,PREFIX);
    strcat(pvname,"PM:TS_Sec-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[21]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"PM:TS_nSec-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[22]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"PM:Trig:Date-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[23]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"PM:TrigCnt-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[24]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"PM:CRC:file-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[25]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"PM:CRC:eeprom-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[26]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"PM:CRC:artix-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[27]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"PM:faults:live-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[28]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"PM:faults:lat-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[29]);

    ca_pend_io(5);
    return(status);
}

int main()
{
    int loopCounter=0,etime,stat=0,i,Nstat=0, TPfaults, pmlatch=0,fileCRC;
    float x,xmax,xmin,rsum[4];
    int faultLive,faultLatch,qcal,ADCraw[10000],sum[10],trigCount,oldtrigCount=0;
    int tmsec,eepromCRC,artixCRC,tnsec;

    int ARTXdelay1,ARTXbase1,ARTXpeak1,ARTXintegral1,ARTXfwhm1,ARTXindex1,TP1[80];
    float ARTXq1,q1,q1avg,q1std,q1sum=0,Qwfm1[3600]={0};
    int delay1,base1,peak1,integral1,fwhm1,index1,pos1,neg1,fwhm1LO,fwhm1HI;
    float b1sum=0,b1avg,b1std,p1sum=0,p1avg,p1std;
    int Bwfm1[3600]={0},Pwfm1[3600]={0};

    int ARTXdelay2,ARTXbase2,ARTXpeak2,ARTXintegral2,ARTXfwhm2,ARTXindex2,TP2[80];
    float ARTXq2,q2,q2avg,q2std,q2sum=0,Qwfm2[3600]={0};
    int delay2,base2,peak2,integral2,fwhm2,index2,pos2,neg2,fwhm2LO,fwhm2HI;
    float b2sum=0,b2avg,b2std,p2sum=0,p2avg,p2std;
    int Bwfm2[3600]={0},Pwfm2[3600]={0};

    int ARTXdelay3,ARTXbase3,ARTXpeak3,ARTXintegral3,ARTXfwhm3,ARTXindex3,TP3[80];
    float ARTXq3,q3sum,q3avg,q3std,q3,Qwfm3[3600]={0};
    int delay3,base3,peak3,integral3,fwhm3,index3,pos3,neg3,fwhm3LO,fwhm3HI;
    float b3sum=0,b3avg,b3std,p3sum=0,p3avg,p3std;
    int Bwfm3[3600]={0},Pwfm3[3600]={0};

    time_t trigTime;
    struct tm ts;
    char tmstr[80];

    clock_t loopStart;
    clock_t loopEnd;

    while(1==1){
//        printf("1....\n");
        loopStart = clock();
        if(stat!=1){
            printf("Initializing acTP...\n");
            stat = initialize_pvs();
            loopCounter=0;
            usleep(1000000);
        }
        stat = stat*ca_get(DBR_LONG,SYSin[1],(void *)&trigCount);
        ca_pend_io(5);
        if(trigCount>oldtrigCount){
	    stat = stat*ca_array_get(DBR_LONG,9000,SYSin[0],(void *)&ADCraw);
            stat = stat*ca_get(DBR_LONG,SYSin[3],(void *)&TPfaults);
            stat = stat*ca_get(DBR_LONG,SYSin[2],(void *)&qcal);
            stat = stat*ca_get(DBR_LONG,TP1in[0],(void *)&ARTXdelay1);
            stat = stat*ca_get(DBR_LONG,TP1in[1],(void *)&ARTXbase1);
            stat = stat*ca_get(DBR_LONG,TP1in[2],(void *)&ARTXpeak1);
            stat = stat*ca_get(DBR_LONG,TP1in[3],(void *)&ARTXintegral1);
            stat = stat*ca_get(DBR_LONG,TP1in[4],(void *)&ARTXfwhm1);
            stat = stat*ca_get(DBR_LONG,TP1in[5],(void *)&ARTXindex1);
            stat = stat*ca_get(DBR_LONG,TP1in[6],(void *)&pos1);
            stat = stat*ca_get(DBR_LONG,TP1in[7],(void *)&neg1);
            stat = stat*ca_get(DBR_LONG,TP2in[0],(void *)&ARTXdelay2);
            stat = stat*ca_get(DBR_LONG,TP2in[1],(void *)&ARTXbase2);
            stat = stat*ca_get(DBR_LONG,TP2in[2],(void *)&ARTXpeak2);
            stat = stat*ca_get(DBR_LONG,TP2in[3],(void *)&ARTXintegral2);
            stat = stat*ca_get(DBR_LONG,TP2in[4],(void *)&ARTXfwhm2);
            stat = stat*ca_get(DBR_LONG,TP2in[5],(void *)&ARTXindex2);
            stat = stat*ca_get(DBR_LONG,TP2in[6],(void *)&pos2);
            stat = stat*ca_get(DBR_LONG,TP2in[7],(void *)&neg2);
            stat = stat*ca_get(DBR_LONG,TP3in[0],(void *)&ARTXdelay3);
            stat = stat*ca_get(DBR_LONG,TP3in[1],(void *)&ARTXbase3);
            stat = stat*ca_get(DBR_LONG,TP3in[2],(void *)&ARTXpeak3);
            stat = stat*ca_get(DBR_LONG,TP3in[3],(void *)&ARTXintegral3);
            stat = stat*ca_get(DBR_LONG,TP3in[4],(void *)&ARTXfwhm3);
            stat = stat*ca_get(DBR_LONG,TP3in[5],(void *)&ARTXindex3);
            stat = stat*ca_get(DBR_LONG,TP3in[6],(void *)&pos3);
            stat = stat*ca_get(DBR_LONG,TP3in[7],(void *)&neg3);
            stat = stat*ca_get(DBR_LONG,SYSin[4],(void *)&tmsec);
            stat = stat*ca_get(DBR_LONG,SYSin[7],(void *)&faultLatch);
            ca_pend_io(5);
//            printf("2....tmsec=%d\n,",tmsec);
            oldtrigCount = trigCount;
            trigTime = (time_t)tmsec;
            ts = *localtime(&trigTime);
            strftime(tmstr,sizeof(tmstr), "%a %d %b %Y %H:%M:%S %Z", &ts);
            printf("2.1....%s\n",tmstr);

            // Get the 72-point Wfm for TP1 from the ADC Raw Array:
            for(i=0;i<72;i++){
               TP1[i] = -1*ADCraw[i+(int)ARTXdelay1];
               TP2[i] = -1*ADCraw[i+(int)ARTXdelay2];
               TP3[i] = -1*ADCraw[i+(int)ARTXdelay3];
            }
//            printf("2.2....\n");

            ARTXq1 = (float)ARTXintegral1/qcal;
            ARTXq2 = (float)ARTXintegral2/qcal;
            ARTXq3 = (float)ARTXintegral3/qcal;
//            printf("2.3....\n");

            stat = stat*ca_put(DBR_FLOAT,TP1out[10],(void *)&ARTXq1);
            stat = stat*ca_array_put(DBR_LONG,72,TP1out[6],TP1);
            if((TPfaults&0x0000FF)>0) stat = stat*ca_array_put(DBR_LONG,72,TP1out[13],TP1);
            stat = stat*ca_put(DBR_FLOAT,TP2out[10],(void *)&ARTXq2);
            stat = stat*ca_array_put(DBR_LONG,72,TP2out[6],TP2);
            if((TPfaults&0x00FF00)>0) stat = stat*ca_array_put(DBR_LONG,72,TP2out[13],TP2);
            stat = stat*ca_put(DBR_FLOAT,TP3out[10],(void *)&ARTXq3);
            stat = stat*ca_array_put(DBR_LONG,72,TP3out[6],TP3);
            if((TPfaults&0xFF0000)>0) stat = stat*ca_array_put(DBR_LONG,72,TP3out[13],TP3);
            ca_pend_io(5);
//            printf("3....\n");

            // Recalculate the Integral, Peak, FWHM, Baseline and Index Values:
            sum[1] = 0;
            sum[2] = 0;
            sum[3] = 0;
            for(i=0;i<32;i++){
                sum[1] = sum[1] + TP1[i];
                sum[2] = sum[2] + TP2[i];
                sum[3] = sum[3] + TP3[i];
            }
            base1 = (int)(sum[1]/32.0);
            base2 = (int)(sum[2]/32.0);
            base3 = (int)(sum[3]/32.0);
            for(i=32;i<72;i++){
                TP1[i] = TP1[i]-base1;
                if(pos1>=neg1){
                    if(TP1[i]<0) TP1[i]=0;
                }else{
                    if(TP1[i]>0) TP1[i]=0;
                }
                TP2[i] = TP2[i]-base2;
                if(pos2>=neg2){
                    if(TP2[i]<0) TP2[i]=0;
                }else{
                    if(TP2[i]>0) TP2[i]=0;
                }
                TP3[i] = TP3[i]-base3;
                if(pos3>=neg3){
                    if(TP3[i]<0) TP3[i]=0;
                }else{
                    if(TP3[i]>0) TP3[i]=0;
                }
            }
            if(neg1>pos1) base1 = -1*base1;
            if(neg2>pos2) base2 = -1*base2;
            if(neg3>pos3) base3 = -1*base3;
            integral1 = 0;
            integral2 = 0;
            integral3 = 0;
            peak1 = 0;
            peak2 = 0;
            peak3 = 0;
            for(i=32;i<72;i++){
                integral1 = integral1 + abs(TP1[i]);
                integral2 = integral2 + abs(TP2[i]);
                integral3 = integral3 + abs(TP3[i]);
                if(abs(TP1[i])>peak1){
                    peak1 = abs(TP1[i]);
                    index1 = i;
                }
                if(abs(TP2[i])>peak2){
                    peak2 = abs(TP2[i]);
                    index2 = i;
                }
                if(abs(TP3[i])>peak3){
                    peak3 = abs(TP3[i]);
                    index3 = i;
                }
            }
            fwhm1LO=0;
            fwhm1HI=0;
            fwhm2LO=0;
            fwhm2HI=0;
            fwhm3LO=0;
            fwhm3HI=0;
//            printf("4....%s\n",tmstr);

            for(i=32;i<72;i++){
                if(fwhm1LO==0 && abs(TP1[i])>(peak1/2)) fwhm1LO = i;
                if(fwhm1LO>0 && fwhm1HI==0 && abs(TP1[i])<(peak1/2)) fwhm1HI = i;
                if(fwhm2LO==0 && abs(TP2[i])>(peak2/2)) fwhm2LO = i;
                if(fwhm2LO>0 && fwhm2HI==0 && abs(TP2[i])<(peak2/2)) fwhm2HI = i;
                if(fwhm3LO==0 && abs(TP3[i])>(peak3/2)) fwhm3LO = i;
                if(fwhm3LO>0 && fwhm3HI==0 && abs(TP3[i])<(peak3/2)) fwhm3HI = i;
            }
            fwhm1 = fwhm1HI - fwhm1LO;
            fwhm2 = fwhm2HI - fwhm2LO;
            fwhm3 = fwhm3HI - fwhm3LO;
            q1 = (float)integral1/qcal;
            q2 = (float)integral2/qcal;
            q3 = (float)integral3/qcal;

            Nstat = Nstat + 1;
            if(Nstat>3600) Nstat = 3600;
            q1sum = q1sum + ARTXq1 - Qwfm1[3599];
            q2sum = q2sum + ARTXq2 - Qwfm2[3599];
            q3sum = q3sum + ARTXq3 - Qwfm3[3599];
            p1sum = p1sum + ARTXpeak1 - Pwfm1[3599];
            p2sum = p2sum + ARTXpeak2 - Pwfm2[3599];
            p3sum = p3sum + ARTXpeak3 - Pwfm3[3599];
            b1sum = b1sum + ARTXbase1 - Bwfm1[3599];
            b2sum = b2sum + ARTXbase2 - Bwfm2[3599];
            b3sum = b3sum + ARTXbase3 - Bwfm3[3599];
//            printf("b1sum=%5.1f base1=%5.1f wfm[3599]=%5.1f\n",b1sum,ARTXbase1,Bwfm1[3599]);
            for(i=3599;i>0;i--){
                Qwfm1[i] = Qwfm1[i-1];
                Qwfm2[i] = Qwfm2[i-1];
                Qwfm3[i] = Qwfm3[i-1];
                Pwfm1[i] = Pwfm1[i-1];
                Pwfm2[i] = Pwfm2[i-1];
                Pwfm3[i] = Pwfm3[i-1];
                Bwfm1[i] = Bwfm1[i-1];
                Bwfm2[i] = Bwfm2[i-1];
                Bwfm3[i] = Bwfm3[i-1];
            }
            Qwfm1[0] = ARTXq1;
            Qwfm2[0] = ARTXq2;
            Qwfm3[0] = ARTXq3;
            Pwfm1[0] = ARTXpeak1;
            Pwfm2[0] = ARTXpeak2;
            Pwfm3[0] = ARTXpeak3;
            Bwfm1[0] = ARTXbase1;
            Bwfm2[0] = ARTXbase2;
            Bwfm3[0] = ARTXbase3;
            q1avg = q1sum/Nstat;
            q2avg = q2sum/Nstat;
            q3avg = q3sum/Nstat;
            p1avg = p1sum/Nstat;
            p2avg = p2sum/Nstat;
            p3avg = p3sum/Nstat;
            b1avg = b1sum/Nstat;
            b2avg = b2sum/Nstat;
            b3avg = b3sum/Nstat;
//            printf("5....%s\n",tmstr);
            rsum[1]=0;
            rsum[2]=0;
            rsum[3]=0;
            sum[4]=0;
            sum[5]=0;
            sum[6]=0;
            sum[7]=0;
            sum[8]=0;
            sum[9]=0;
            if(Nstat>5){
                for(i=0;i<Nstat;i++){
                    rsum[1] = rsum[1] + (Qwfm1[i]-q1avg)*(Qwfm1[i]-q1avg);
                    rsum[2] = rsum[2] + (Qwfm2[i]-q2avg)*(Qwfm2[i]-q2avg);
                    rsum[3] = rsum[3] + (Qwfm3[i]-q3avg)*(Qwfm3[i]-q3avg);
                    sum[4] = sum[4] + (Pwfm1[i]-p1avg)*(Pwfm1[i]-p1avg);
                    sum[5] = sum[5] + (Pwfm2[i]-p2avg)*(Pwfm2[i]-p2avg);
                    sum[6] = sum[6] + (Pwfm3[i]-p3avg)*(Pwfm3[i]-p3avg);
                    sum[7] = sum[7] + (Bwfm1[i]-b1avg)*(Bwfm1[i]-b1avg);
                    sum[8] = sum[8] + (Bwfm2[i]-b2avg)*(Bwfm2[i]-b2avg);
                    sum[9] = sum[9] + (Bwfm3[i]-b3avg)*(Bwfm3[i]-b3avg);
                }
                q1std = sqrt(rsum[1]/Nstat);
                q2std = sqrt(rsum[2]/Nstat);
                q3std = sqrt(rsum[3]/Nstat);
                p1std = sqrt((float)sum[4]/Nstat);
                p2std = sqrt((float)sum[5]/Nstat);
                p3std = sqrt((float)sum[6]/Nstat);
                b1std = sqrt((float)sum[7]/Nstat);
                b2std = sqrt((float)sum[8]/Nstat);
                b3std = sqrt((float)sum[9]/Nstat);
            }else{
                q1std = 0;
                q2std = 0;
                q3std = 0;
                p1std = 0;
                p2std = 0;
                p3std = 0;
                b1std = 0;
                b2std = 0;
                b3std = 0;
            }
            index1 = index1 + ARTXdelay1;
            index2 = index2 + ARTXdelay2;
            index3 = index3 + ARTXdelay3;
            fwhm1LO=0;
            fwhm1HI=0;
            fwhm2LO=0;
            fwhm2HI=0;
            fwhm3LO=0;
            fwhm3HI=0;
            stat = stat*ca_put(DBR_LONG,TP1out[0],(void *)&base1);
            stat = stat*ca_put(DBR_LONG,TP1out[1],(void *)&peak1);
            stat = stat*ca_put(DBR_LONG,TP1out[2],(void *)&integral1);
            stat = stat*ca_put(DBR_LONG,TP1out[3],(void *)&fwhm1);
            stat = stat*ca_put(DBR_LONG,TP1out[4],(void *)&index1);
            stat = stat*ca_put(DBR_FLOAT,TP1out[5],(void *)&q1);
            stat = stat*ca_array_put(DBR_FLOAT,Nstat,TP1out[7],Qwfm1);
            stat = stat*ca_put(DBR_FLOAT,TP1out[11],(void *)&q1avg);
            stat = stat*ca_put(DBR_FLOAT,TP1out[12],(void *)&q1std);
            stat = stat*ca_array_put(DBR_LONG,Nstat,TP1out[8],Pwfm1);
            stat = stat*ca_put(DBR_FLOAT,TP1out[21],(void *)&p1avg);
            stat = stat*ca_put(DBR_FLOAT,TP1out[22],(void *)&p1std);
            stat = stat*ca_array_put(DBR_LONG,Nstat,TP1out[9],Bwfm1);
            stat = stat*ca_put(DBR_FLOAT,TP1out[23],(void *)&b1avg);
            stat = stat*ca_put(DBR_FLOAT,TP1out[24],(void *)&b1std);
//            printf("%s\n",tmstr);
            if((TPfaults&0x0000FF)>0){
                stat = stat*ca_put(DBR_STRING,TP1out[20],(void *)&tmstr);
                stat = stat*ca_put(DBR_FLOAT,TP1out[14],(void *)&ARTXq1);
                stat = stat*ca_put(DBR_LONG,TP1out[15],(void *)&ARTXintegral1);
                stat = stat*ca_put(DBR_LONG,TP1out[16],(void *)&ARTXpeak1);
                stat = stat*ca_put(DBR_LONG,TP1out[17],(void *)&ARTXfwhm1);
                stat = stat*ca_put(DBR_LONG,TP1out[18],(void *)&ARTXindex1);
                stat = stat*ca_put(DBR_LONG,TP1out[19],(void *)&ARTXbase1);
            }
            stat = stat*ca_put(DBR_LONG,TP2out[0],(void *)&base2);
            stat = stat*ca_put(DBR_LONG,TP2out[1],(void *)&peak2);
            stat = stat*ca_put(DBR_LONG,TP2out[2],(void *)&integral2);
            stat = stat*ca_put(DBR_LONG,TP2out[3],(void *)&fwhm2);
            stat = stat*ca_put(DBR_LONG,TP2out[4],(void *)&index2);
            stat = stat*ca_put(DBR_FLOAT,TP2out[5],(void *)&q2);
            stat = stat*ca_array_put(DBR_FLOAT,Nstat,TP2out[7],Qwfm2);
            stat = stat*ca_put(DBR_FLOAT,TP2out[11],(void *)&q2avg);
            stat = stat*ca_put(DBR_FLOAT,TP2out[12],(void *)&q2std);
            stat = stat*ca_array_put(DBR_LONG,Nstat,TP2out[8],Pwfm2);
            stat = stat*ca_put(DBR_FLOAT,TP2out[21],(void *)&p2avg);
            stat = stat*ca_put(DBR_FLOAT,TP2out[22],(void *)&p2std);
            stat = stat*ca_array_put(DBR_LONG,Nstat,TP2out[9],Bwfm2);
            stat = stat*ca_put(DBR_FLOAT,TP2out[23],(void *)&b2avg);
            stat = stat*ca_put(DBR_FLOAT,TP2out[24],(void *)&b2std);
            if((TPfaults&0x00FF00)>0){
                stat = stat*ca_put(DBR_STRING,TP2out[20],(void *)&tmstr);
                stat = stat*ca_put(DBR_FLOAT,TP2out[14],(void *)&ARTXq2);
                stat = stat*ca_put(DBR_LONG,TP2out[15],(void *)&ARTXintegral2);
                stat = stat*ca_put(DBR_LONG,TP2out[16],(void *)&ARTXpeak2);
                stat = stat*ca_put(DBR_LONG,TP2out[17],(void *)&ARTXfwhm2);
                stat = stat*ca_put(DBR_LONG,TP2out[18],(void *)&ARTXindex2);
                stat = stat*ca_put(DBR_LONG,TP2out[19],(void *)&ARTXbase2);
            }

            stat = stat*ca_put(DBR_LONG,TP3out[0],(void *)&base3);
            stat = stat*ca_put(DBR_LONG,TP3out[1],(void *)&peak3);
            stat = stat*ca_put(DBR_LONG,TP3out[2],(void *)&integral3);
            stat = stat*ca_put(DBR_LONG,TP3out[3],(void *)&fwhm3);
            stat = stat*ca_put(DBR_LONG,TP3out[4],(void *)&index3);
            stat = stat*ca_put(DBR_FLOAT,TP3out[5],(void *)&q3);
            stat = stat*ca_array_put(DBR_FLOAT,Nstat,TP3out[7],Qwfm3);
            stat = stat*ca_put(DBR_FLOAT,TP3out[11],(void *)&q3avg);
            stat = stat*ca_put(DBR_FLOAT,TP3out[12],(void *)&q3std);
            stat = stat*ca_array_put(DBR_LONG,Nstat,TP3out[8],Pwfm3);
            stat = stat*ca_put(DBR_FLOAT,TP3out[21],(void *)&p3avg);
            stat = stat*ca_put(DBR_FLOAT,TP3out[22],(void *)&p3std);
            stat = stat*ca_array_put(DBR_LONG,Nstat,TP3out[9],Bwfm3);
            stat = stat*ca_put(DBR_FLOAT,TP3out[23],(void *)&b3avg);
            stat = stat*ca_put(DBR_FLOAT,TP3out[24],(void *)&b3std);

            if((TPfaults&0xFF0000)>0){
                stat = stat*ca_put(DBR_STRING,TP3out[20],(void *)&tmstr);
                stat = stat*ca_put(DBR_FLOAT,TP3out[14],(void *)&ARTXq3);
                stat = stat*ca_put(DBR_LONG,TP3out[15],(void *)&ARTXintegral3);
                stat = stat*ca_put(DBR_LONG,TP3out[16],(void *)&ARTXpeak3);
                stat = stat*ca_put(DBR_LONG,TP3out[17],(void *)&ARTXfwhm3);
                stat = stat*ca_put(DBR_LONG,TP3out[18],(void *)&ARTXindex3);
                stat = stat*ca_put(DBR_LONG,TP3out[19],(void *)&ARTXbase3);
            }
//            printf("6....\n");

            printf("faultLatch=%f pmlatch=%d\n",faultLatch,pmlatch);
            if(faultLatch!=0 && pmlatch==0){
                printf("Processing PM...\n");
                pmlatch = 1;
                stat = stat*ca_put(DBR_FLOAT,PM[0],(void *)&q1);
                stat = stat*ca_put(DBR_LONG,PM[1],(void *)&integral1);
                stat = stat*ca_put(DBR_LONG,PM[2],(void *)&peak1);
                stat = stat*ca_put(DBR_LONG,PM[3],(void *)&fwhm1);
                stat = stat*ca_put(DBR_LONG,PM[4],(void *)&index1);
                stat = stat*ca_put(DBR_LONG,PM[5],(void *)&base1);
                stat = stat*ca_array_put(DBR_LONG,72,PM[6],TP1);

                stat = stat*ca_put(DBR_FLOAT,PM[7],(void *)&q2);
                stat = stat*ca_put(DBR_LONG,PM[8],(void *)&integral2);
                stat = stat*ca_put(DBR_LONG,PM[9],(void *)&peak2);
                stat = stat*ca_put(DBR_LONG,PM[10],(void *)&fwhm2);
                stat = stat*ca_put(DBR_LONG,PM[11],(void *)&index2);
                stat = stat*ca_put(DBR_LONG,PM[12],(void *)&base2);
                stat = stat*ca_array_put(DBR_LONG,72,PM[13],TP2);

                stat = stat*ca_put(DBR_FLOAT,PM[14],(void *)&q3);
                stat = stat*ca_put(DBR_LONG,PM[15],(void *)&integral3);
                stat = stat*ca_put(DBR_LONG,PM[16],(void *)&peak3);
                stat = stat*ca_put(DBR_LONG,PM[17],(void *)&fwhm3);
                stat = stat*ca_put(DBR_LONG,PM[18],(void *)&index3);
                stat = stat*ca_put(DBR_LONG,PM[19],(void *)&base3);
                stat = stat*ca_array_put(DBR_LONG,72,PM[20],TP3);

                stat = stat*ca_get(DBR_LONG,SYSin[8],(void *)&faultLive);
                stat = stat*ca_get(DBR_LONG,SYSin[9],(void *)&fileCRC);
                stat = stat*ca_get(DBR_LONG,SYSin[10],(void *)&eepromCRC);
                stat = stat*ca_get(DBR_LONG,SYSin[11],(void *)&artixCRC);
                stat = stat*ca_get(DBR_LONG,SYSin[12],(void *)&tnsec);
                ca_pend_io(5);
                usleep(2000);
                printf("%d   %f  %f\n",fileCRC,eepromCRC,artixCRC);
                stat = stat*ca_put(DBR_LONG,PM[21],(void *)&tmsec);
                stat = stat*ca_put(DBR_LONG,PM[22],(void *)&tnsec); //TSnSec
                stat = stat*ca_put(DBR_STRING,PM[23],(void *)&tmstr);
                stat = stat*ca_put(DBR_LONG,PM[24],(void *)&trigCount);  //TrigCount
                stat = stat*ca_put(DBR_LONG,PM[25],(void *)&fileCRC);  //FileCRC
                stat = stat*ca_put(DBR_LONG,PM[26],(void *)&eepromCRC);  //EEPROMCRC
                stat = stat*ca_put(DBR_LONG,PM[27],(void *)&artixCRC);  //ARTIXCRC
                stat = stat*ca_put(DBR_LONG,PM[28],(void *)&faultLive);  //faults_live
                stat = stat*ca_put(DBR_LONG,PM[29],(void *)&faultLatch);  //faults_lat

                ca_pend_io(5);
                printf("7....\n");

            }else if(faultLatch==0 && pmlatch==1){
                printf("PM armed...\n");
                pmlatch = 0;
            }

            ca_pend_io(5);
        }else{
            usleep(200000);
        }
        loopEnd = clock();
        loopCounter = loopCounter + 1;
        etime = (int)(loopEnd-loopStart);  //microseconds
        stat = stat*ca_put(DBR_LONG,SYSin[5],(void *)&loopCounter);
        stat = stat*ca_put(DBR_LONG,SYSin[6],(void *)&etime);
        ca_pend_io(5);
    }
}

