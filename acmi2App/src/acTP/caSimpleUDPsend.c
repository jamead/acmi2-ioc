#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdint.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include "cadef.h"

#define PREFIX "LN-BI{ACMI:A}"
#define PORT 12345
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

void ArrToByte(const int *Array, size_t ArraySize, unsigned char *byteArray){
    // Copy the memory of the integer array into the byte array
    memcpy(byteArray, Array, ArraySize * sizeof(int));
}

int main() {
    int sockfd,TP3[72],stat=0,i;
    struct sockaddr_in server_addr;
    char binary_data[289]; // Example binary data

    while(1==1){
        if(stat!=1){
            stat = initialize_pvs();
            // Create a UDP socket
            sockfd = socket(AF_INET, SOCK_DGRAM, 0);
            if (sockfd < 0) {
                perror("Socket creation failed");
                exit(EXIT_FAILURE);
            }
            // Configure server address
            memset(&server_addr, 0, sizeof(server_addr));
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(PORT); // Replace with your desired port
            server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        }

        stat = stat*ca_array_get(DBR_LONG,72,PV[0],(void *)&TP3);
        ca_pend_io(5);
        ArrToByte(TP3,72,binary_data);
        for(i=20;i<60;i++){
            printf("TP3[%d]=%d\n",i,TP3[i]);
        }
        // Send binary data
        ssize_t sent_bytes = sendto(sockfd, binary_data, sizeof(binary_data), 0,
                                (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (sent_bytes < 0) {
            perror("Failed to send data");
            close(sockfd);
            exit(EXIT_FAILURE);
        }

        printf("Sent %zd bytes of binary data\n", sent_bytes);

        // Close the socket
        if(stat!=1){
            close(sockfd);
        }
        usleep(1000000); 
    }
    return 0;
}

