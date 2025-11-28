#include "sergio_laverde_taller_3.hpp"
#include <iostream>
#include <optional>
#include <string>
#include <vector> // For the hashing function only

using namespace std;

unsigned long hash_func_xor(const string& word, const int& lenght)
{
    unsigned long word_size = word.length() * 8;
    // Store the bits of the word passed in an array as if they were booleans
    vector<bool> bit_vec;
    bit_vec.reserve(word_size);
    for (const unsigned char c : word) {
        int char_bit = int(c);
        unsigned long char_mask = 1;
        for (int i = 0; i < 8; i++) {
            bit_vec.push_back(char_bit & char_mask);
            char_mask = char_mask << 1;
        }
    }
    // Divide the number of bits in the word between the number of bits to
    // return after hasing, and round up.
    int vec_len = (word_size + lenght - 1) / lenght;
    // Convert the array of bits into an array of bit chunks of size `lenght`
    vector<unsigned long> lengt_vec;
    lengt_vec.reserve(vec_len);
    for (int i = 0; i < vec_len; i++) {
        unsigned long current = 0;
        for (int j = 0; j < lenght; j++) {
            current = current << 1;
            if (!bit_vec.empty()) {
                current += bit_vec.back();
                bit_vec.pop_back();
            }
        }
        lengt_vec.push_back(current);
    }
    unsigned long result = 0;
    for (unsigned long chunk : lengt_vec) {
        result = result ^ chunk;
    }
    return result;
}

template <class T>
int HashTable<T>::find(const string& key) const
{
    // Hash the key and clamp into table size
    unsigned long hashed = hash_func_xor(key, 16) % this->capacity;
    const entry<T>* found = this->table[hashed];
    // In case of collision, search for the next empty space
    while (found && found->key != key) {
        hashed = (hashed + 1) % this->capacity;
        found = this->table[hashed];
    }
    return hashed;
}

template <class T>
void HashTable<T>::resize()
{
    HashTable<T> new_map = HashTable<T>(this->capacity * 2.5);
    for (unsigned i = 0; i < this->capacity; i++) {
        const entry<T>* const& cell = this->table[i];
        if (cell) {
            new_map.setKey(cell->key, cell->value);
        }
    }
    this->clear();
    this->capacity = new_map.capacity;
    this->used = new_map.used;
    // Table ownership witchery
    entry<T>** old_table = this->table;
    this->table = new_map.table;
    new_map.table = nullptr;
    new_map.capacity = 0;
    new_map.used = 0;
    delete[] old_table;
}

template <class T>
void HashTable<T>::setKey(const string& key, const T& value)
{
    int index = find(key);
    entry<T>* cell = this->table[index];
    if (cell && cell->key == key) {
        cell->status = true;
        cell->value = value;
        return;
    }
    this->table[index] = new entry<T>(key, value, true);
    this->used++;
    if (this->used * 2 > this->capacity) {
        // Table half full, resize
        this->resize();
    }
}

template <class T>
optional<T> HashTable<T>::getKey(const string& key) const
{
    int hashed = find(key);
    entry<T>* cell = this->table[hashed];
    if (cell && cell->key == key && cell->status) {
        return cell->value;
    }
    return {};
}

template <class T>
void HashTable<T>::clear()
{
    for (unsigned i = 0; i < this->capacity; i++) {
        entry<T>*& cell = this->table[i];
        delete cell;
        cell = nullptr;
    }
    this->used = 0;
}

template <class T>
void HashTable<T>::remove(const string& key)
{
    int hashed = find(key);
    entry<T>* cell = this->table[hashed];
    if (cell && cell->key == key) {
        cell->status = false;
    }
}

int main()
{
    // Some testing that it actually works
    HashTable<string> dict = HashTable<string>(4);
    dict.setKey("Samuel", "Apoyo");
    dict.setKey("Sebastian", "Natilla");
    dict.setKey("Mariana", "Eggsplosiva");
    dict.setKey("Luisa", "ChickenMaster");
    dict.setKey("Jose", "Waza");
    dict.setKey("Isaac", "MekeTron");

    cout << *dict.getKey("Samuel") << endl;
    cout << *dict.getKey("Sebastian") << endl;
    cout << *dict.getKey("Isaac") << endl;
    return 0;
}
