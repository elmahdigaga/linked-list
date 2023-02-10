#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <class T>
class Node {
   public:
    T data_;
    Node* next_;

    Node(T value) {
        this->data_ = value;
        this->next_ = nullptr;
    }
};

template <class T>
class LinkedList {
   private:
    Node* head_;
    int size_;
};

#endif