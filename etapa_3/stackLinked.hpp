#ifndef STACK_LINKED_HPP
#define STACK_LINKED_HPP

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
class StackLinked {
private:
    Node<T>* peak;

public:
    explicit StackLinked()
    {
        this->peak = nullptr;
    }
    ~StackLinked(){
        this->clean();
    }
    void push(const T&);
    T pop();
    void clean();
    T& get();
    bool empty();
};

#endif // !STACK_LINKED_HPP
