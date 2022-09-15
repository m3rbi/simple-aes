#ifndef SIMPLE_AES_BLOCK_H
#define SIMPLE_AES_BLOCK_H

#define BLOCK_COLS (4)
#define BLOCK_ROWS (4)
#define BLOCK_SIZE (16)


typedef enum aes_direction_t {
    AES_DIRECTION_ENCRYPT = 0,
    AES_DIRECTION_DECRYPT = 1
} aes_direction_t;


typedef struct state_block_t {
    unsigned char *block;
    aes_direction_t aes_direction;
} state_block_t;


#endif
