#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include <vector>

typedef int HeapNode;

void heapSort(std::vector<HeapNode>& array);
void keepHeap(std::vector<HeapNode>& array, const int& size, const int& start);
HeapNode parent(const HeapNode& key);

#endif // !HEAP_SORT_HPP
