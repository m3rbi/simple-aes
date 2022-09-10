#ifndef SIMPLE_AES_SHIFT_ROWS_H
#define SIMPLE_AES_SHIFT_ROWS_H

#include <stdbool.h>
#include "block.h"


/*******************************************************************
 * Perform the shift rows step where the last three rows of the state
 * are shifted cyclically a certain number of steps.
 * 
 * @param state_block - specified block to perform stage on.
 *                      The stage is performed on the same memory.
 * 
 * @returns - true if stage was successfull, false otherwise.
*******************************************************************/
bool do_shift_rows_stage(state_block_t state_block);


#endif
