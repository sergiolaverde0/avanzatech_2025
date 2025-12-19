#include "heapSort.hpp"
#include <iostream>
#include <vector>

using namespace std;

HeapNode parent(const HeapNode& key)
{
    return (key - 1) / 2;
}

/// Ensure the slice of the array passed has all the properties of a max-heap,
/// where both the size and the start clearly define a slice inside the array
void keepHeap(std::vector<HeapNode>& array, const int& size, const int& start)
{
    HeapNode i = start;
    while (true) {
        // Compare node to is children
        HeapNode left = (i * 2) + 1;
        HeapNode right = (i * 2) + 2;
        HeapNode large = i;
        if (left < size && array[left] > array[large]) {
            large = left;
        }
        if (right < size && array[right] > array[large]) {
            large = right;
        }
        // If non of them is larger, break
        if (large == i) {
            break;
        }
        // Swap the values if a larger one was found
        HeapNode temp = array[i];
        array[i] = array[large];
        array[large] = temp;
        i = large;
    }
}

/// Sorts array in place
void heapSort(std::vector<HeapNode>& array)
{
    int size = array.size();
    // Return is array has less than 2 elements
    if (size <= 1) {
        return;
    }
    // Turn the array into a max-heap
    for (int i = parent(size - 1); i >= 0; i--) {
        keepHeap(array, size, i);
    }
    // Sort the array by taking the maximimum value at the root and moving it to
    // the end of the tree
    for (int j = size - 1; j > 0; j--) {
        int temp = array[0];
        array[0] = array[j];
        array[j] = temp;
        keepHeap(array, j, 0);
    }
}

int main()
{
    vector<int> array = { 345, 721, 425, 572, 836, 467, 672, 194, 365, 236, 891, 746, 431, 834, 247, 529, 216, 389 };
    heapSort(array);
    for (auto elem : array) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}
