#ifndef ARRAY_2D_H
#define ARRAY_2D_H

#include <set>
#include "block.h"
#include "color_block.h"

using namespace std;

class array_2d {
private:
    static const int W = 5;
    static const int H = 12;
    static block * block_array[W][H];
    static bool can_visit[W][H];
    set<color_block *> explosion_s;
    static int score;
public:
    array_2d();
    bool can_make(int type);
    static void delete_block(int x, int y);
    static void insert(vector<block *> v);
    static void insert(int x, int y, block * b);
    static void check_visit(int x, int y, bool state);
    static bool visit_check(int x, int y);
    block *get_block(int x, int y);
    static bool can_move(int x, int y);
    void print();
    void insert_explosion(color_block * group);
    void remove_explosion(color_block * group);
    bool can_explosion();
    void explosion();
    int get_score();
    static vector<block *> gravity(vector<block *> v);

};

#endif
