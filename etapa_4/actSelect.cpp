#include <iostream>
#include <list>
#include <utility>
#include <vector>

using namespace std;

list<int> activitySelection(const vector<pair<int, int>>& table)
{
    int current_time = 1;
    list<int> retVal;
    for (auto const& entry : table) {
        if (entry.first >= current_time) {
            retVal.push_back(entry.first);
            current_time = entry.second;
        }
    }
    return retVal;
}

int main(void)
{
    vector<pair<int, int>> table = { { 1, 4 }, { 3, 5 }, { 0, 6 }, { 5, 7 },
        { 3, 9 }, { 5, 9 }, { 6, 10 }, { 7, 11 }, { 8, 12 }, { 2, 14 },
        { 12, 16 } };
    for (const int& entry : activitySelection(table)) {
        cout << entry << " ";
    }
    cout << endl;
}
