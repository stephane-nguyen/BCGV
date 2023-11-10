// #include <stdint.h>

// #include "decoding.h"
// #include "utils.h"
// #include "generated_code.h"

// #define POSITION_LIGHT_MESSAGE_ID 0x01 
// #define LOW_BEAM_MESSAGE_ID 0x02
// #define HIGH_BEAM_LIGHT_MESSAGE_ID 0x03
// #define RIGHT_INDICATOR_MESSAGE_ID 0x04
// #define LEFT_INDICATOR_MESSAGE_ID 0x05

// void encodeBCGVtoBGF1(uint8_t *frame, message_t message) {
//     if(message.id == POSITION_LIGHT_MESSAGE_ID){
//         frame[0] = message.id
//         frame[1] = message.lightState; 
//     } else{
//         perror("Wrong light message");
//     }
// }

// void encodeBCGVtoBGF2(uint8_t *frame, message_t message) {
//     frame[0] = message.id
//     frame[1] = message.lightState; 
// }

