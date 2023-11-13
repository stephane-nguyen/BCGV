#pragma once

void encodeFrame(uint8_t *frame, message_t message, uint8_t expectedMessageID, const char *errorMessage);
void encodeBCGVtoBGF1(uint8_t *frame, message_t message);
void encodeBCGVtoBGF2(uint8_t *frame, message_t message);
void encodeBCGVtoBGF3(uint8_t *frame, message_t message);
void encodeBCGVtoBGF4(uint8_t *frame, message_t message);
void encodeBCGVtoBGF5(uint8_t *frame, message_t message);
void encodeBCGVtoMux(uint8_t *frame, message_t message);