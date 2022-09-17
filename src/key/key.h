#ifndef SIMPLE_AES_KEY_H
#define SIMPLE_AES_KEY_H


typedef enum aes_keysize_t {
    KEYSIZE_AES128 = 16,
    KEYSIZE_AES192 = 24,
    KEYSIZE_AES256 = 32
} aes_keysize_t;


// typedef struct aes128_key_buffer_t {
//     unsigned char key[KEYSIZE_AES128];
//     unsigned char next_key[KEYSIZE_AES128];
// } aes128_key_buffer_t;

typedef struct aes_key_state_t {
    aes_keysize_t key_size;
    
    union {
        struct {
            unsigned char key[KEYSIZE_AES128];
            unsigned char next_key[KEYSIZE_AES128];
        } aes128_key_buffer_t;

        struct {
            unsigned char key[KEYSIZE_AES192];
            unsigned char next_key[KEYSIZE_AES192];
        } aes192_key_buffer_t;

        struct {
            unsigned char key[KEYSIZE_AES256];
            unsigned char next_key[KEYSIZE_AES256];
        } aes256_key_buffer_t;
        
    } key_buffer;

} aes_key_state_t;

#endif
