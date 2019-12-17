#ifndef TREE_BLOCK_H
#define TREE_BLOCK_H

#include "block.h"
#include "array_2d.h"

class tree_block: public big_block {
public:
    tree_block(int c1, int c2, int c3);
    void rotate();
};

#endif 

