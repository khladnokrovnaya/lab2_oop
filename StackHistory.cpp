#include "StackHistory.h"
#include <iostream>
#include <fstream>
#include <sstream>


StackHistory::StackHistory(const StackHistory& SH) {
    insert_or_delete = SH.insert_or_delete;
    inserts = SH.inserts;
    deletes = SH.deletes;
}

void StackHistory::Add(const Text &text) {
    if (text.OperationType()) { // если вставка
        inserts.Push(text);
    } else {
        deletes.Push(text);
    }
    insert_or_delete.Push(text.OperationType());
}

void StackHistory::Add(Text &&text) {
    if (text.OperationType()) { // если вставка
        inserts.Push(move(text));
    } else {
        deletes.Push(move(text));
    }
    insert_or_delete.Push(text.OperationType());
}

void StackHistory::Pop() {
    if (insert_or_delete.Top()->value) { // если последняя была вставка
        inserts.Pop();
    } else {deletes.Pop();}
    insert_or_delete.Pop();
}

template <typename type>
void ClearStack(Stack<type> &stack) {
    stack.~Stack();
    stack = Stack<type>();
}

void StackHistory::Clear() {
    ClearStack(insert_or_delete);
    ClearStack(inserts);
    ClearStack(deletes);
}

void StackHistory::Save(const string &filename) {
    try{
        ofstream file(filename);
        auto stack = this->getDeletes().Top();
        while (stack != nullptr) {
            file << stack << '\n';
            stack = stack->next;
        }
        stack = this->getInserts().Top();
        while (stack != nullptr) {
            file << stack << '\n';
            stack = stack->next;
        }
    } catch (exception& e) {
        cout << e.what();
    }
}


void StackHistory::Load(const string &filename) {
    ifstream file(filename);
    string str;
    StackHistory sh;
    while (!file.eof()) {
        getline(file, str, '\n');
        stringstream ss(str);
        if (ss.peek() == 'true') {
            string newtext, text_to, type_to, temp;
            int pos_to, isset;
            getline(ss, type_to);
            getline(ss, newtext, '-');
            getline(ss, text_to, '-');
            getline(ss, temp, '\n');
            stringstream t(temp);
            t >> pos_to >> isset;
            sh.Add({newtext, text_to, true, pos_to});
        } else {
            string newtext, text_to, type_to, temp;
            int pos_to, size, isset;
            getline(ss, type_to);
            getline(ss, newtext, '-');
            getline(ss, text_to, '-');
            getline(ss, temp, '\n');
            stringstream t(temp);
            t >> pos_to >> size >> isset;
            sh.Add({newtext, false, pos_to, size});
        }
    }

}
