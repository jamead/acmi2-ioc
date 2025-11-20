#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdint.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <aSubRecord.h>
#include <registryFunction.h>
#include <epicsExport.h>

int LoadFileSub(aSubRecord *precord)
{
    printf("Hello from LoadFileSub....\n");
    int i,fr,Set[55],TP1[13],TP2[13],TP3[13],BM[11],zero=0,stat;
    char buff[2000],*a, *line[50];

    fr = open("/home/diag/acmi2/settings/settings.txt",O_RDONLY);
    stat = read(fr,buff,2000);
    if(stat<0){
        printf("ERROR opening file.\n");
        return(stat);
    }
    line[0] = strtok(buff,"\n");

    for(i=1;i<50;i++){
        line[i] = strtok(NULL,"\n");
    }
    for(i=0;i<50;i++){
        a = strtok(line[i],"\t");
        Set[i] = (int) strtol(a,(char **)NULL,10);
        printf("LoadFile: Set[%d]=%d\n",i,Set[i]);
    }
    
    TP1[0] = Set[1];   TP2[0] = Set[4];   TP3[0] = Set[7];    BM[0] = Set[10];
    TP1[1] = Set[2];   TP2[1] = Set[5];   TP3[1] = Set[8];    BM[1] = Set[43];
    TP1[2] = Set[39];  TP2[2] = Set[40];  TP3[2] = Set[41];   BM[2] = Set[45];
    TP1[3] = Set[36];  TP2[3] = Set[37];  TP3[3] = Set[38];   BM[3] = Set[44];
    TP1[4] = Set[3];   TP2[4] = Set[6];   TP3[4] = Set[9];    BM[4] = Set[47];
    TP1[5] = Set[12];  TP2[5] = Set[14];  TP3[5] = Set[16];   BM[5] = Set[48];
    TP1[6] = Set[13];  TP2[6] = Set[15];  TP3[6] = Set[17];   BM[6] = Set[42];
    TP1[7] = Set[18];  TP2[7] = Set[20];  TP3[7] = Set[22];   BM[7] = Set[11];
    TP1[8] = Set[19];  TP2[8] = Set[21];  TP3[8] = Set[23];   BM[8] = Set[46];
    TP1[9] = Set[24];  TP2[9] = Set[26];  TP3[9] = Set[28];   BM[9] = Set[0];
    TP1[10] = Set[25]; TP2[10] = Set[27]; TP3[10] = Set[29];  BM[10] = Set[49];
    TP1[11] = Set[30]; TP2[11] = Set[32]; TP3[11] = Set[34];
    TP1[12] = Set[31]; TP2[12] = Set[33]; TP3[12] = Set[35];
    
    precord->neva = 13;
    precord->nevb = 13;
    precord->nevc = 13;
    precord->nevd = 11;
    
    memmove((int *)precord->vala,TP1,13*sizeof(int));
    memmove((int *)precord->valb,TP2,13*sizeof(int));
    memmove((int *)precord->valc,TP3,13*sizeof(int));
    memmove((int *)precord->vald,BM,11*sizeof(int));
    *(int *)precord->vale = zero;
    return(0);
}
// Note the function must be registered at the end!
epicsRegisterFunction(LoadFileSub);
