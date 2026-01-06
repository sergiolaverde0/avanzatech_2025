#include "weightSum.hpp"
#include <iostream>
#include <vector>

using namespace std;

// Takes a list of integers, an index on it (top calller must use zero), a
// running subtotal (top caller must use zero) and a target number.
// Prints to stdout the first subset of numbers whose sum equals the target.
bool sumWeight(const std::vector<int>& list, const int& pos, const int& subtotal, const int& target)
{
    // Exit condition, return true in a match
    for (unsigned i = pos; i < list.size(); i++) {
        if (subtotal + list[i] == target) {
            cout << list[i] << " ";
            return true;
        }
        // Recursive call to look for a match in the DFS
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
