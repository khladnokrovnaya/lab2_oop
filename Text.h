#pragma once
#include <string>
#include <iostream>
using namespace std;

class Text {
public:
    Text() = default;
    Text(const string &newtext);
    Text(const string &newtext, const string &text_to, bool type_to, int pos_to);
    Text(const string &newtext, bool type_to, int pos_to, int size_to);
    Text(const Text& other);
    ~Text() = default;

    // Калькулятор нового текста
    string GetNewText() const;

    bool IsOperationSet() const;
    bool OperationType() const {return type;}

    // Delete and Insert
    void SetInsert(const string &text_new, int pos_to);
    void SetInsert(string &&text_new, int pos_to);
    void Delete(int pos_begin, int size);

    ostream &operator<<(ostream &os);

private:
    string text; // сам удаляемый/вставляемый текст
    string text_to_add_or_delete;
    bool type; // 0 если удаление, 1 если вставка
    int pos, size_to_del = 0;
    bool isOperationSet = false;
};

