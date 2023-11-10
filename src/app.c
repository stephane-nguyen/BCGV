#include <stdio.h>

#include "udp.h"
#include "drv_api.h"

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

    return 0;
}


