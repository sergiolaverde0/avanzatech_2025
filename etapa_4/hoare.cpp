#include "quickSort.hpp"
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void quickSort(vector<int>& array, int first, int last)
{
    int i = first, j = last;
    int pivot = array[(first + last) / 2]; // Hoare
    // Iterate over elements in both ends until they cross
    while (i <= j) {
        // Find the first element larger than the pivot
        while (array[i] < pivot) {
            i++;
        }
        // Find the last element smaller than  the pivot
        while (pivot < array[j]) {
            j--;
        }
        // Swap such elements
        if (i <= j) {
            std::swap(array[i++], array[j--]);
        }
    }
    // If there are elements between the first element and the last element that
    // was smaller than the pivot, sort that segment
    if (first < j) {
        quickSort(array, first, j);
    }
    // If there are elements between the last element and the first element that
    // was larger than the pivot, sort that segment
    if (i < last) {
        quickSort(array, i, last);
    }
}

int main()
{
    vector<int> array = { 6, 1, 5, 2, 3, 4, 0 };
    quickSort(array, 0, array.size() - 1);
    for (auto elem : array) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}
