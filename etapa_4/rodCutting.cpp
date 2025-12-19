#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, int> PRICES = { { 1, 1 }, { 2, 5 }, { 3, 8 }, { 4, 9 },
    { 5, 10 }, { 6, 17 }, { 7, 17 }, { 8, 20 }, { 9, 24 }, { 10, 30 } };

/// Bottom-up dynamic programming solution of the cutting rod problem
int cut_rod(unsigned length)
{
    // Store the first solution on an array and leave space for the rest
    vector<int> optimal(length + 1);
    optimal[0] = 0;
    // Compute optimal solution iteratively
    for (unsigned i = 1; i <= length; ++i) {
        int revenue = 0;
        for (unsigned j = 1; j <= i; ++j) {
            // Potential revenue is the revenue from a segment of a given length
            // plus the optimal revenue of the rest
            int potential = PRICES[j] + optimal[i - j];
            if (potential > revenue) {
                revenue = potential;
            }
        }
        optimal[i] = revenue;
    }
    return optimal[length];
}

int main(void)
{
    for (int i = 1; i < 100; ++i) {
        cout << i << "\t" << cut_rod(i) << endl;
    }
}
