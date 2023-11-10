#ifndef ENCODING_H
#define ENCODING_H

#include <stdint.h>

#include "utils.h"

void decodeComodoMessage(struct comodo_message_t *comodoMessage, const uint8_t *message);
void decodeMuxMessage(struct mux_message_t *muxMessage, const uint8_t *message);


#endif