#include <stdio.h>

#include "headers/udp.h"
#include "headers/drv_api.h"

int main(){
    
    int32_t drvFd = drv_open();

    if (drvFd < 0){
        perror("Error while trying to open the driver.");
        return 1;
    }

    uint8_t udpFrame[DRV_UDP_100MS_FRAME_SIZE];

    while (drv_read_udp_100ms(drvFd, udpFrame) != DRV_ERROR) {
        displayUdpFrame(udpFrame);
    } 

    while (1){
        if(drv_close(drvFd) == DRV_SUCCESS){
            break;
        }
    }

    return 0;
}


