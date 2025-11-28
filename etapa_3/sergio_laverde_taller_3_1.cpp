#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

unsigned long hash_func_sum(const string& word, const int& lenght)
{
    unsigned long sum = 0;
    for (const unsigned char c : word) {
        sum += int(c);
    }
    unsigned long mask = (1UL << lenght) - 1;
    return sum & mask;
}

unsigned long hash_func_prod(const string& word, const int& lenght)
{
    unsigned long prod = 1;
    for (const unsigned char c : word) {
        prod *= int(c);
    }
    unsigned long mask = (1UL << lenght) - 1;
    return prod & mask;
}

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

int main(void)
{
    ifstream file("./files/linuxwords.txt");
    string line;
    vector<string> words;
    while (file >> line) {
        words.push_back(line);
    }

    unsigned int hash_sum_collides_8 = 0;
    unordered_set<unsigned long> hash_sum_set_8;
    for (const string& word : words) {
        unsigned long hashed_word = hash_func_sum(word, 8);
        if (hash_sum_set_8.find(hashed_word) != hash_sum_set_8.end()) {
            hash_sum_collides_8 += 1;
        } else {
            hash_sum_set_8.insert(hashed_word);
        }
    }

    unsigned int hash_prod_collides_8 = 0;
    unordered_set<unsigned long> hash_prod_set_8;
    for (const string& word : words) {
        unsigned long hashed_word = hash_func_prod(word, 8);
        if (hash_prod_set_8.find(hashed_word) != hash_prod_set_8.end()) {
            hash_prod_collides_8 += 1;
        } else {
            hash_prod_set_8.insert(hashed_word);
        }
    }

    unsigned int hash_xor_collides_8 = 0;
    unordered_set<unsigned long> hash_xor_set_8;
    for (const string& word : words) {
        unsigned long hashed_word = hash_func_xor(word, 8);
        if (hash_xor_set_8.find(hashed_word) != hash_xor_set_8.end()) {
            hash_xor_collides_8 += 1;
        } else {
            hash_xor_set_8.insert(hashed_word);
        }
    }

    unsigned int hash_sum_collides_14 = 0;
    unordered_set<unsigned long> hash_sum_set_14;
    for (const string& word : words) {
        unsigned long hashed_word = hash_func_sum(word, 14);
        if (hash_sum_set_14.find(hashed_word) != hash_sum_set_14.end()) {
            hash_sum_collides_14 += 1;
        } else {
            hash_sum_set_14.insert(hashed_word);
        }
    }

    unsigned int hash_prod_collides_14 = 0;
    unordered_set<unsigned long> hash_prod_set_14;
    for (const string& word : words) {
        unsigned long hashed_word = hash_func_prod(word, 14);
        if (hash_prod_set_14.find(hashed_word) != hash_prod_set_14.end()) {
            hash_prod_collides_14 += 1;
        } else {
            hash_prod_set_14.insert(hashed_word);
        }
    }

    unsigned int hash_xor_collides_14 = 0;
    unordered_set<unsigned long> hash_xor_set_14;
    for (const string& word : words) {
        unsigned long hashed_word = hash_func_xor(word, 14);
        if (hash_xor_set_14.find(hashed_word) != hash_xor_set_14.end()) {
            hash_xor_collides_14 += 1;
        } else {
            hash_xor_set_14.insert(hashed_word);
        }
    }

    cout << "Collisions with summation and 8 bits: " << hash_sum_collides_8 << endl;
    cout << "Collisions with product and 8 bits: " << hash_prod_collides_8 << endl;
    cout << "Collisions with XOR and 8 bits: " << hash_xor_collides_8 << endl;
    cout << "Collisions with summation and 14 bits: " << hash_sum_collides_14 << endl;
    cout << "Collisions with product and 14 bits: " << hash_prod_collides_14 << endl;
    cout << "Collisions with XOR and 14 bits: " << hash_xor_collides_14 << endl;

    return 0;
}
