#ifndef SIMPLE_AES_MIX_COLUMN_H
#define SIMPLE_AES_MIX_COLUMN_H

#include <stdbool.h>
#include "block.h"


/*******************************************************************
 * Perform the mix columns step, a linear mixing operation which 
 * operates on the columns of the state, combining the four bytes in
 * each column.
 * 
 * @param state_block - specified block to perform stage on.
 *                      The stage is performed on the same memory.
 * 
 * @returns - true if stage was successfull, false otherwise.
*******************************************************************/
bool do_mix_columns_stage(state_block_t state_block);


#endif
