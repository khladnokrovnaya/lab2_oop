#include "Text.h"
#include <iostream>

Text::Text(const string &newtext) :
    text(newtext)
{}

Text::Text(const Text& other) {
    text = other.text;
    text_to_add_or_delete = other.text_to_add_or_delete;
    type = other.type;
    pos = other.pos;
    size_to_del = other.size_to_del;
}

Text::Text(const string &newtext, const string &text_to, bool type_to, int pos_to) {
    text = newtext;
    text_to_add_or_delete = text_to;
    type = type_to;
    pos = pos_to;
    isOperationSet = true;
}

Text::Text(const string &newtext, bool type_to, int pos_to, int size_to) {
    text = newtext;
    type = type_to;
    pos = pos_to;
    size_to_del = size_to;
    isOperationSet = true;
}


string Text::GetNewText() const {
    if (type) { // если вставка:
        string res = text;
        res.insert(res.begin() + pos, text_to_add_or_delete.begin(), text_to_add_or_delete.end());
        return res;
    } else if (!type) {
        string res = text;
        res.erase(res.begin() + pos, min(res.begin() + pos + size_to_del, res.end()));
        return res;
    } else {
        throw runtime_error("type is not defined");
    }
}

bool Text::IsOperationSet() const {
    return isOperationSet;
}

void Text::SetInsert(const string &text_new, int pos_to) {
    text_to_add_or_delete = text_new;
    pos = pos_to;
    type = isOperationSet = true;
}

void Text::SetInsert(string &&text_new, int pos_to) {
    text_to_add_or_delete = text_new;
    pos = pos_to;
    type = isOperationSet = true;
}

void Text::Delete(int pos_begin, int size) {
    pos = pos_begin;
    size_to_del = size;
    type = 0;
    isOperationSet = true;
}

ostream &Text::operator<<(ostream &os) {
    if (type) {
        os << type << ' ' << text << '-' << text_to_add_or_delete << '-' <<
              pos << ' ' << isOperationSet;
    } else {
        os << type << ' ' << text << '-' << text_to_add_or_delete << '-' <<
              pos << ' ' << size_to_del << ' ' << isOperationSet;
    }
    return os;
}
