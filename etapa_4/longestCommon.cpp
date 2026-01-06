#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Returns the longest common subsequence (not necessarily contiguous) between
// the two strings passed
string longestCommon(const string& left, const string& right)
{
    unsigned lsize = left.size();
    unsigned rsize = right.size();
    string retVal = "";
    // Make a table with one extra column and row, to account for empty strings
    // when recursing
    vector<vector<int>> table(lsize + 1, vector<int>(rsize + 1, 0));
    for (unsigned i = 0; i < lsize; ++i) {
        for (unsigned j = 0; j < rsize; ++j) {
            if (left[i] == right[j]) {
                // If characters are equal, increase counter by one
                table[i + 1][j + 1] = table[i][j] + 1;
            } else {
                // Otherwise, keep the max value from before
                table[i + 1][j + 1] = max(table[i + 1][j], table[i][j + 1]);
            }
        }
    }
    // A second loop is needed to reconstruct the string
    unsigned i = lsize, j = rsize;
    while (i > 0 && j > 0) {
        if (left[i - 1] == right[j - 1]) {
            retVal = left[i - 1] + retVal;
            --i;
            --j;
        } else if (table[i - 1][j] > table[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    return retVal;
}

int main(void)
{
    string left = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    string right = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    cout << longestCommon(left, right) << endl;
}
