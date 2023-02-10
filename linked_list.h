#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <class T>
class Node {
   public:
    T data;
    Node* next;

    Node(T value) {
        this->data = value;
        this->next = nullptr;
    }
};

#endif