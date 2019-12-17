#ifndef FOLD_BLOCK_H
#define FOLD_BLOCK_H

#include "color_block.h"
#include "big_block.h"
#include "array_2d.h"


class fold_block: public big_block {
public:
    fold_block(int c1, int c2, int c3);
    void rotate();
};

#endif 


