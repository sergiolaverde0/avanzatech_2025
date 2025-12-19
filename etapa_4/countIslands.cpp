#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> MAP = { { 1, 1, 1, 1, 1, 1, 1, 0 },
    { 1, 0, 0, 0, 0, 1, 1, 0 },
    { 1, 0, 1, 0, 1, 1, 1, 0 },
    { 1, 0, 0, 0, 0, 1, 0, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 0 } };

/// Visit a cell in a map. If it is water, return immediately. Otherwise, mark
/// it as visited and then visit all of its neighbors.
void markIsland(vector<vector<int>>* map, unsigned width, unsigned height,
    unsigned i, unsigned j)
{
    // By adding this guard here we can save repeating guards in each if
    // statement after, at minimum performance penalty.
    if ((*map)[i][j] != 1) {
        return;
    }
    // Mark the starting island before doing recursion to avoid infinite loops
    (*map)[i][j] = -1;
    // Visit all neighboors, on the assumption that diagonals do not count
    if (i + 1 < width) {
        markIsland(map, width, height, i + 1, j);
    }
    if (i > 0) {
        markIsland(map, width, height, i - 1, j);
    }
    if (j + 1 < height) {
        markIsland(map, width, height, i, j + 1);
    }
    if (j > 0) {
        markIsland(map, width, height, i, j - 1);
    }
}

/// Count the number of islands in a map.
/// This function makes a copy of the map because it requires mutation.
int countIslands(vector<vector<int>> map)
{
    unsigned width = map.size();
    unsigned height = map[0].size();
    int retVal = 0;
    // Visit all cells one by one
    for (unsigned i = 0; i < width; ++i) {
        for (unsigned j = 0; j < height; ++j) {
            if (map[i][j] == 1) {
                // Upon discovering a new island, increase counter and leave a
                // mark to make sure
                ++retVal;
                markIsland(&map, width, height, i, j);
            }
        }
    }
    return retVal;
}

int main()
{
    cout << "Island count:\t" << countIslands(MAP) << endl;
    return 0;
}
