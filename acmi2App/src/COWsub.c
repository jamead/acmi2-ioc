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
    printf("Hello from COWSub....\n");
    int i,IMAX=0;
    float CFIT[128],CSUM=0,SCORE=0,PMAX=0;
    int *CWFM = (int *)precord->a;
//    char *DATE = (char *)precord->h;

    int INTG = *(int *)precord->b;
    int PEAK = *(int *)precord->c;
    int FWHM = *(int *)precord->d;
    int INDX = *(int *)precord->e;
    int BASE = *(int *)precord->f;
    int QCAL = *(int *)precord->g;
    int tmsec = *(int *)precord->h;

    float Q = (float)INTG/QCAL;
    *(float *)precord->vala = Q;
    
    time_t trigTime;
    struct tm ts;
    char tmstr[40];

    if(INTG>0){
        trigTime = (time_t)tmsec;
        ts = *localtime(&trigTime);
        strftime(tmstr,sizeof(tmstr), "%a %d %b %Y %H:%M:%S %Z", &ts);
    
        *(float *)precord->valc = Q;
        *(int *)precord->vald = INTG;
        *(int *)precord->vale = PEAK;
        *(int *)precord->valf = FWHM;
        *(int *)precord->valg = INDX;
        *(int *)precord->valh = BASE;
//        memcpy((char *)precord->vali,DATE,40*sizeof(char));
        for(i=0;i<128;i++){
            if(CWFM[i]>PMAX){
                PMAX = CWFM[i];
                IMAX = i;
            }
        }
        for(i=0;i<128;i++){
            CFIT[i] = PEAK*exp(-2.7726*(i-IMAX)*(i-IMAX)/(FWHM*FWHM));
        }
        for(i=0;i<128;i++){
            CSUM = CSUM + (CWFM[i]-CFIT[i])*(CWFM[i]-CFIT[i]);
        }
        SCORE = sqrt(CSUM)/PEAK;
        printf("CSUM = %8.2f  Score = %8.4f\n",CSUM,SCORE);
        memcpy((float *)precord->vali,CFIT,128*sizeof(float));
        memcpy((int *)precord->valb,CWFM,128*sizeof(int));
        memcpy((char *)precord->valj,tmstr,strlen(tmstr)*sizeof(char));
    }

    return(0);
}
// Note the function must be registered at the end!
epicsRegisterFunction(COWsub);

