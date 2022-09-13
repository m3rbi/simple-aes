#ifndef SIMPLE_AES_GALOIS_H
#define SIMPLE_AES_GALOIS_H


const unsigned char forward_rijndael_matrix[] = {
    2, 3, 1, 1,
    1, 2, 3, 1,
    1, 1, 2, 3,
    3, 1, 1, 2
};


const unsigned char backwards_rijndael_matrix[] = {
    14, 11, 13, 9,
    9, 14, 11, 13,
    13, 9, 14, 11,
    11, 13, 9, 14
};


#endif
