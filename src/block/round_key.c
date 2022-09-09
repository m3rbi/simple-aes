#include "round_key.h"


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
bool do_round_key_stage(state_block_t state_block, state_key_t state_key)
{
    for (int i = 0; i < BLOCK_SIZE; i++) {
        state_block.block[i] ^= state_key.state_key[i];
    }

    return true;
}
