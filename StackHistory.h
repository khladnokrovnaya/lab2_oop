#include "Text.h"
#include "Stack.h"

class StackHistory
{
public:
    StackHistory() = default;
    StackHistory(const StackHistory& SH);
    StackHistory operator=(const StackHistory &other);

    void Add(const Text &text);
    void Add(Text &&text); // r-value
    void Pop();
    void Clear();

    Stack<Text> getInserts() const {return inserts;}
    Stack<Text> getDeletes() const {return deletes;}


    Text Top() const {
        if (insert_or_delete.Top()->value)
            return inserts.Top()->value;
        else return deletes.Top()->value;
    }

    void Save(const string &filename);
    void Load(const string &filename);

private:
    Stack<bool> insert_or_delete;
    Stack<Text> inserts, deletes;
};

ostream &operator<<(ostream &os, const StackHistory &st);
