#ifndef QUEUE_LINKED_HPP
#define QUEUE_LINKED_HPP

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
class QueueLinked {
private:
    Node<T>* start;
    Node<T>* end;

public:
    explicit QueueLinked()
    {
        start = end = nullptr;
    }
    ~QueueLinked()
    {
        this->clean();
    }
    void push(const T&);
    T pop();
    void clean();
    T& get();
    bool empty();
};

#endif // !QUEUE_LINKED_HPP
