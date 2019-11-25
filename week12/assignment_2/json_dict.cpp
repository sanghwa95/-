
#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"

void json_dict::put(json_object *key, json_object *val) {
    int i = find(key);

    if (i < 0)
        v.emplace_back(std::make_pair(key, val));
    else
        v[i].second = val;
}

int json_dict::find(json_object *key) {

    for (int i = 0; i < v.size(); ++i) {
        if (v[i].first->to_string() == key->to_string())
            return i;
    }

    return -1;
}

json_dict::json_dict() {

}

json_object *json_dict::parse(const char * ch, int length) {
    _index++;
    json_dict *_json_dict = new json_dict();
    json_object * key = nullptr;
    json_object * value = nullptr;

    int control = 0;
    while (_index < length) {
        char c = ch[_index];

        if (c == ' ' || c == ']') {
            _index++;
            continue;
        }
        else if (c == ':') {
            _index++;
            control = 1;
        }
        else if (c == ',') {
            _index++;
            control = 0;
            _json_dict->put(key, value);
        }
        else if (c == '}') {
            _index++;
            _json_dict->put(key, value);
            return _json_dict;
        }
        else if (c == '[') {
            value = json_list::parse(ch, length);
        }
        else if (c == '{') {
            value = json_dict::parse(ch, length);
        }
        else if ('0' <= c && c <= '9') {
            if (control)
                value = Integer::parse(ch, length);
            else
                key = Integer::parse(ch, length);
        }
        else if (c == '"' || c == '\'') {
            if (control)
                value = String::parse(ch, length, *(ch+_index));
            else
                key = String::parse(ch, length, *(ch+_index));
        }
        else {
            _index++;
            continue;
        }
    }

    return _json_dict;
}

json_object *json_dict::operator[](json_object *key) const {
    int i = 0;
    for (; i < v.size(); i++) {
        if (v[i].first->to_string() == key->to_string()) {
            v[i].second;
        }
    }
    return nullptr;
}

json_object *json_dict::operator[](const std::string &key) const {
    int i = 0;
    std::string str;
    for (; i < v.size(); i++) {
        if (v[i].first->type() == 3) {
            str = dynamic_cast<String*>(v[i].first)->val();
            if (str == key) {
                return v[i].second;
            }
        }
    }
    return nullptr;
}

json_object *json_dict::operator[](int key) const {
    int i = 0;
    int temp;
    for (; i < v.size(); i++) {
        if (v[i].first->type() == 2) {
            temp = dynamic_cast<Integer*>(v[i].first)->val();
            if (temp == key) {
                return v[i].second;
            }
        }
    }
    return nullptr;
}

json_object::_type json_dict::type() {
    return DICT;
}

std::string json_dict::to_string() {
    std::string _sub = "{";
    for (auto& iter : v) {
        _sub += iter.first->to_string();
        _sub += ": ";
        _sub += iter.second->to_string();
        _sub += ", ";
    }
    if (_sub.length() >= 2) {
        _sub.pop_back();
        _sub.pop_back();
    }

    return _sub + "}";
}



