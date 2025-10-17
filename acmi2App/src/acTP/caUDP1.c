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
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT     8080
#define MAXLINE 1024

#define PREFIX "LN-BI{ACMI:A}"

chid PV[30];

int initialize_pvs()
{
    int status;
    char pvname[100];

    status = ca_context_create(ca_disable_preemptive_callback);
// System Input PVs:
    strcpy(pvname,PREFIX);
    strcat(pvname,"TP3-Wfm");
    status = status*ca_create_channel(pvname,NULL,NULL,0,&PV[0]);

    ca_pend_io(5);
    return(status);
}

void intArrayToByteArray(const int *intArray, size_t intArraySize, unsigned char *byteArray){
    // Copy the memory of the integer array into the byte array
    memcpy(byteArray, intArray, intArraySize * sizeof(int));
}


int main()
{
    int TP1[72]={0}, stat=0, i;
    size_t intArrSize=sizeof(TP1)/sizeof(int);
    unsigned char byteArray[intArrSize*sizeof(int)];
    int sockfd,len,n;
    char buffer[MAXLINE];
    char *pvdata = "pvdata";
    struct sockaddr_in servaddr, cliaddr;

    while(1==1){
        if(stat!=1){
            stat = initialize_pvs();
            usleep(1000000);
            if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
                perror("socket creation failed");
                exit(EXIT_FAILURE);
            }
            memset(&servaddr, 0, sizeof(servaddr));
            memset(&cliaddr, 0, sizeof(cliaddr));
            // Filling server information
            servaddr.sin_family = AF_INET; // IPv4
            servaddr.sin_addr.s_addr = INADDR_ANY;
            servaddr.sin_port = htons(PORT);
            // Bind the socket with the server address
            if ( bind(sockfd, (const struct sockaddr *)&servaddr,
                        sizeof(servaddr)) < 0 )
            {
                perror("bind failed");
                exit(EXIT_FAILURE);
            }
            len = sizeof(cliaddr); //len is value/result
        }
        stat = stat*ca_array_get(DBR_LONG,72,PV[0],(void *)&TP1);
        ca_pend_io(5);

        intArrayToByteArray(TP1, intArrSize, byteArray);

        for(i=0;i<4;i++){
            printf("byteArray[%d] = %d\n",i,byteArray[i]);
        }
       	n = recvfrom(sockfd, (char *)buffer, MAXLINE,
                                MSG_WAITALL, ( struct sockaddr *) &cliaddr,
                                &len);
        buffer[n] = '\0';
        printf("Client : %s\n", buffer);
        sendto(sockfd, (const char *)byteArray, strlen(byteArray),
                MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
                        len);
        printf("Hello message sent.\n");

        usleep(800000);
    }
}
