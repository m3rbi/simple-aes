#include "shift_rows.h"
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
bool do_shift_rows_stage(state_block_t state_block)
{
    unsigned char temp_column[BLOCK_ROWS] = { 0, 0, 0, 0 };

    int direction_modifier = 1;
    if (AES_DIRECTION_DECRYPT == state_block.aes_direction) {
        direction_modifier = -1;
    }

    /* the layout of the matrix for the cipher is not
     * the most comfortable for us while we use an array
     * instead of a matrix. While our matrix is left-to-right
     * and then top-to-bottom, the cipher's matrix is 
     * top-to-bottom and then left-to-right.
     * therefore instead of shifting each row left
     * according to the algorithm, we need to shift each column
     * to the opposite direction (up), and vice versa for decryption.
     * 
     * The implementation runs from the second column to the left
     * and goes forward, each time iterating the rows in order to 
     * shift them up/down into a new array, then setting them back in place.
    **/
    for (int i = 1; i < BLOCK_COLS; i++) {  // columns
        // copying the current row in an offset
        for (int j = 0; j < BLOCK_ROWS; j++) {
            temp_column[j] = state_block.block[((j + (direction_modifier * i)) % BLOCK_ROWS) * BLOCK_ROWS + i];
        }

        for (int j = 0; j < BLOCK_ROWS; j++) {
            state_block.block[j * BLOCK_ROWS + i] = temp_column[j];
        }
    }

    return true;
}
