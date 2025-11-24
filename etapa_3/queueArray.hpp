#ifndef QUEUE_ARRAY_HPP
#define QUEUE_ARRAY_HPP

template <class T>
class QueueArray {
private:
    int capacity;
    int head;
    int tail;
    int used;
    T* array;

public:
    explicit QueueArray(int capacity)
        : capacity(capacity)
    {
        head = tail = used = 0;
        array = new T[capacity]();
    }
    ~QueueArray()
    {
        delete[] array;
    }
    void push(const T&);
    T pop();
    void clean();
    T& get();
    bool empty();
    bool full();
};

#endif // !QUEUE_ARRAY_HPP
