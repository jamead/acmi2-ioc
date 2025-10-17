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

int BMsub(aSubRecord *precord) {

    int i;

    float *STAT = (float *)precord->a;
    float *QWFM = (float *)precord->b;

    int INTG = *(int *)precord->c;
    int RESET = *(int *)precord->d;
    int WLEN = *(int *)precord->e;
    int QCAL = *(int *)precord->f;

    printf("Beam INTG = %d  %d\n",INTG,QCAL);
    if(RESET>0){
        WLEN = 0;
        RESET = 0;
        *(int *)precord->vald = RESET;
    }

    if(WLEN>0 || INTG>0){
        float Q = (float)INTG/QCAL;
        if(WLEN<100){
            QWFM[WLEN] = Q;
            WLEN = WLEN + 1;
        }else{
            memmove(QWFM,QWFM+1,99*sizeof(float));
            QWFM[99] = Q;
            WLEN = 100;
        }

        *(float *)precord->vala = Q;
        *(int *)precord->vale = WLEN;
    }

    float QSUM=0;
    for(i=0;i<WLEN;i=i+1){
        QSUM = QSUM + QWFM[i];
    }
    float QAVG = QSUM/WLEN;
    STAT[6] = QAVG;
    QSUM = 0;
    for(i=0;i<WLEN;i=i+1){
        QSUM = QSUM + (QWFM[i]-QAVG)*(QWFM[i]-QAVG);
    }
    float QSTD = sqrt(QSUM/WLEN);
    STAT[9] = QSTD;

    precord->nevb = WLEN;
    memcpy((float *)precord->valb,QWFM,WLEN*sizeof(float));
    memcpy((float *)precord->valc,STAT,12*sizeof(float));

    return(0);
}
// Note the function must be registered at the end!
epicsRegisterFunction(BMsub);

