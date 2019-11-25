#include "Integer.h"

Integer::Integer(int value) {
    this->_val = value;
}

int Integer::val() {
    return this->_val;
}

void Integer::set_val(const int &value) {
    this->_val = value;
}

json_object * Integer::parse(const char * ch, int length) {
    json_object * _json_integer;

    std::string _sub;
    while(1) {
        if ('0' <= ch[_index] && ch[_index] <= '9')
            _sub += ch[_index];
        else
            break;
        _index++;
    }

    _json_integer = new Integer(stoi(_sub));
    return _json_integer;
}

json_object::_type Integer::type() {
    return INT;
}

std::string Integer::to_string() {
    return std::to_string(this->_val);
}
