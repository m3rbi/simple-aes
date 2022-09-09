#ifndef SIMPLE_AES_SUB_BYTES_H
#define SIMPLE_AES_SUB_BYTES_H

#include <stdbool.h>
#include "block.h"


/*******************************************************************
 * Perform the byte substitution step where each byte is 
 * replaced with another according to a lookup table.
 * 
 * @param state_block - specified block to perform stage on.
 *                      The stage is performed on the same memory.
 * 
 * @returns - true if stage was successfull, false otherwise.
*******************************************************************/
bool do_sub_bytes_stage(state_block_t state_block);


#endif
