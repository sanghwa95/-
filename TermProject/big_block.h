#ifndef BIG_BLOCK_H
#define BIG_BLOCK_H

#include <vector>
#include "block.h"

using namespace std;

class big_block {
protected:
    static int rotate_number;
    vector<block *> v;
    static int min_x, min_y, max_x, max_y;
public:
    ~big_block();
    virtual void rotate();
    bool can_left();
    bool can_right();
    bool can_down();
    void left();
    void right();
    void down();
    void down_all();
    bool move();
    bool met_floor();
};

#endif


