#include "quickSort.hpp"
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void quickSort(vector<int>& array, int first, int last)
{
    // Pick the last element as the pivot and set the first entry as the
    // current destination for the smaller values
    int pivot = array[last];
    int i = first;
    for (int j = first; j < last; j++) {
        // Move the elements smaller than the pivot to the beginning of the array,
        // do nothing with the ones that are larger
        if (array[j] <= pivot) {
            swap(array[i++], array[j]);
        }
    }
    swap(array[i], array[last]);

    // If there are elements between the first element and the last element that
    // was smaller than the pivot, sort that segment
    if (first < i - 1) {
        quickSort(array, first, i - 1);
    }
    // If there are elements between the last element and the first element that
    // was larger than the pivot, sort that segment
    if (i + 1 < last) {
        quickSort(array, i + 1, last);
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
