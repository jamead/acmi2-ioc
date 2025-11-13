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

int BMarraySub(aSubRecord *precord) {
//    printf("Hello from BMarraySub....\n");
    int A[11],zero=0;

    A[0] = *(int *)precord->a;
    A[1] = *(int *)precord->b;
    A[2] = *(int *)precord->c;
    A[3] = *(int *)precord->d;
    A[4] = *(int *)precord->e;
    A[5] = *(int *)precord->f;
    A[6] = *(int *)precord->g;
    A[7] = *(int *)precord->h;
    A[8] = *(int *)precord->i;
    A[9] = *(int *)precord->j;
    A[10] = *(int *)precord->k;

    precord->neva = 11;
    memmove((int *)precord->vala,A,11*sizeof(int));
    *(int *)precord->valb = zero;

    return(0);
}
// Note the function must be registered at the end!
epicsRegisterFunction(BMarraySub);

