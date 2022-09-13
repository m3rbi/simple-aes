#include "mix_column.h"
#include "block.h"


static const unsigned char forward_rijndael_matrix[BLOCK_ROWS * BLOCK_COLS] = {
    2, 3, 1, 1,
    1, 2, 3, 1,
    1, 1, 2, 3,
    3, 1, 1, 2
};


static const unsigned char backwards_rijndael_matrix[BLOCK_ROWS * BLOCK_COLS] = {
    14, 11, 13, 9,
    9, 14, 11, 13,
    13, 9, 14, 11,
    11, 13, 9, 14
};


/*******************************************************************
 * Gets the wanted rijndael matrix according to the encryption direction.
 * 
 * @param aes_direction -   direction of encryption.
 *
 * @returns - rijndael matrix suited for the specified direction.
*******************************************************************/
static const unsigned char *get_rijndael_matrix(aes_direction_t aes_direction)
{
    if (AES_DIRECTION_ENCRYPT == aes_direction) {
        return forward_rijndael_matrix;
    }

    return backwards_rijndael_matrix;
}


/*******************************************************************
 * Multiplies two one-byte integers inside of the  Rijndael's galois 
 * finite field (2 ^ 8).
 * 
 * @param a -   first number to be multiplied.
 * @param b -   second integer to be multiplied.
 *
 * @returns - result of the multiplication inside of the GF.
*******************************************************************/
static unsigned char galois_multiply(unsigned char a, unsigned char b)
{
    unsigned char result = 0;

    for (int i = 0; i < 8; i++) {
        if ((b & 1) != 0) {
            result ^= a;
        }

        bool is_high_bit_set = ((a & 0x80) != 0);

        a <<= 1;
        if (is_high_bit_set) {
            a ^= 0x1b;
        }

        b >>= 1;
    }

    return result;
}


/*******************************************************************
 * Multiplies one column with specified matrix inside of Rijndael's
 * Galois field.
 * 
 * @param column -          pointer to column to be mixed.
 * @param rijndael_matrix - specified matrix to multiply the column 
 *                          with.
 *
 * @returns - mixed column.
*******************************************************************/
static void mix_single_column(unsigned char *column, const unsigned char *rijndael_matrix)
{
    unsigned char tmp_column[BLOCK_ROWS] = { 0, 0, 0, 0 };

    for (int i = 0; i < BLOCK_ROWS; i++) {
        tmp_column[i] = 0;
        
        for (int j = 0; j < BLOCK_COLS; j++) {
            tmp_column[i] ^= galois_multiply(rijndael_matrix[i * BLOCK_COLS + j], column[j]);
        }
    }

    for (int i = 0; i < BLOCK_ROWS; i++) {
        column[i] = tmp_column[i];
    }
}


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
bool do_mix_columns_stage(state_block_t state_block)
{
    const unsigned char *rijndael_matrix = get_rijndael_matrix(state_block.aes_direction);

    for (int i = 0; i < BLOCK_COLS; i++) {
        mix_single_column(state_block.block + (i * BLOCK_COLS), rijndael_matrix);
    }

    return true;
}
