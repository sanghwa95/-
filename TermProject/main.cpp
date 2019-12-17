#include <iostream>
#include <thread>
#include <time.h>
#include "array_2d.h"
#include "tree_block.h"
#include "fold_block.h"
#include "cross_block.h"
#include "color_block.h"

using namespace std;

array_2d * board = new array_2d();
big_block * _fold_block;
big_block * _tree_block;
big_block * _cross_block;
big_block * target;

bool do_you_need_the_new_block = false;

void print_status() {
    cout << "score: " << board->get_score() << '\n';
    board->print();
}

void print_init() {
    print_status();
    this_thread::sleep_for(chrono::duration<int>(1));
    cout << "  start  " << '\n';
    this_thread::sleep_for(chrono::duration<int>(1));
}

void key_event() {
    cout << "input : ";
    string control;
    getline(cin, control);

    if (control == "a" && target->can_left()) {    // moving left
        target->left();
    }
    if (control == "d" && target->can_right()) {    // moving right
        target->right();
    }
    if (control == "s") {    // moving down (one step)
        if (target->can_down()) target->down();
        else do_you_need_the_new_block =true;

    }
    if (control == "x") {    // moving down till can't move down.
        if (target->can_down()) target->down_all();
        else do_you_need_the_new_block = true;

    }
    if (control == "e") {    // rotating clockwise
        target->rotate();
    }

    if(do_you_need_the_new_block) {
        target->move();
        target->~big_block();
    }

}

int color() {
    int c = rand() % 4 + 1;
    return c;
}

// every times, at (row: 2, col: 3)
// if you can make the block, that return true.
bool create_block() {
    int res = 0;
    int b = rand() % 3 + 1;

    if (b == 1 && board->can_make(1)) {       // get fold block
        _fold_block = new fold_block(color(), color(), color());
        target = _fold_block;
        res++;
    }
    if (b == 2 && board->can_make(2)) {       // get tree block
        _tree_block = new tree_block(color(), color(), color());
        target = _tree_block;
        res++;
    }
    if (b == 3 && board->can_make(3)) {       // get cross block
        _cross_block = new cross_block(color(), color(), color(), color(), color());
        target = _cross_block;
        res++;
    }

    return res;
}

void start() {
    srand((unsigned int)time(0));

//    print_init();
    while (1) {

        if (!create_block()) break;
        do_you_need_the_new_block = false;

        while (1) {
            print_status();
            key_event();
            if (do_you_need_the_new_block) break;

        }

    }
}

int main() {
    //srand((unsigned int)time(0));
    // for testing func.
    {
        start();
    }
    return 0;
}

