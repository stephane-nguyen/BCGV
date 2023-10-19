#include <stdint.h>

#include "../headers/drv_api.h"
#include "../headers/udp.h"

void displayUdpFrame(uint8_t *udpFrame){
    for (int i=0; i < DRV_UDP_100MS_FRAME_SIZE; i++) {
        printf("MUX frame sent from UDP: %d \n", udpFrame[i]);
    }
}