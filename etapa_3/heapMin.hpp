#ifndef HEAP_MIN_HPP
#define HEAP_MIN_HPP

class HeapMin {
private:
    int key, used, root, left, right;
    const int capacity;

public:
    HeapMin(int cap = 1024)
        : capacity(cap)
    {
        used = 0;
    }
    int operator[](int);
    void insert(int key);
    int get();
    int pop();
    bool empty();
    bool full();
    void clean();
};

#endif // !HEAP_MIN_HPP
