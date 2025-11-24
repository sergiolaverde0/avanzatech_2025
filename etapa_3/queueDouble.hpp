#ifndef QUEUE_DOUBLE_HPP
#define QUEUE_DOUBLE_HPP

template <class T>
class Node {
public:
    T value;
    Node<T>* next;
    Node<T>* prev;
    explicit Node(const T& value)
        : value(value)
    {
        next = nullptr;
        prev = nullptr;
    }
};

template <class T>
class QueueDouble {
private:
    Node<T>* front;
    Node<T>* back;

public:
    explicit QueueDouble()
    {
        front = back = nullptr;
    }
    void push_front(const T&);
    void push_back(const T&);
    T& get_front();
    T& get_back();
    T pop_front();
    T pop_back();
    bool empty();
    void clean();
};

#endif // !QUEUE_DOUBLE_HPP
