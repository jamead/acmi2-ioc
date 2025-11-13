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
#include "crc.c"

#define PREFIX "LN-BI{ACMI:A}"
#define CRC_INIT 0xFFFFFFFF // Initial value for CRC calc
#define CRC32_POLY 0x04C11DB7 // CRC-32 Polynomial (0x04C11DB7)
#define MAX_LINE_LENGTH 100 // Maximum lines in settings file
#define MAX_SETTINGS 49 // Maximum number of ACMI2 Settings

chid EEin[90];
chid SYSin[30], SYSout[30];

int initialize_pvs()
{
    int status;
    char pvname[100];

    status = ca_context_create(ca_disable_preemptive_callback);
// System Input PVs:
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:save-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[0]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:load-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[1]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"Interlock-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[2]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EVR:TS_Sec-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[3]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EVR:TS_nSec-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[4]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"acSYS:Counter-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[5]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"acSYS:Timer-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[6]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"Temp1:Raw-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[7]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"Temp2:Raw-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[8]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"Vin:Raw-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[9]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"Iin:Raw-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[10]);

// System Output PVs:
    strcpy(pvname,PREFIX);
    strcat(pvname,"Key:State-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSout[0]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"Temp1-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSout[1]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"Temp2-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSout[2]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"Vin-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSout[3]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"Iin-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSout[4]);

// EEPROM PVs:
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:header-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[0]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP1:pulDelay-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[1]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP1:pulWidth-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[2]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP1:adcDelay-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[3]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP2:pulDelay-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[4]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP2:pulWidth-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[5]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP2:adcDelay-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[6]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP3:pulDelay-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[7]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP3:pulWidth-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[8]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP3:adcDelay-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[9]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:BEAM:adcDelay-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[10]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:COW:thresh-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[11]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP1:intgLL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[12]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP1:intgHL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[13]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP2:intgLL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[14]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP2:intgHL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[15]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP3:intgLL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[16]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP3:intgHL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[17]);

    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP1:peakLL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[18]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP1:peakHL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[19]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP2:peakLL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[20]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP2:peakHL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[21]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP3:peakLL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[22]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP3:peakHL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[23]);

    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP1:fwhmLL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[24]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP1:fwhmHL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[25]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP2:fwhmLL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[26]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP2:fwhmHL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[27]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP3:fwhmLL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[28]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP3:fwhmHL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[29]);

    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP1:baseLL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[30]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP1:baseHL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[31]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP2:baseLL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[32]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP2:baseHL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[33]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP3:baseLL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[34]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP3:baseHL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[35]);

    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP1:negLevel-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[36]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP2:negLevel-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[37]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP3:negLevel-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[38]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP1:posLevel-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[39]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP2:posLevel-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[40]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:TP3:posLevel-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[41]);

    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:Accumulator:HL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[42]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:BEAM:QHL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[43]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:BEAM:baseLL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[44]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:BEAM:baseHL-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[45]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:Qcal-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[46]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:Accumulator:Qmin-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[47]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:Accumulator:Len-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[48]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"CRC:file-SP");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&EEin[49]);

    ca_pend_io(5);
    return(status);
}

// Function to compute CRC32 with 8-bit input
uint32_t crc32_update(uint32_t crc, uint8_t data) {
    crc ^= ((uint32_t)data << 24); // Align data to the highest byte

    for (int i = 0; i < 8; i++) { // Process 8 bits
        if (crc & 0x80000000) {   // Check MSB
            crc = (crc << 1) ^ CRC32_POLY;
        } else {
            crc <<= 1;
        }
    }
    return crc;
}

int LoadFile(int stat)
{
    int i,fr,val;
    char buff[2000],*a, *line[50];

    fr = open("/nsls2/users/caracapp/acmi2/settings/settings.txt",O_RDONLY);
    read(fr,buff,2000);
    line[0] = strtok(buff,"\n");

    for(i=1;i<50;i++){
        line[i] = strtok(NULL,"\n");
    }
    for(i=0;i<50;i++){
        a = strtok(line[i],"\t");
        val = (int) strtol(a,(char **)NULL,10);
        printf("LoadFile: val[%d]=%d\n",i,val);
        stat = stat*ca_put(DBR_LONG,EEin[i],(void *)&val);
    }
    ca_pend_io(5);
    return(stat);
}

int WriteEEPROMtoFile(int stat)
{
    int i, Set[55], tm;
    uint32_t crc=0xFFFFFFFF;
    unsigned char byteval;
    char fname[200];

    stat = stat*ca_get(DBR_LONG,SYSin[3],(void *)&tm);
    ca_pend_io(5);
    sprintf(fname,"/nsls2/users/caracapp/acmi2/settings/settings_%d.txt",tm);
    printf("%s    %d\n",fname,tm);
    rename("/nsls2/users/caracapp/acmi2/settings/settings.txt",fname);
    usleep(300000);

    FILE *fout = fopen("/nsls2/users/caracapp/acmi2/settings/settings.txt","w");

    if(stat==1){
        for(i=0;i<MAX_SETTINGS;i++){
            stat = stat*ca_get(DBR_LONG,EEin[i],(void *)&Set[i]);
        }
        ca_pend_io(5);

        printf("Computing CRC\n"); 
        for (i=0;i<MAX_SETTINGS;i++) {
//	    printf("Setting Num: %d: Value: %d\n",i,Set[i]);
            byteval = (Set[i] >> 24) & 0xFF; 
            crc = crc32_update(crc,byteval);
//    	    printf("Byte: %d   CRC32: 0x%08X\n",byteval,crc);
            byteval = (Set[i] >> 16) & 0xFF; 
	    crc = crc32_update(crc,byteval);
//	    printf("Byte: %d   CRC32: 0x%08X\n",byteval,crc);
            byteval = (Set[i] >> 8) & 0xFF; 
	    crc = crc32_update(crc,byteval);
//	    printf("Byte: %d   CRC32: 0x%08X\n",byteval,crc);
            byteval = (Set[i] >> 0 ) & 0xFF; 
	    crc = crc32_update(crc,byteval);
//	    printf("Byte: %d   CRC32: 0x%08X\n\n",byteval,crc);
        }

        printf("CRC32 = 0x%x\n",crc);
        Set[MAX_SETTINGS] = crc;
        for(i=0;i<49;i++){
            printf("%d\t:\t%s\n",Set[i],ca_name(EEin[i]));
            fprintf(fout,"%d\t:\t%s\n",Set[i],ca_name(EEin[i]));
        }
        fprintf(fout,"%d\t:\t%s\n",Set[MAX_SETTINGS],ca_name(EEin[MAX_SETTINGS]));
        printf("%d\t:\t%s\n",Set[MAX_SETTINGS],ca_name(EEin[MAX_SETTINGS]));
        fclose(fout);
        stat = stat*ca_put(DBR_LONG,EEin[MAX_SETTINGS],(void *)&crc);
        ca_pend_io(5);
    }
    return(stat);
}


int main()
{
    int stat=0,loopCounter=0,save=0,load=0,etime,tmSec,tmnSec,t0;
    int Settings[50],interlock,key,oldkey,T1raw,T2raw,Vraw,Iraw;
    float tm,Temp1,Temp2,Vin,Iin,T1[8000],T2[8000],V[8000],I[8000],TM[8000];
    clock_t loopStart;
    clock_t loopEnd;

    time_t sysTime;
    struct tm ts;
    char tmstr[80];

    while(1==1){
        loopStart = clock();
        if(stat!=1){
            printf("Initializing acSYS...\n");
            stat = initialize_pvs();
            printf("stat = %d\n",stat);
            loopCounter=0;
            usleep(1000000);
        }
        stat = stat*ca_get(DBR_LONG,SYSin[0],(void *)&save);
        stat = stat*ca_get(DBR_LONG,SYSin[1],(void *)&load);
        stat = stat*ca_get(DBR_LONG,SYSin[2],(void *)&interlock);
        stat = stat*ca_get(DBR_LONG,SYSin[3],(void *)&tmSec);
        stat = stat*ca_get(DBR_LONG,SYSin[4],(void *)&tmnSec);
        stat = stat*ca_get(DBR_LONG,SYSin[7],(void *)&T1raw);
        stat = stat*ca_get(DBR_LONG,SYSin[8],(void *)&T2raw);
        stat = stat*ca_get(DBR_LONG,SYSin[9],(void *)&Vraw);
        stat = stat*ca_get(DBR_LONG,SYSin[10],(void *)&Iraw);
        ca_pend_io(5);

        if(loopCounter==0){
           t0 = tmSec;
           tm = 0;
        }else{
           tm = (float)(tmSec-t0)+(float)((double)tmnSec/125500000.0)/3600.0;
        }
        printf("Tsec=%d  TnSec=%d  tm = %10.5f\n",tmSec,tmnSec,tm);
        Temp1 = (float)T1raw*0.0078;
        Temp2 = (float)T2raw*0.0078;
        Vin = Vraw*1.25;
        Iin = (float)Iraw;
        key = (interlock&1);
        stat = stat*ca_put(DBR_LONG,SYSout[0],(void *)&key);
        stat = stat*ca_put(DBR_FLOAT,SYSout[1],(void *)&Temp1);
        stat = stat*ca_put(DBR_FLOAT,SYSout[2],(void *)&Temp2);
        stat = stat*ca_put(DBR_FLOAT,SYSout[3],(void *)&Vin);
        stat = stat*ca_put(DBR_FLOAT,SYSout[4],(void *)&Iin);
        ca_pend_io(5);

        if(save==1){
            printf("Saving...\n");
            stat = WriteEEPROMtoFile(stat);
            save = 0;
            stat = stat*ca_put(DBR_LONG,SYSin[0],(void *)&save);
            ca_pend_io(5);
        }
        if(load==1){
            printf("Loading...\n");
            stat = LoadFile(stat);
            load = 0;
            stat = stat*ca_put(DBR_LONG,SYSin[1],(void *)&load);
            ca_pend_io(5);
        }
        loopEnd = clock();
        loopCounter = loopCounter + 1;
        etime = (int)(loopEnd-loopStart);  //microseconds
        stat = stat*ca_put(DBR_LONG,SYSin[5],(void *)&loopCounter);
        stat = stat*ca_put(DBR_LONG,SYSin[6],(void *)&etime);
        ca_pend_io(5);
        usleep(400000);
    }
}
