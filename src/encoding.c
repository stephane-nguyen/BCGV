#include <stdio.h>
#include <stdint.h>

#include "decoding.h"
#include "generated_code.h"

#define POSITION_LIGHT_MESSAGE_ID 0x01 
#define LOW_BEAM_MESSAGE_ID 0x02
#define HIGH_BEAM_LIGHT_MESSAGE_ID 0x03
#define RIGHT_INDICATOR_MESSAGE_ID 0x04
#define LEFT_INDICATOR_MESSAGE_ID 0x05

void encodeFrame(uint8_t *frame, message_t message, uint8_t expectedMessageID, const char *errorMessage) {
    if (message.id == expectedMessageID) {
        frame[0] = message.id;
        frame[1] = message.lightState; 
    } else {
        perror(errorMessage);
    }
}

void encodeBCGVtoBGF1(uint8_t *frame, message_t message) {
    encodeFrame(frame, message, POSITION_LIGHT_MESSAGE_ID, "Wrong light: Not the position light");
}

void encodeBCGVtoBGF2(uint8_t *frame, message_t message) {
    encodeFrame(frame, message, LOW_BEAM_MESSAGE_ID, "Wrong light: Not the low beam light");
}

void encodeBCGVtoBGF3(uint8_t *frame, message_t message) {
    encodeFrame(frame, message, HIGH_BEAM_LIGHT_MESSAGE_ID, "Wrong light: Not the high beam light");
}

void encodeBCGVtoBGF4(uint8_t *frame, message_t message) {
    encodeFrame(frame, message, RIGHT_INDICATOR_MESSAGE_ID, "Wrong light: Not the right indicator");
}

void encodeBCGVtoBGF5(uint8_t *frame, message_t message) {
    encodeFrame(frame, message, LEFT_INDICATOR_MESSAGE_ID, "Wrong light: Not the left indicator");
}

void encodeBCGVtoMux(uint8_t *frame, message_t message) {
    encodeFrame(frame, message, LEFT_INDICATOR_MESSAGE_ID, "Wrong light: Not the left indicator");
}
