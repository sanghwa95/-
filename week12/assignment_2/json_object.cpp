
#include "json_object.h"
#include "json_list.h"
#include "json_dict.h"
#include "data/Integer.h"
#include "data/String.h"

int json_object::_index = 0;

json_object * json_object::parse(const char * ch, int length) {
    json_object *_json_object;

    while (_index < length) {
        char c = ch[_index];

        if (c == ':' || c == ',' || c == ' ' || c == '}' || c == ']') {
            _index++;
            continue;
        }
        else if (c == '[') {
            _json_object = json_list::parse(ch, length);
        }
        else if (c == '{') {
            _json_object = json_dict::parse(ch, length);
        }
        else if ('0' <= c && c <= '9') {
            _json_object = Integer::parse(ch, length);
        }
        else if (c == '"' || c == '\'') {
            _json_object = String::parse(ch, length, *(ch+_index));
        }
        else {
            _index++;
            continue;
        }
    }

    return _json_object;
}

json_object * json_object::parse(const std::string& str) {
    json_object::_index = 0;
    return parse(str.c_str(), str.length());
}

json_object::_type json_object::type() {

}

std::string json_object::to_string() {

}





