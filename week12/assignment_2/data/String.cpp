#include "String.h"

String::String(const std::string &str) {
    this->_val = str;
}

std::string String::val() {
    return _val;
}

void String::set_val(const std::string& str) {
    this->_val = str;
}

json_object * String::parse(const char * ch, int length, char base) {
    _index++;
    json_object * _json_string;

    std::string _sub;
    while(ch[_index] != base) {
        _sub += ch[_index++];
    }
    _index++;

    _json_string = new String(_sub);
    return _json_string;
}

json_object::_type String::type() {
    return STRING;
}

std::string String::to_string() {
    return "'" + this->_val + "'";
}
