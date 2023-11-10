#include <stdint.h>

#include "../headers/encoding.h"
#include "../headers/utils.h"
#include "../headers/drv_api.h"

#define COMODO_LENGTH sizeof()

// struct comodo_message_t {
//     enum_bool_t cmdWarning;
//     enum_bool_t cmdPositionLights;
//     enum_bool_t cmdLowBeam;
//     enum_bool_t cmdHighBeam;
//     enum_bool_t cmdRightIndicator;
//     enum_bool_t cmdLeftIndicator;
//     enum_bool_t cmdWipers;
//     enum_bool_t cmdWasher;
// };
// struct mux_message_t {
//     uint8_t tramNumber;
//     uint8_t mileage;
//     uint8_t speed;
//     chassis_problem_t chassisProblem;
//     motor_problem_t motorProblem;
//     battery_problem_t batteryProblem;
//     uint8_t fuelLevel;
//     uint8_t turnsPerMinute; 
//     uint8_t crc8;
// };

void decodeComodoMessage(struct comodo_message_t *comodoMessage, const uint8_t *message) {
    comodoMessage->cmdWarning = message[0];
    comodoMessage->cmdPositionLights = message[1];
    comodoMessage->cmdLowBeam = message[2];
    comodoMessage->cmdHighBeam = message[3];
    comodoMessage->cmdRightIndicator = message[4];
    comodoMessage->cmdLeftIndicator = message[5];
    comodoMessage->cmdWipers = message[6];
    comodoMessage->cmdWasher = message[7];
}

void decodeMuxMessage(int32_t drvFd, struct mux_message_t *muxMessage, const uint8_t *message) {
    
    uint8_t udpFrame[DRV_UDP_100MS_FRAME_SIZE];

    while (drv_read_udp_100ms(drvFd, udpFrame) != DRV_ERROR) {
        muxMessage->tramNumber = message[0];
        muxMessage->mileage = message[1];
        muxMessage->speed = message[2];
        muxMessage->chassisProblem = message[3];
        muxMessage->motorProblem = message[4];
        muxMessage->batteryProblem = message[5];
        muxMessage->fuelLevel = message[6];
        muxMessage->turnsPerMinute = message[7];
        muxMessage->crc8 = message[8];
    }
}