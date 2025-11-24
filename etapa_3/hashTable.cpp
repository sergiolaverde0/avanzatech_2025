#include "hashTable.hpp"
#include <iostream>

using namespace std;

template <class T>
int HashTable<T>::hash(const T& elem)
{
    double temp_1 = elem * RATIO;
    double temp_2 = temp_1 - int(temp_1);
    int hash = temp_2 * this->capacity;
    return hash;
}

template <class T>
int HashTable<T>::find(const T& value)
{
    int hashed = this->hash(value);
    const element<T>* found = this->table[hashed];
    while (found && found->content != value) {
        hashed = (hashed + 1) % this->capacity;
        found = this->table[hashed];
    }
    return hashed;
}

template <class T>
void HashTable<T>::push(T content)
{
    int index = this->find(content);
    element<T>* cell = this->table[index];
    if (cell) {
        if (cell->status) {
            // Value existed and was active
            return;
        } else {
            // Value was found inactive, so active and increase use
            cell->status = true;
            this->used++;
        }
    } else {
        this->table[index] = new element<T> { content, true };
        this->used++;
    }
    if (this->used * 2 > this->capacity) {
        // Table half full, must resize
        // TODO
    };
}

template <class T>
T& HashTable<T>::get(const int& hash)
{
    const element<T>* cell = this->table[hash];
    if (cell && cell->status) {
        return this->table[hash]->content;
    }
    throw std::runtime_error("Mario, your princess is in another castle.");
}

template <class T>
T& HashTable<T>::pop(const int& hash)
{
    element<T>* cell = this->table[hash];
    if (cell && cell->status) {
        cell->status = false;
        this->used--;
        return cell->content;
    }
    throw std::runtime_error("Mario, your princess is in another castle.");
}

int main()
{
    HashTable<char> a = HashTable<char>();
    a.push('A');
    a.push('B');
    int index_b = a.find('B');
    cout << a.get(index_b) << endl;
    a.push('C');
    int index_a = a.find('A');
    int index_c = a.find('C');
    a.pop(index_a);
    cout << a.pop(index_c) << endl;
    return 0;
}
