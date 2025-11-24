#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#define RATIO 0.6180334

template <class T>
struct element {
    T content;
    bool status;
};

template <class T>
class HashTable {
private:
    int used;
    int capacity;
    element<T>** table;
    int hash(const T&);

public:
    explicit HashTable(int cap = 32)
        : capacity(cap)
    {
        used = 0;
        table = new element<T>*[cap]();
        for (int i = 0; i < cap; i++) {
            table[i] = nullptr;
        }
    }
    ~HashTable()
    {
        for (int i = 0; i < this->capacity; i++) {
            delete table[i];
        }
        delete[] table;
    }
    void push(T);
    int find(const T&);
    T& pop(const int&);
    T& get(const int&);
};

#endif // !HASH_TABLE_HPP
