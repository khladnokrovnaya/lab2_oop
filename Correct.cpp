#include "Correct.h"

Correct::Correct():
    Text(), oldText(""), position(0)
{

}
Correct::Correct(string text, string oldText_, int pos):
    oldText(oldText_), Text(text)
{
    if (position > oldText.size() || position < 0) // position - позиция в которой произошли изменения в старом тексте
        position = 0;
    else
        this->position = pos;
}

int Correct::get_position(){
    return this->position;
}
void Correct::set_position(int pos){
    if (pos > 0 && pos < oldText.size())
        this->position = pos;
}

string Correct::getOldText(){
    return this->oldText;
}
void Correct::setOldText(string text){
    this->oldText = text;
    if (position > text.size())
        position = text.size() - 1;
}
