#pragma once

template <typename T>
class Stack {
public:
  struct Node {
      Node(const T& value_) {value = value_;}
    T value;
    Node* next = nullptr;
  };

  ~Stack();

  void Push(const T& value);
  void Pop();
  int Size() const;

  Node* Top() { return head; }
  const Node* Top() const { return head; }

private:
  Node* head = nullptr;
};

template <typename T>
int Stack<T>::Size() const {
    Node* node = this->Top();
    int count = 0;
    while (node != nullptr) {
        node = node->next;
        count++;
    }
    return count;
}


template <typename T>
Stack<T>::~Stack() {
  while (head) {
    Pop();
  }
}

template <typename T>
void Stack<T>::Push(const T& value) {
  auto node = new Node{value};
  node->next = head;
  head = node;
}

template <typename T>
void Stack<T>::Pop() {
  if (head) {
    Node* new_head = head->next;
    delete head;
    head = new_head;
  }
}
