#ifndef UDP_H
#define UDP_H

/**
 * @file udp.h
 * @brief Functions and declarations related to UDP communication.
 */

#include <stdint.h>

/**
 * @brief Display the contents of an UDP frame.
 *
 * This function displays the contents of an UDP frame, which is an array of bytes.
 *
 * @param udpFrame Pointer to the UDP frame data.
 */
void displayUdpFrame(uint8_t *udpFrame);

#endif
