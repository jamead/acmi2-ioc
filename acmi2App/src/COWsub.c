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

int COWsub(aSubRecord *precord) {

    printf("Hello from COW Sub...\n");
/*
    float *CWFM = (float *)precord->a;
    char *DATE = (char *)precord->h;

    int INTG = *(int *)precord->b;
    int PEAK = *(int *)precord->c;
    int FWHM = *(int *)precord->d;
    int INDX = *(int *)precord->e;
    int BASE = *(int *)precord->f;
    int QCAL = *(int *)precord->g;

    float Q = (float)INTG/QCAL;
    *(float *)precord->vala = Q;

    if(INTG>0){
        memcpy((float *)precord->valb,CWFM,128*sizeof(float));
        *(float *)precord->valc = Q;
        *(int *)precord->vald = INTG;
        *(int *)precord->vale = PEAK;
        *(int *)precord->valf = FWHM;
        *(int *)precord->valg = INDX;
        *(int *)precord->valh = BASE;
        memcpy((char *)precord->vali,DATE,40*sizeof(char));
    }
*/
    return(0);
}
// Note the function must be registered at the end!
epicsRegisterFunction(COWsub);

