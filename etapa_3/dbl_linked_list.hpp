#ifndef DOUBLE_LINKED_LIST_HPP
#define DOUBLE_LINKED_LIST_HPP

#include <ostream>
template <class T>
class Node {
public:
    T value;
    Node* prev;
    Node* next;
    explicit Node(const T& value)
        : value(value)
    {
        prev = nullptr;
        next = nullptr;
    }
};

template <class T>
class DblLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    explicit DblLinkedList(const T& value)
    {
        head = new Node<T>(value);
        tail = head;
    }
    ~DblLinkedList()
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
    DblLinkedList& append(const T& value);
    DblLinkedList& prepend(const T& value);
    DblLinkedList& insertAfter(const T& anchor, const T& value);
    DblLinkedList& insertBefore(const T& anchor, const T& value);
    T first(void);
    T last(void);
    DblLinkedList& remove(const T& value);
    bool search(const T& value);
    void print(void);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Node<T>& elem)
{
    os << elem.value;
    return os;
}

#endif // !DOUBLE_LINKED_LIST_HPP
