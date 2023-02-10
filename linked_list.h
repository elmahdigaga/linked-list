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

   public:
    LinkedList() {
        head_ = nullptr;
        size = 0;
    }

    ~LinkedList() {
        Node* temp = head_;
        while (temp != nullptr) {
            Node* to_delete = temp;
            temp = temp->next_;
            delete to_delete;
        }
    }

    LinkedList* InsertBegin(T value) {
        Node* new_node = new Node(value);
        new_node->next_ = head_;
        head_ = new_node;
        return *this;
    }
};

#endif