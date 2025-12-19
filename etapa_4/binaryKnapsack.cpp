#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, int> PRICES = { { 10, 60 }, { 20, 100 }, { 30, 120 } };

/// Bottom-up dynamic programming solution of the binary knapsack problem
int binary_knapsack(unsigned cap)
{
    // Store the first solution and reserve space
    vector<int> optimal(cap + 1, 0);
    for (const auto& [weight, value] : PRICES) {
        // Take an item from the list
        for (int i = cap; i >= weight; --i) {
            int potential = optimal[i - weight] + value;
            if (potential > optimal[i]) {
                optimal[i] = potential;
            }
        }
    }
    return optimal[cap];
}

int main(void)
{
    cout << "50:\t" << binary_knapsack(50) << endl;
}
