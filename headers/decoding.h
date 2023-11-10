/**
 * @file decoding.h
 * @brief Header file containing function declarations for decoding messages.
 */

#ifndef DECODING_H
#define DECODING_H

#include <stdint.h>

#include "generated_code.h"

/**
 * @brief Decode a 1-bit message into a comodo_message_t structure.
 *
 * This function decodes a 1-bit message into a comodo_message_t structure,
 * where each bit in the message corresponds to a specific field in the structure.
 *
 * @param message Pointer to the input message.
 */
void decodecomodo(const uint8_t *message);

/**
 * @brief Decode a 15-bit message into a mux_message_t structure.
 *
 * This function decodes a 15-bit message into a mux_message_t structure,
 * where the message is packed into specific fields in the structure.
 *
 * @param message Pointer to the input message.
 */
void decodemux(const uint8_t *message);

#endif