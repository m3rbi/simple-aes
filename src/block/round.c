#include "block.h"
#include "round.h"
#include "round_key.h"
#include "sub_bytes.h"
#include "shift_rows.h"
#include "mix_column.h"


bool do_initial_round(state_block_t state_block, state_key_t state_key)
{
    return do_round_key_stage(state_block, state_key);
}


bool do_main_round(state_block_t state_block, state_key_t state_key)
{
    if (!do_sub_bytes_stage(state_block)) {
        return false;
    }
    
    if (!do_shift_rows_stage(state_block)) {
        return false;
    }

    if (!do_mix_columns_stage(state_block)) {
        return false;
    }

    return do_round_key_stage(state_block, state_key);
}


bool do_final_round(state_block_t state_block, state_key_t state_key)
{
    if (!do_sub_bytes_stage(state_block)) {
        return false;
    }
    
    if (!do_shift_rows_stage(state_block)) {
        return false;
    }

    return do_round_key_stage(state_block, state_key);
}
