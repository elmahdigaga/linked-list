#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

template <class T>
class Node {
   public:
    T data;
    Node<T>* next;

    Node(T value) {
        this->data = value;
        this->next = nullptr;
    }
};

template <class T>
class LinkedList {
   private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* cursor;
    int size;

   public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~LinkedList() {
        cursor = head;
        while (cursor != nullptr) {
            Node<T>* to_delete = cursor;
            cursor = cursor->next;
            delete to_delete;
        }
    }

    void Print() {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }

        cursor = head;
        while (cursor != nullptr) {
            std::cout << cursor->data << " -> ";
            cursor = cursor->next;
        }
        std::cout << "NULL\n";
    }

    int Size() {
        return size;
    }

    LinkedList& InsertBegin(T value) {
        cursor = new Node(value);
        cursor->next = head;
        head = cursor;
        ++size;
        return *this;
    }

    LinkedList& InsertEnd(T value) {
        Node<T>* new_node = new Node(value);
        if (head == nullptr) {
            head = new_node;
            ++size;
            return *this;
        }

        cursor = head;
        while (cursor->next != nullptr) {
            cursor = cursor->next;
        }
        cursor->next = new_node;
        ++size;
        return *this;
    }

    LinkedList& InsertPos(T value, int pos) {
        if (pos > size) {
            std::cerr << "Invalid position\n";
            return *this;
        } else if (pos == 0) {
            InsertBegin(value);
            return *this;
        } else if (pos == size) {
            InsertEnd(value);
            return *this;
        }

        Node<T>* new_node = new Node(value);
        cursor = head;
        for (int i = 0; i < pos - 1; ++i) {
            cursor = cursor->next;
        }
        new_node->next = cursor->next;
        cursor->next = new_node;
        ++size;
        return *this;
    }

    LinkedList& RemoveBegin() {
        if (head == nullptr) {
            std::cerr << "List is empty\n";
            return *this;
        }

        cursor = head;
        head = cursor->next;
        delete cursor;
        --size;
        return *this;
    }

    LinkedList& RemoveEnd() {
        if (head == nullptr) {
            std::cerr << "List is empty\n";
            return *this;
        }

        cursor = head;
        if (head->next == nullptr) {
            head = nullptr;
            delete cursor;
            --size;
            return *this;
        }
        Node<T>* temp2;
        while (cursor->next != nullptr) {
            temp2 = cursor;
            cursor = cursor->next;
        }
        temp2->next = nullptr;
        delete cursor;
        --size;
        return *this;
    }

    LinkedList& RemovePos(int pos) {
        if (pos >= size) {
            std::cerr << "Invalid position\n";
            return *this;
        } else if (pos == 0) {
            RemoveBegin();
            return *this;
        } else if (pos == size - 1) {
            RemoveEnd();
            return *this;
        }

        cursor = head;
        Node<T>* temp2;
        for (int i = 0; i < pos; ++i) {
            temp2 = cursor;
            cursor = cursor->next;
        }
        temp2->next = cursor->next;
        delete cursor;
        --size;
        return *this;
    }

    T Get(int pos) {
        if (head == nullptr) {
            std::cerr << "List is empty\n";
            return 0;
        }
        if (pos >= size) {
            std::cerr << "Invalid index\n";
            return 0;
        }

        cursor = head;
        for (int i = 0; i < pos; ++i) {
            cursor = cursor->next;
        }
        return cursor->data;
    }

    int Find(T value) {
        if (head == nullptr) {
            std::cerr << "List is empty\n";
            return -1;
        }
        int pos = 0;
        cursor = head;
        while (cursor != nullptr) {
            if (cursor->data == value) {
                return pos;
            }
            cursor = cursor->next;
            ++pos;
        }

        return -1;
    }

    LinkedList& Delete(T value) {
        if (head == nullptr) {
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
        return head == nullptr ? true : false;
    }

    T* ToArray() {
        if (head == nullptr) {
            std::cerr << "List is empty\n";
            return nullptr;
        }

        T* array = new T[size];
        cursor = head;
        for (int i = 0; i < size; ++i) {
            array[i] = cursor->data;
            cursor = cursor->next;
        }
        return array;
    }
};

#endif