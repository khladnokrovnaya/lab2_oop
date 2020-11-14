#pragma once
#include "Text.h"


class Correct : public Text
{
public:
    Correct();
    Correct(string text, string oldText, int pos); // изменненая подстрока, старый текст и позиция изменения

    const string getType() { return "Children"; }

    int get_position();
    void set_position(int pos);

    string getOldText();
    void setOldText(string text);

private:
    string oldText;
    int position;
};
