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

    LinkedList* InsertEnd(T value) {
        Node* new_node = new Node(value);
        if (head_ == nullptr) {
            head_ = new_node;
            return *this;
        }

        Node* temp = head_;
        while (temp->next_ != nullptr) {
            temp = temp->next_;
        }
        temp->next_ = new_node;

        return *this;
    }

    LinkedList* InsertPos(T value, int pos) {
        if (pos > size_) {
            std::cerr << "Invalid position\n";
            return *this;
        } else if (pos == 0) {
            InsertBegin(value);
            return *this;
        } else if (pos == size) {
            InsertEnd(value);
            return *this;
        }

        Node* new_node = new Node(value);
        Node* temp = head_;
        for (int i = 0; i < pos - 1; ++i) {
            temp = temp->next_;
        }
        new_node->next_ = temp->next_;
        temp->next_ = new_node;

        return *this;
    }

    LinkedList* RemoveBegin() {
        if (head_ == nullptr) {
            std::cerr << "List is empty\n";
            return *this;
        }

        Node* temp = head_;
        head_ = temp->next_;
        delete temp;

        return *this;
    }
};

#endif