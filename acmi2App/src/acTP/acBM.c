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

chid BMin[30],COWin[30];
chid SYSin[30], PM[20];

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
    strcat(pvname,"EVR:TS_Sec-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[3]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"Trig:Date-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[4]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"acBM:Counter-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[5]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"acBM:Timer-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[6]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"faults_lat-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&SYSin[7]);

// Beam Indicator PVs:
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:BEAM:adcDelay-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[0]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[1]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[2]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[3]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[4]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[5]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"Accumulator-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[6]);
//  BEAM IOC Indicator PVs:
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:IOC:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[11]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:IOC:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[12]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:IOC:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[13]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:IOC:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[14]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:IOC:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[15]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[16]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:IOC:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[17]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[18]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:Q-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[19]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"Accumulator:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[20]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"Accumulator:Q-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[21]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:Accumulator:HL-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[22]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:Accumulator:Len-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[23]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"Accumulator:QHL-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&BMin[24]);

// COW Indicator PVs:
    strcpy(pvname,PREFIX);
    strcat(pvname,"EE:COW:thresh-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[0]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[1]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[2]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[3]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[4]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[5]);

// COW IOC Indicator PVs:
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:IOC:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[11]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:IOC:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[12]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:IOC:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[13]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:IOC:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[14]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:IOC:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[15]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[16]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:IOC:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[17]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[18]);
// COW Fault Readings:
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:Fault:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[21]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:Fault:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[22]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:Fault:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[23]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:Fault:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[24]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:Fault:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[25]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:Fault:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[26]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:Fault-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[27]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:Fault:date-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&COWin[28]);

// Post Mortem PVs for Beam, Accumulators, and COW

    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:PM:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[0]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:PM:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[1]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:PM:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[2]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:PM:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[3]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:PM:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[4]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:PM:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[5]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"BEAM:PM-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[6]);

    strcpy(pvname,PREFIX);
    strcat(pvname,"Accumulator:PM:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[7]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"Accumulator:PM-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[8]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"Accumulator:PM:Q-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[9]);

    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:PM:Q-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[10]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:PM:intg-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[11]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:PM:peak-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[12]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:PM:fwhm-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[13]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:PM:indx-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[14]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:PM:base-I");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[15]);
    strcpy(pvname,PREFIX);
    strcat(pvname,"COW:PM-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PM[16]);

    ca_pend_io(5);
    return(status);
}

int main()
{
    int loopCounter=0,etime,stat=0,i,j,Nstat=0, pmlatch=0;
    int x, xmax, xmin, sum, qcal, ADCraw[10000], faultLatch;
    int trigCount,oldtrigCount=0,tsSec;

    float ARTXq1,BeamQ[3600]={0},AccQ[3600]={0},q1,accumQ,q1sum,q1avg,q1std,accQHL;
    int ARTXdelay1,ARTXbase1,ARTXpeak1,ARTXintegral1,ARTXfwhm1,ARTXindex1;
    int delay1,base1,peak1,integral1,fwhm1,index1,Beam[80],sum1;
    int fwhm1LO,fwhm1HI,accum,accLen,accHL;

    float ARTXq2,q2;
    int ARTXthresh,ARTXbase2,ARTXpeak2,ARTXintegral2,ARTXfwhm2,ARTXindex2;
    int delay2,base2,peak2,integral2,fwhm2,index2,COW[130],sum2;
    int pos2,neg2,fwhm2LO,fwhm2HI;

    time_t evrTime;
    struct tm ts;
    char tmstr[80],fname[200];

    clock_t loopStart;
    clock_t loopEnd;

    while(1==1){
        loopStart = clock();
        if(stat!=1){
            printf("Initializing acBM...\n");
            stat = initialize_pvs();
            loopCounter=0;
            usleep(1000000);
        }
        stat = stat*ca_get(DBR_LONG,SYSin[1],(void *)&trigCount);
        ca_pend_io(5);
        if(trigCount>oldtrigCount){
	    stat = stat*ca_array_get(DBR_LONG,4500,SYSin[0],(void *)&ADCraw);
            stat = stat*ca_get(DBR_LONG,SYSin[2],(void *)&qcal);
            stat = stat*ca_get(DBR_LONG,BMin[0],(void *)&ARTXdelay1);
            stat = stat*ca_get(DBR_LONG,BMin[1],(void *)&ARTXbase1);
            stat = stat*ca_get(DBR_LONG,BMin[2],(void *)&ARTXpeak1);
            stat = stat*ca_get(DBR_LONG,BMin[3],(void *)&ARTXintegral1);
            stat = stat*ca_get(DBR_LONG,BMin[4],(void *)&ARTXfwhm1);
            stat = stat*ca_get(DBR_LONG,BMin[5],(void *)&ARTXindex1);
            stat = stat*ca_get(DBR_LONG,BMin[6],(void *)&accum);
            stat = stat*ca_get(DBR_LONG,BMin[22],(void *)&accHL);
            stat = stat*ca_get(DBR_LONG,BMin[23],(void *)&accLen);

            stat = stat*ca_get(DBR_LONG,COWin[0],(void *)&ARTXthresh);
            stat = stat*ca_get(DBR_LONG,COWin[1],(void *)&ARTXbase2);
            stat = stat*ca_get(DBR_LONG,COWin[2],(void *)&ARTXpeak2);
            stat = stat*ca_get(DBR_LONG,COWin[3],(void *)&ARTXintegral2);
            stat = stat*ca_get(DBR_LONG,COWin[4],(void *)&ARTXfwhm2);
            stat = stat*ca_get(DBR_LONG,COWin[5],(void *)&ARTXindex2);
            stat = stat*ca_array_get(DBR_LONG,128,COWin[18],(void *)&COW);
            stat = stat*ca_get(DBR_LONG,SYSin[3],(void *)&tsSec);
            stat = stat*ca_get(DBR_LONG,SYSin[7],(void *)&faultLatch);
            ca_pend_io(5);
            printf("tsSec=%8.1f   %d\n",tsSec,stat);
            oldtrigCount = trigCount;
            // Get the time and date for the current trigger:
            evrTime = (time_t)tsSec;
            ts = *localtime(&evrTime);
            strftime(tmstr,sizeof(tmstr), "%a %d %b %Y %H:%M:%S %Z", &ts);
            stat = stat*ca_put(DBR_STRING,SYSin[4],(void *)&tmstr);
            ca_pend_io(5);
            printf("Qcal=%d\n",qcal);

            // Get the 72-point Wfm for TP1 from the ADC Raw Array:
            for(i=0;i<72;i++){
               Beam[i] = -1*ADCraw[i+(int)ARTXdelay1];
            }
//            printf("COWintegral=%f\n",ARTXintegral2);
            ARTXq1 = (float)ARTXintegral1/qcal;
            ARTXq2 = (float)ARTXintegral2/qcal;
            accQHL = (float)accHL/qcal;
            stat = stat*ca_put(DBR_FLOAT,BMin[16],(void *)&ARTXq1);
            stat = stat*ca_put(DBR_FLOAT,BMin[24],(void *)&accQHL);
            stat = stat*ca_array_put(DBR_LONG,72,BMin[18],Beam);
            stat = stat*ca_put(DBR_FLOAT,COWin[16],(void *)&ARTXq2);
            ca_pend_io(5);
            // Recalculate the Integral, Peak, FWHM, Baseline and Index Values:
            sum1 = 0;
            sum2 = 0;
            for(i=0;i<50;i++){
                if(i<32) sum1 = sum1 + Beam[i];
                sum2 = sum2 + COW[i];
            }
            base1 = (int)((float)sum1/32.0);
            base2 = (int)((float)sum2/50.0);
            integral1 = 0;
            peak1 = 0;
            fwhm1LO = 0;
            fwhm1HI = 0;
            integral2 = 0;
            peak2 = 0;
            for(i=32;i<72;i++){
                Beam[i] = Beam[i]-base1;
                if(Beam[i]<0) Beam[i]=0;
                integral1 = integral1 + Beam[i];
                if(Beam[i]>peak1){
                    peak1 = Beam[i];
                    index1 = i;
                }
            }
            for(i=32;i<72;i++){
                if(fwhm1LO==0 && Beam[i]>(peak1/2)) fwhm1LO = i;
                if(fwhm1LO>0 && fwhm1HI==0 && Beam[i]<(peak1/2)) fwhm1HI = i;
            }
            fwhm1 = fwhm1HI - fwhm1LO;

            for(i=50;i<128;i++){
                x =  COW[i] - base2;
                if(x>0){
                    integral2 = integral2 + x;
                }
                if(x>peak2){
                    peak2 = x;
                    index2 = i;
                }
            }
            q1 = (float)integral1/qcal;
            q2 = (float)integral2/qcal;
            Nstat = Nstat + 1;
            if(Nstat>3600) Nstat = 3600;
            q1sum = q1sum + q1 - BeamQ[3599];
            for(i=3599;i>0;i--){
                BeamQ[i] = BeamQ[i-1];
                AccQ[i] = AccQ[i-1];
            }
            BeamQ[0] = q1;
            accumQ = (float)accum/qcal;
            AccQ[0] = accumQ;
            index1 = index1 + ARTXdelay1;
            if(q2>0){
                index2 = index2 + ARTXindex2 - 70;
            }else{
                index2 = 0;
            }
            fwhm2LO=0;
            fwhm2HI=0;
            for(i=50;i<128;i++){
                if(fwhm2LO==0 && COW[i]>(peak2/2)) fwhm2LO = i;
                if(fwhm2LO>0 && fwhm2HI==0 && COW[i]<(peak2/2)) fwhm2HI = i;
            }
            fwhm2 = fwhm2HI - fwhm2LO;

            stat = stat*ca_put(DBR_LONG,BMin[11],(void *)&base1);
            stat = stat*ca_put(DBR_LONG,BMin[12],(void *)&peak1);
            stat = stat*ca_put(DBR_LONG,BMin[13],(void *)&integral1);
            stat = stat*ca_put(DBR_LONG,BMin[14],(void *)&fwhm1);
            stat = stat*ca_put(DBR_LONG,BMin[15],(void *)&index1);
            stat = stat*ca_put(DBR_FLOAT,BMin[17],(void *)&q1);
            stat = stat*ca_put(DBR_FLOAT,BMin[20],(void *)&accumQ);
            stat = stat*ca_array_put(DBR_FLOAT,Nstat,BMin[19],BeamQ);
            stat = stat*ca_array_put(DBR_FLOAT,accLen,BMin[21],AccQ);

            stat = stat*ca_put(DBR_LONG,COWin[11],(void *)&base2);
            stat = stat*ca_put(DBR_LONG,COWin[12],(void *)&peak2);
            stat = stat*ca_put(DBR_LONG,COWin[13],(void *)&integral2);
            stat = stat*ca_put(DBR_LONG,COWin[14],(void *)&fwhm2);
            stat = stat*ca_put(DBR_LONG,COWin[15],(void *)&index2);
            stat = stat*ca_put(DBR_FLOAT,COWin[17],(void *)&q2);
            if(ARTXq2>0){
                stat = stat*ca_put(DBR_LONG,COWin[21],(void *)&ARTXbase2);
                stat = stat*ca_put(DBR_LONG,COWin[22],(void *)&ARTXpeak2);
                stat = stat*ca_put(DBR_LONG,COWin[23],(void *)&ARTXintegral2);
                stat = stat*ca_put(DBR_LONG,COWin[24],(void *)&ARTXfwhm2);
                stat = stat*ca_put(DBR_LONG,COWin[25],(void *)&ARTXindex2);
                stat = stat*ca_put(DBR_FLOAT,COWin[26],(void *)&ARTXq2);
                stat = stat*ca_array_put(DBR_LONG,128,COWin[27],COW);
                stat = stat*ca_put(DBR_STRING,COWin[28],(void *)&tmstr);
                sprintf(fname,"/home/diag/acmi2/ioc/COW/COW_%10.0f.txt",tsSec);
                printf("%s\n",fname);
                FILE *fout = fopen(fname,"w");
                fprintf(fout,"%d : COW Baseline\n",ARTXbase2);
                fprintf(fout,"%d : COW Peak\n",ARTXpeak2);
                fprintf(fout,"%d : COW FWHM\n",ARTXfwhm2);
                fprintf(fout,"%d : COW Index\n",ARTXindex2);
                fprintf(fout,"%d : COW Integral\n",ARTXintegral2);
                fprintf(fout,"%8.3f : COW Charge\n",ARTXq2);
                fprintf(fout,"%d : COW Timestamp\n",tsSec);
                for(i=0;i<16;i++){
                    fprintf(fout,"\n");
                    for(j=0;j<7;j++){
                        fprintf(fout,"%6.0f,",COW[8*i+j]);
                    }
                    fprintf(fout,"%6.0f",COW[8*i+7]);
                }
                fclose(fout);
            }
            ca_pend_io(5);

            if(faultLatch!=0 && pmlatch==0){
                pmlatch = 1;
                stat = stat*ca_put(DBR_FLOAT,PM[0],(void *)&ARTXq1);
                stat = stat*ca_put(DBR_LONG,PM[1],(void *)&ARTXintegral1);
                stat = stat*ca_put(DBR_LONG,PM[2],(void *)&ARTXpeak1);
                stat = stat*ca_put(DBR_LONG,PM[3],(void *)&ARTXfwhm1);
                stat = stat*ca_put(DBR_LONG,PM[4],(void *)&ARTXindex1);
                stat = stat*ca_put(DBR_LONG,PM[5],(void *)&ARTXbase1);
                stat = stat*ca_array_put(DBR_LONG,72,PM[6],Beam);
                printf("accum=%f  accumQ=%f\n",accum,accumQ);
                stat = stat*ca_put(DBR_FLOAT,PM[7],(void *)&accumQ);
                stat = stat*ca_put(DBR_LONG,PM[8],(void *)&accum);
                stat = stat*ca_array_put(DBR_FLOAT,accLen,PM[9],AccQ);

                stat = stat*ca_put(DBR_FLOAT,PM[10],(void *)&ARTXq2);
                stat = stat*ca_put(DBR_LONG,PM[11],(void *)&ARTXintegral2);
                stat = stat*ca_put(DBR_LONG,PM[12],(void *)&ARTXpeak2);
                stat = stat*ca_put(DBR_LONG,PM[13],(void *)&ARTXfwhm2);
                stat = stat*ca_put(DBR_LONG,PM[14],(void *)&ARTXindex2);
                stat = stat*ca_put(DBR_LONG,PM[15],(void *)&ARTXbase2);
                stat = stat*ca_array_put(DBR_LONG,128,PM[16],(void *)&COW);
                ca_pend_io(5);
            }else if(faultLatch==0 && pmlatch==1){
                pmlatch = 0;
            }
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

