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

int Tick(aSubRecord *precord) {

    int count = *(int *)precord->a;

    printf("Uptime = %d\n",count);
    return(0);
}
// Note the function must be registered at the end!
epicsRegisterFunction(Tick);

