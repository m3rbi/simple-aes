#include "sub_bytes.h"
#include "../consts/sbox.h"


/*******************************************************************
 * Gets the wanted sbox according to the encryption direction.
 * 
 * @param aes_direction -   direction of encryption.
 *
 * @returns - sbox suited for the specified direction.
*******************************************************************/
static const unsigned char *get_sbox(aes_direction_t aes_direction)
{
    if (AES_DIRECTION_ENCRYPT == aes_direction) {
        return forward_sbox;
    }

    return backward_sbox;
}


/*******************************************************************
 * Perform the byte substitution step where each byte is 
 * replaced with another according to a lookup table.
 * 
 * @param state_block - specified block to perform stage on.
 *                      The stage is performed on the same memory.
 * 
 * @returns - true if stage was successfull, false otherwise.
*******************************************************************/
bool do_sub_bytes_stage(state_block_t state_block)
{
    const unsigned char *sbox = get_sbox(state_block.aes_direction);

    for (int i = 0; i < BLOCK_SIZE; i++) {
        state_block.block[i] = sbox[state_block.block[i]];
    }

    return true;
}
