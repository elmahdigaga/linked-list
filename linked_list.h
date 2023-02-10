#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <class T>
class Node {
   public:
    T data_;
    Node<T>* next_;

    Node(T value) {
        this->data_ = value;
        this->next_ = nullptr;
    }
};

template <class T>
class LinkedList {
   private:
    Node<T>* head_;
    int size_;

   public:
    LinkedList() {
        head_ = nullptr;
        size_ = 0;
    }

    ~LinkedList() {
        Node<T>* temp = head_;
        while (temp != nullptr) {
            Node<T>* to_delete = temp;
            temp = temp->next_;
            delete to_delete;
        }
    }

    void Print() {
        if (head_ == nullptr) {
            std::cout << "List is empty\n";
            return;
        }

        Node<T>* temp = head_;
        while (temp != nullptr) {
            std::cout << temp->data_ << " -> ";
            temp = temp->next_;
        }
        std::cout << "NULL\n";
    }

    int Size() {
        return size_;
    }

    LinkedList& InsertBegin(T value) {
        Node<T>* new_node = new Node(value);
        new_node->next_ = head_;
        head_ = new_node;
        ++size_;
        return *this;
    }

    LinkedList& InsertEnd(T value) {
        Node<T>* new_node = new Node(value);
        if (head_ == nullptr) {
            head_ = new_node;
            ++size_;
            return *this;
        }

        Node<T>* temp = head_;
        while (temp->next_ != nullptr) {
            temp = temp->next_;
        }
        temp->next_ = new_node;
        ++size_;
        return *this;
    }

    LinkedList& InsertPos(T value, int pos) {
        if (pos > size_) {
            std::cerr << "Invalid position\n";
            return *this;
        } else if (pos == 0) {
            InsertBegin(value);
            return *this;
        } else if (pos == size_) {
            InsertEnd(value);
            return *this;
        }

        Node<T>* new_node = new Node(value);
        Node<T>* temp = head_;
        for (int i = 0; i < pos - 1; ++i) {
            temp = temp->next_;
        }
        new_node->next_ = temp->next_;
        temp->next_ = new_node;
        ++size_;
        return *this;
    }

    LinkedList& RemoveBegin() {
        if (head_ == nullptr) {
            std::cerr << "List is empty\n";
            return *this;
        }

        Node<T>* temp = head_;
        head_ = temp->next_;
        delete temp;
        --size_;
        return *this;
    }

    LinkedList& RemoveEnd() {
        if (head_ == nullptr) {
            std::cerr << "List is empty\n";
            return *this;
        }

        Node<T>* temp = head_;
        if (head_->next_ == nullptr) {
            head_ = nullptr;
            delete temp;
            --size_;
            return *this;
        }
        Node<T>* temp2;
        while (temp->next_ != nullptr) {
            temp2 = temp;
            temp = temp->next_;
        }
        temp2->next_ = nullptr;
        delete temp;
        --size_;
        return *this;
    }

    LinkedList& RemovePos(int pos) {
        if (pos >= size_) {
            std::cerr << "Invalid position\n";
            return *this;
        } else if (pos == 0) {
            RemoveBegin();
            return *this;
        } else if (pos == size_ - 1) {
            RemoveEnd();
            return *this;
        }

        Node<T>* temp = head_;
        Node<T>* temp2;
        for (int i = 0; i < pos; ++i) {
            temp2 = temp;
            temp = temp->next_;
        }
        temp2->next_ = temp->next_;
        delete temp;
        --size_;
        return *this;
    }

    int Find(T value) {
        if (head_ == nullptr) {
            std::cerr << "List is empty\n";
            return -1;
        }
        int pos = 0;
        Node<T>* temp = head_;
        while (temp != nullptr) {
            if (temp->data_ == value) {
                return pos;
            }
            temp = temp->next_;
            ++pos;
        }

        return -1;
    }

    LinkedList& Delete(T value) {
        if (head_ == nullptr) {
            std::cerr << "List is empty\n";
            return *this;
        }

        int pos = Find(value);
        if (pos == -1) {
            std::cerr << "Value not found\n";
            return *this;
        }
        RemovePos(pos);
        return *this;
    }

    bool IsEmpty() {
        return head_ == nullptr ? true : false;
    }

    T* ToArray() {
        if (head_ == nullptr) {
            std::cerr << "List is empty\n";
            return nullptr;
        }

        T* array = new T[size_];
        Node<T>* temp = head_;
        for (int i = 0; i < size_; ++i) {
            array[i] = temp->data_;
            temp = temp->next_;
        }
        return array;
    }
};

#endif