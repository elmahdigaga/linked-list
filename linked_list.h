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
    int size;

   public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    ~LinkedList() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            Node<T>* to_delete = temp;
            temp = temp->next;
            delete to_delete;
        }
    }

    void Print() {
        if (head == nullptr) {
            std::cout << "List is empty\n";
            return;
        }

        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    int Size() {
        return size;
    }

    LinkedList& InsertBegin(T value) {
        Node<T>* new_node = new Node(value);
        new_node->next = head;
        head = new_node;
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

        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
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
        Node<T>* temp = head;
        for (int i = 0; i < pos - 1; ++i) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        ++size;
        return *this;
    }

    LinkedList& RemoveBegin() {
        if (head == nullptr) {
            std::cerr << "List is empty\n";
            return *this;
        }

        Node<T>* temp = head;
        head = temp->next;
        delete temp;
        --size;
        return *this;
    }

    LinkedList& RemoveEnd() {
        if (head == nullptr) {
            std::cerr << "List is empty\n";
            return *this;
        }

        Node<T>* temp = head;
        if (head->next == nullptr) {
            head = nullptr;
            delete temp;
            --size;
            return *this;
        }
        Node<T>* temp2;
        while (temp->next != nullptr) {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = nullptr;
        delete temp;
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

        Node<T>* temp = head;
        Node<T>* temp2;
        for (int i = 0; i < pos; ++i) {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = temp->next;
        delete temp;
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

        Node<T>* temp = head;
        for (int i = 0; i < pos; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }

    int Find(T value) {
        if (head == nullptr) {
            std::cerr << "List is empty\n";
            return -1;
        }
        int pos = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return pos;
            }
            temp = temp->next;
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
        Node<T>* temp = head;
        for (int i = 0; i < size; ++i) {
            array[i] = temp->data;
            temp = temp->next;
        }
        return array;
    }
};

#endif