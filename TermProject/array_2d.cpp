#include <iostream>
#include <vector>
#include "array_2d.h"
#include "color_block.h"

int array_2d::score = 0;
block * array_2d::block_array[W][H] = {0,};
bool array_2d::can_visit[W][H] = {0,};

array_2d::array_2d() {
    array_2d::score = 0;

    int i = 0, j = 0;
    for (i = 0; i < H; ++i) {
        for (j = 0; j < W; ++j) {
            block_array[j][i] = new block(0);
            block_array[j][i]->set_location(j, i);
        }
    }
}

bool array_2d::can_make(int type) {          
    bool res = false;

    if (type == 1) {
        if (block_array[2][1]->get_color() == 0 &&
            block_array[2][0]->get_color() == 0 &&
            block_array[1][0]->get_color() == 0)
            res = true;
    }
    if (type == 2) {
        if (block_array[2][0]->get_color() == 0 &&
            block_array[2][1]->get_color() == 0 &&
            block_array[2][2]->get_color() == 0)
            res = true;
    }
    if (type == 3) {
        if (block_array[2][0]->get_color() == 0 &&
            block_array[2][1]->get_color() == 0 &&
            block_array[2][2]->get_color() == 0 &&
            block_array[1][1]->get_color() == 0 &&
            block_array[3][1]->get_color() == 0)
            res = true;
    }

    return res;
}

void array_2d::delete_block(int x, int y) {
    block_array[x][y]->~block();
}

void array_2d::insert(vector<block *> v) {
    int idx = 0;
    for (auto& idx : v) {
        insert(idx->get_x(), idx->get_y(), idx);
    }
}

void array_2d::insert(int x, int y, block *b) {
    block_array[x][y] = b;
}

void array_2d::check_visit(int x, int y, bool state) {
    can_visit[x][y] = state;
}

bool array_2d::visit_check(int x, int y) {
    return can_visit[x][y];
}

block* array_2d::get_block(int x, int y) {
    return block_array[x][y];
}

bool array_2d::can_move(int x, int y) {
    if (x < 0 || W <= x) return false;
    if (y < 0 || H <= y) return false;
    if (visit_check(x, y)) return false;

    return true;
}

void array_2d::print() {

    int i = 0, j = 0;
    for (i = 0; i < H; ++i) {
        for (j = 0; j < W; ++j) {
            cout << (int)(get_block(j, i)->get_color()) << " ";
        }
        cout << "\n";
    }
}

void array_2d::insert_explosion(color_block *group) {  

}

void array_2d::remove_explosion(color_block *group) {   

}

bool array_2d::can_explosion() {                   




    return true;
}

void array_2d::explosion() {                       

}

int array_2d::get_score() {
    return score;
}

vector<block *> array_2d::gravity(vector<block *> v) {

    for (auto& idx : v) {
        while(1) {
            if (!can_move(idx->get_x(), idx->get_y() + 1)) break;
            if (block_array[idx->get_x()][idx->get_y() + 1]->get_color() != 0) break;

            int x = idx->get_x();
            int y = idx->get_y();

            idx = new block(idx->get_color());
            idx->set_location(x, y + 1);

            delete_block(x, y);
        }
        insert(v);
    }

    return v;
}

