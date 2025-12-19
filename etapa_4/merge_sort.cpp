#include "merge_sort.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::vector<int> array = { 9, 1, 3, 5, 10, 4, 6 };
    mergeSort(array, 0, array.size() - 1);
    for (auto elem : array) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}
