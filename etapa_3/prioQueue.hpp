#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

template <class T>
class Node {
public:
    T value;
    int priority;
    Node* next;
    explicit Node(const T& value, const int& prio)
        : value(value)
        , priority(prio)
    {
        next = nullptr;
    }
};

template <class T>
class PrioQueue {
private:
    Node<T>* start;
    Node<T>* end;

public:
    explicit PrioQueue()
    {
        start = end = nullptr;
    }
    ~PrioQueue()
    {
        this->clean();
    }
    void push(const T&, const int&);
    T pop();
    void clean();
    T& get();
    bool empty();
};

#endif // !PRIORITY_QUEUE_HPP
