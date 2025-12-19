#include "weightSum.hpp"
#include <iostream>
#include <vector>

using namespace std;

bool sumWeight(const std::vector<int>& list, const int& pos, const int& subtotal, const int& target)
{
    for (unsigned i = pos; i < list.size(); i++) {
        if (subtotal + list[i] == target) {
            cout << list[i] << " ";
            return true;
        }
        if (subtotal + list[i] < target) {
            if (sumWeight(list, i + 1, subtotal + list[i], target)) {
                cout << list[i] << " ";
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> list = { 4, 3, 6, 2, 1 };
    int target = 12;
    sumWeight(list, 0, 0, target);
    cout << endl;
    return 0;
}
