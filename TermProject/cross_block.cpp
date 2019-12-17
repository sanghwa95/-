#include "cross_block.h"

cross_block::cross_block(int c1, int c2, int c3, int c4, int c5) {
    block * _part1 = new block(c1);
    _part1->set_location(2, 2);

    block * _part2 = new block(c2);
    _part2->set_location(2, 1);

    block * _part3 = new block(c3);
    _part3->set_location(2, 0);

    block * _part4 = new block(c4);
    _part4->set_location(1, 1);

    block * _part5 = new block(c5);
    _part5->set_location(3, 1);

    big_block::v.push_back(_part1);
    big_block::v.push_back(_part2);
    big_block::v.push_back(_part3);
    big_block::v.push_back(_part4);
    big_block::v.push_back(_part5);

    array_2d::insert(big_block::v);
}

void cross_block::rotate() {

    block * _part1 = big_block::v.at(0);
    block * _part2 = big_block::v.at(1);
    block * _part3 = big_block::v.at(2);
    block * _part4 = big_block::v.at(3);
    block * _part5 = big_block::v.at(4);


    big_block::v.clear();

    int _x1 = _part1->get_x();
    int _y1 = _part1->get_y();
    int _x3 = _part3->get_x();
    int _y3 = _part3->get_y();
    int _x4 = _part4->get_x();
    int _y4 = _part4->get_y();
    int _x5 = _part5->get_x();
    int _y5 = _part5->get_y();


    _part5->set_location(_x1, _y1);
    big_block::v.push_back(_part5);

    big_block::v.push_back(_part2);

    _part4->set_location(_x3, _y3);
    big_block::v.push_back(_part4);

    _part1->set_location(_x4, _y4);
    big_block::v.push_back(_part1);

    _part3->set_location(_x5, _y5);
    big_block::v.push_back(_part3);

    array_2d::insert(big_block::v);

}

