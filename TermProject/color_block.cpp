#include "color_block.h"
#include <set>

using namespace std;

vector<block *> color_block::s;

color_block::color_block(block *b) {

}

void color_block::insert(std::vector<block *> v) { // insert set of color blocks in array_2d

    for(auto& idx : v) {
        s.push_back(idx);
    }

}

vector<block *> color_block::get_set() {
    return s;
}

int color_block::get_set_size() {
    return this->s.size();
}

void color_block::explosion() {

}


