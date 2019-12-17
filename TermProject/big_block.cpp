#include "big_block.h"
#include "array_2d.h"
#include "color_block.h"
#include "block.h"

#include <iostream>
int big_block::min_x = 0;
int big_block::min_y = 0;
int big_block::max_x = 4;
int big_block::max_y = 11;
int big_block::rotate_number=0;

big_block::~big_block() {

    color_block::insert(this->v);
}
void big_block::rotate(){

}

bool big_block::can_left() {

    for (auto& idx : this->v) {
        if (!array_2d::can_move(idx->get_x() - 1, idx->get_y())) {
            return false;
        }
    }

    return true;
}

bool big_block::can_right() {

    for (auto& idx : this->v) {
        if (!array_2d::can_move(idx->get_x() + 1, idx->get_y())) {
            return false;
        }
    }

    return true;
}

bool big_block::can_down() {

    for (auto& idx : this->v) {
        if (!array_2d::can_move(idx->get_x(), idx->get_y() + 1)) {
            return false;
        }
    }

    return true;
}

void big_block::left() {
    vector<block *> mov_info;

    for (auto& idx : this->v) {
        mov_info.push_back(new block(idx->get_color()));
        mov_info.back()->block::set_location(idx->get_x() - 1, idx->get_y());
    }

    for (auto& idx : this->v)
        array_2d::delete_block(idx->get_x(), idx->get_y());
    this->v.clear();

    for (auto& idx : mov_info) {
        block * _new = new block(idx->get_color());
        _new->set_location(idx->get_x(), idx->get_y());
        this->v.push_back(_new);
    }

    array_2d::insert(this->v);

}

void big_block::right() {
    vector<block *> mov_info;

    for (auto& idx : this->v) {
        mov_info.push_back(new block(idx->get_color()));
        mov_info.back()->block::set_location(idx->get_x() + 1, idx->get_y());
    }

    for (auto& idx : this->v)
        array_2d::delete_block(idx->get_x(), idx->get_y());
    this->v.clear();

    for (auto& idx : mov_info) {
        block * _new = new block(idx->get_color());
        _new->set_location(idx->get_x(), idx->get_y());
        this->v.push_back(_new);
    }

    array_2d::insert(this->v);
}

void big_block::down() {
    vector<block *> mov_info;

    for (auto& idx : this->v) {
        mov_info.push_back(new block(idx->get_color()));
        mov_info.back()->block::set_location(idx->get_x(), idx->get_y() + 1);
    }

    for (auto& idx : this->v)
        array_2d::delete_block(idx->get_x(), idx->get_y());
    this->v.clear();

    for (auto& idx : mov_info) {
        block * _new = new block(idx->get_color());
        _new->set_location(idx->get_x(), idx->get_y());
        this->v.push_back(_new);
    }

    array_2d::insert(this->v);

}

void big_block::down_all() {

    while(this->can_down()) {
        vector<block *> mov_info;

        for (auto& idx : this->v) {
            mov_info.push_back(new block(idx->get_color()));
            mov_info.back()->block::set_location(idx->get_x(), idx->get_y() + 1);
        }

        for (auto& idx : this->v)
            array_2d::delete_block(idx->get_x(), idx->get_y());
        this->v.clear();

        for (auto& idx : mov_info) {
            block * _new = new block(idx->get_color());
            _new->set_location(idx->get_x(), idx->get_y());
            this->v.push_back(_new);
        }

        array_2d::insert(this->v);
    }
}

bool big_block::move() {
    vector<block *> mov_info = array_2d::gravity(this->v);

    for(auto& idx : mov_info)
        array_2d::check_visit(idx->get_x(), idx->get_y(), true);

    return 0;
}

bool big_block::met_floor() {
    int res = 0;

    for (auto& idx : this->v) {
        if (array_2d::visit_check(idx->get_x(), idx->get_y() + 1)
            || idx->get_y() == max_y) {
            res++;
        }
    }

    return res;
}



