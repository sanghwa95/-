
#include "json_list.h"
#include "json_dict.h"
#include "data/Integer.h"
#include "data/String.h"

json_list::json_list() {

}

json_object * json_list::parse(const char * ch, int length) {
    _index++;
    json_list *_json_list = new json_list();
    int count = 0;

    while (_index < length) {
        char c = ch[_index];

        if (c == ':' || c == ' ' || c == '}') {
            _index++;
            continue;
        }
        else if (c == ',') {
            count++;
            _index++;
            continue;
        }
        else if (c == ']') {
            _index++;
            if (count == _json_list->v.size() && count != 0)
                _json_list->v.emplace_back(nullptr);

            if (_json_list->v.empty())
                _json_list->v.emplace_back(nullptr);

            return _json_list;
        }
        else if (c == '[') {
            _json_list->v.emplace_back(json_list::parse(ch, length));
        }
        else if (c == '{') {
            _json_list->v.emplace_back(json_dict::parse(ch, length));
        }
        else if ('0' <= c && c <= '9') {
            _json_list->v.emplace_back(Integer::parse(ch, length));
        }
        else if (c == '"' || c == '\'') {
            _json_list->v.emplace_back(String::parse(ch, length, ch[_index]));
        }
        else {
            _index++;
            continue;
        }
    }

    return _json_list;
}

json_object * json_list::operator[](int key) const {
    return this->v[key];
}

json_object::_type json_list::type() {
    return LIST;
}

std::string json_list::to_string() {
    if (v[0] == nullptr)
        return "[]";

    std::string _sub = "[";

    for (auto& iter : v) {
        if (iter != nullptr) {
            _sub += iter->to_string();
            _sub += ", ";
        }
        else
            _sub += " ";
    }

    _sub.pop_back();
    _sub.pop_back();

    return _sub + "]";
}

