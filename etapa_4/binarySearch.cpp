#include "binarySearch.hpp"
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& array, const int& key)
{
    unsigned start = 0;
    unsigned end = array.size() - 1;
    while (start <= end) {
        unsigned center = start + (end - start) / 2;
        if (array[center] == key) {
            return center;
        } else if (key < array[center]) {
            end = center - 1;
        } else {
            start = center + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> array = { -8, 4, 5, 9, 12, 18, 25, 40, 60 };
    cout << binarySearch(array, 30) << endl;
    return 0;
}
