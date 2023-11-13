#include "decoding.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "drv_api.h"
#include "generated_code.h"

void decodecomodo(const uint8_t *message) {
    comodo_message_t comodo;

    comodo.cmdWarning = (message[0] & (1 << 0)) ? TRUE : FALSE;
    comodo.cmdPositionLights = (message[0] & (1 << 1)) ? TRUE : FALSE;
    comodo.cmdLowBeam = (message[0] & (1 << 2)) ? TRUE : FALSE;
    comodo.cmdHighBeam = (message[0] & (1 << 3)) ? TRUE : FALSE;
    comodo.cmdRightIndicator = (message[0] & (1 << 4)) ? TRUE : FALSE;
    comodo.cmdLeftIndicator = (message[0] & (1 << 5)) ? TRUE : FALSE;
    comodo.cmdWipers = (message[0] & (1 << 6)) ? TRUE : FALSE;
    comodo.cmdWasher = (message[0] & (1 << 7)) ? TRUE : FALSE;

    // Create a static array of serial_frame_t to hold the comodo message
    serial_frame_t serialData[DRV_MAX_FRAMES];
    serialData[0].frameSize = sizeof(comodo_message_t);
    memcpy(serialData[0].frame, &comodo, sizeof(comodo_message_t));

    // set_comodoData(comodo);

    int32_t drvFd = drv_open(); 
    int32_t result = drv_write_ser(drvFd, serialData, 1); 
    drv_close(drvFd); 

    if (result == DRV_ERROR) {
        perror("Error while writing the serial frame");
    } 
}



void decodemux(const uint8_t *message) {
    uint8_t udpFrame[DRV_UDP_100MS_FRAME_SIZE];
    mux_message_t mux;

    int32_t drvFd = drv_open();

    if (drvFd == DRV_ERROR){
        perror("Error while trying to open the driver.");
        return;
    }

    while (drv_read_udp_100ms(drvFd, udpFrame) != DRV_ERROR) {
        mux.tramNumber = message[0];
        mux.mileage = (uint32_t)((message[1] << 24) | (message[2] << 16) | (message[3] << 8) | message[4]);
        mux.speed = message[5];
        mux.chassisProblem = message[6];
        mux.motorProblem = message[7];
        mux.batteryProblem = message[8];
        mux.fuelLevel = message[9];
        mux.turnsPerMinute = (uint32_t)((message[10] << 24) | (message[11] << 16) | (message[12] << 8) | message[13]);        
        mux.crc8 = message[14];

        (void)mux;
        // set_muxData(mux);
    }
}