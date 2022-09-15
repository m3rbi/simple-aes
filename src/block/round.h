#ifndef SIMPLE_AES_ROUND_H
#define SIMPLE_AES_ROUND_H

#include <stdbool.h>
#include "block.h"
#include "round_key.h"


bool do_initial_round(state_block_t state_block, state_key_t state_key);


bool do_main_round(state_block_t state_block, state_key_t state_key);


bool do_final_round(state_block_t state_block, state_key_t state_key);


#endif
