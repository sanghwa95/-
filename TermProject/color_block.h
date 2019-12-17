#ifndef COLOR_BLOCK_H
#define COLOR_BLOCK_H

#include <vector>

using namespace std;

class block;
class color_block {
private:

    static vector<block *> s;                
public:
    color_block(block * b);
    static void insert(vector<block *> s);
    vector<block *> get_set();
    int get_set_size();
    void explosion();

};

#endif

