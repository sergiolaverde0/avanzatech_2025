#ifndef LINKED_HPP
#define LINKED_HPP

#include <iostream>

template <class T>
class Node {
public:
    T value;
    Node* next;
    explicit Node(const T& value)
        : value(value)
    {
        next = nullptr;
    }
};

template <class T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    explicit LinkedList(const T& value)
    {
        head = new Node<T>(value);
        tail = head;
    }
    ~LinkedList()
    {
        Node<T>* next;
        Node<T>* current = this->head;
        while (current->next) {
            next = current->next;
            delete current;
            current = next;
        }
        delete current;
    }
    LinkedList& append(const T& value)
    {
        Node<T>* current = this->head;
        while (current->next) {
            current = current->next;
        }
        Node<T>* newNode = new Node<T>(value);
        current->next = newNode;
        this->tail = newNode;
        return *this;
    }
    LinkedList& prepend(const T& value)
    {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = this->head;
        this->head = newNode;
        return *this;
    }
    LinkedList& insertAfter(const T& anchor, const T& value)
    {
        Node<T>* current = this->head;
        while (current->value != anchor) {
            if (current->next) {
                current = current->next;
            } else {
                return *this;
            }
        }
        Node<T>* nextNode = current->next;
        Node<T>* newNode = new Node<T>(value);
        current->next = newNode;
        newNode->next = nextNode;
        return *this;
    }
    LinkedList& insertBefore(const T& anchor, const T& value)
    {
        Node<T>* current = this->head;
        Node<T>* prev = nullptr;
        while (current) {
            if (current->value == anchor) {
                Node<T>* newNode = new Node<T>(value);
                if (!prev) {
                    this->head = newNode;
                } else {
                    prev->next = newNode;
                }
                newNode->next = current;
                return *this;
            }
            prev = current;
            current = current->next;
        }
        return *this;
    }
    T first(void)
    {
        return head->value;
    }
    T last(void)
    {
        return tail->value;
    }
    LinkedList& remove(const T& value)
    {
        Node<T>* current = this->head;
        Node<T>* prev = nullptr;
        while (current) {
            if (current->value == value) {
                if (!prev) {
                    this->head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return *this;
            }
            prev = current;
            current = current->next;
        }
        return *this;
    }
    bool search(const T& value)
    {
        Node<T>* current = this->head;
        while (true) {
            if (current->value == value) {
                return true;
            }
            if (!current->next) {
                return false;
            }
            current = current->next;
        }
    }
    void print(void)
    {
        Node<T>* current = this->head;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Node<T>& elem)
{
    os << elem.value;
    return os;
}

#endif
