#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>

template <typename T>
void mergeArray(std::vector<T>& array, const int& first, const int& center, const int& last)
{
    // Create a temporal array
    std::vector<T> temp(last - first + 1);
    // Partition the input array in two halves
    int i = first, j = center + 1, k = 0;
    while (i <= center && j <= last) {
        // Move the smaller value of each half into the temporaal array
        if (array[i] < array[j]) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }
    // Move the remaining elements after consuming one half
    while (i <= center) {
        temp[k++] = array[i++];
    }
    while (j <= last) {
        temp[k++] = array[j++];
    }
    // Copy the elements in order back into the original array
    int l = first;
    for (const T& elem : temp) {
        array[l++] = elem;
    }
}

template <typename T>
void mergeSort(std::vector<T>& array, const int& first, const int& last)
{
    // If array has at least two elements, split and sort each one
    if (first < last) {
        const int center = (first + last) / 2;
        mergeSort(array, first, center);
        mergeSort(array, center + 1, last);
        mergeArray(array, first, center, last);
    }
}

#endif // !MERGE_SORT_HPP
