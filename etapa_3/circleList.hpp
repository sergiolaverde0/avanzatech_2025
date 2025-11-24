#ifndef CIRCLE_LINKED_LIST_HPP
#define CIRCLE_LINKED_LIST_HPP

#include <ostream>

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
class CircleList {
private:
    Node<T>* entry;

public:
    explicit CircleList(const T& value)
    {
        entry = new Node<T>(value);
        entry->next = entry;
    }
    ~CircleList()
    {
        if (!entry) {
            return;
        }
        Node<T>* nextNode;
        Node<T>* current = this->entry->next;
        while (current != this->entry) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        delete this->entry;
    }
    CircleList& append(const T& value);
    CircleList& prepend(const T& value);
    CircleList& insertAfter(const T& anchor, const T& value);
    CircleList& insertBefore(const T& anchor, const T& value);
    CircleList& remove(const T& value);
    bool search(const T& value);
    void print(void);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Node<T>& elem)
{
    os << elem.value;
    return os;
}

#endif // !CIRCLE_LINKED_LIST_HPP
#define CIRCLE_LINKED_LIST_HPP
