#include "radixSort.hpp"
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int maxKey(const std::vector<int>& array)
{
    int max = 0;
    for (int elem : array) {
        if (elem > max) {
            max = elem;
        }
    }
    return max;
}

void radixSort(std::vector<int>& array)
{
    // Get the maximum number present, and calculate how many digits it has
    int max = maxKey(array);
    int digits = 0;
    while (max > 0) {
        max /= 10;
        digits++;
    }
    int weight = 1;
    // For every digit taken in consideration
    for (int i = 0; i < digits; i++) {
        // Put the value in the bin that matches that digit
        vector<list<int>> bins(10);
        for (int elem : array) {
            int last = (elem / weight) % 10;
            (bins[last]).push_back(elem);
        }
        // Then put the values back in the array
        array.clear();
        for (const list<int>& bin : bins) {
            for (const int& elem : bin) {
                array.push_back(elem);
            }
        }
        weight *= 10;
    }
}

int main()
{
    vector<int> array = { 345, 721, 425, 572, 836, 467, 672, 194, 365, 236, 891, 746, 431, 834, 247, 529, 216, 389 };
    radixSort(array);
    for (auto elem : array) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}
