#ifndef SIMPLE_AES_ROUND_KEY_H
#define SIMPLE_AES_ROUND_KEY_H

#include <stdbool.h>
#include "block.h"


typedef struct state_key_t {
    unsigned char *state_key;
} state_key_t;


/*******************************************************************
 * Perform the round key step, where each byte of the state is 
 * combined with a round key using bitwise xor.
 * 
 * @param state_block   -   specified block to perform stage on.
 *                          The stage is performed on the same memory.
 * @param state_key     -   specified key for current round.
 * 
 * @returns - true if stage was successfull, false otherwise.
*******************************************************************/
bool do_round_key_stage(state_block_t state_block, state_key_t state_key);


#endif
