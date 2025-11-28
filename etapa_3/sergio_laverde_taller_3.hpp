#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <optional>
#include <string>

template <class T>
struct entry {
    std::string key;
    T value;
    bool status;

    entry(std::string k, T t, bool b)
        : key(k)
        , value(t)
        , status(b)
    {
    }
};

template <class T>
class HashTable {
protected:
    unsigned int used, capacity;
    entry<T>** table;
    int find(const std::string& key) const;
    void resize();

public:
    explicit HashTable(unsigned cap = 1024)
        : capacity(cap)
    {
        used = 0;
        table = new entry<T>*[cap]();
    };
    ~HashTable()
    {
        for (unsigned i = 0; i < this->capacity; i++) {
            delete table[i];
        }
        delete[] table;
    }

    // Insert or update a key-value pair.
    void setKey(const std::string& key, const T& value);

    // Get value by key. Returns nullopt if key is not found.
    std::optional<T> getKey(const std::string& key) const;

    // Remove all key-value pairs from the hash table.
    void clear();

    // Extra: remove (actually turn off) entry
    void remove(const std::string& key);
};

#endif // HASHTABLE_H
