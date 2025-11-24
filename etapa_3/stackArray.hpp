#ifndef STACK_ARRAY_HPP
#define STACK_ARRAY_HPP

template <class T>
class StackArray {
private:
    int peak;
    int capacity;
    T* array;

public:
    explicit StackArray(const int& capacity)
        : peak(-1)
        , capacity(capacity)
    {
        array = new T[capacity]();
    }
    ~StackArray()
    {
        delete[] array;
    }
    void push(const T&);
    T& pop();
    void clean();
    T& get();
    bool empty();
};

#endif // !STACK_ARRAY_HPP
