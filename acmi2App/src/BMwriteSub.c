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

int BMwriteSub(aSubRecord *precord) {
    printf("Hello from BMwriteSub....\n");
    int zero=0;
    int *A = (int *)precord->a;

    *(int *)precord->vala = A[0];
    *(int *)precord->valb = A[1];
    *(int *)precord->valc = A[2];
    *(int *)precord->vald = A[3];
    *(int *)precord->vale = A[4];
    *(int *)precord->valf = A[5];
    *(int *)precord->valg = A[6];
    *(int *)precord->valh = A[7];
    *(int *)precord->vali = A[8];
    *(int *)precord->valj = A[9];
    *(int *)precord->valk = A[10];
    printf("A[10] = 0x%x\n",A[10]);

    *(int *)precord->valn = zero;

    return(0);
}
// Note the function must be registered at the end!
epicsRegisterFunction(BMwriteSub);
