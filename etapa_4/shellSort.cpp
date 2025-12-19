#include "shellSort.hpp"
#include <iostream>
#include <vector>

using namespace std;

void shellSort(vector<int>& array)
{
    int jump = array.size() / 2;
    while (jump > 0) {
        for (unsigned i = jump; i < array.size(); i++) {
            int j = i - jump;
            while (j >= 0) {
                int k = j + jump;
                if (array[j] <= array[k]) {
                    j = -1;
                } else {
                    int temp = array[k];
                    array[k] = array[j];
                    array[j] = temp;
                    j -= jump;
                }
            }
        }
        jump /= 2;
    }
}

int main () {
    vector<int> array = {6, 1, 5, 2, 3, 4, 0};
    shellSort(array);
    for (auto elem : array) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}
