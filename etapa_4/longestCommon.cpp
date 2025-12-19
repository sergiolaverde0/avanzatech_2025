#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

unsigned longestCommon(const string& left, const string& right)
{
    unsigned lsize = left.size();
    unsigned rsize = right.size();
    vector<vector<int>> table(lsize + 1, vector<int>(rsize + 1, 0));
    for (unsigned i = 0; i < lsize; ++i) {
        for (unsigned j = 0; j < rsize; ++j) {
            if (left[i] == right[j]) {
                table[i + 1][j + 1] = table[i][j] + 1;
            } else {
                table[i + 1][j + 1] = max(table[i + 1][j], table[i][j + 1]);
            }
        }
    }
    return table[lsize][rsize];
}

int main(void)
{
    string left = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    string right = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    cout << longestCommon(left, right) << endl;
}
