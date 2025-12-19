#include <queue>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> MAP = { { 2, 1, 1 }, { 1, 1, 0 }, { 0, 1, 1 } };

typedef pair<int, int> cell;

/// Take a map, composed of a matrix where 0 represents an empty cell, 1
/// represents a good apple, and 2 represents a bad apple. Also take a location
/// in the map, and tell if it contains a good apple or not.
bool good_apple(const vector<vector<int>>& map, cell location)
{
    int height = map.size();
    // In case some idiot passes an empty map
    if (height == 0) {
        return false;
    }
    int width = map[0].size();
    if (location.first < 0 || location.first >= height) {
        return false;
    }
    if (location.second < 0 || location.second >= width) {
        return false;
    }
    if (map[location.first][location.second] != 1) {
        return false;
    }
    return true;
}

/// Take a map, composed of a matrix where 0 represents an empty cell, 1
/// represents a good apple, and 2 represents a bad apple. On every iteration,
/// each bad apple spoils every good apple adjacent to it.
/// Return the number of days required until all apples have gone bad, or -1 if
/// some good apples are unreachable
int bad_apple(vector<vector<int>> map)
{
    static const int dx[4] = { -1, 0, 1, 0 };
    static const int dy[4] = { 0, -1, 0, 1 };
    int height = map.size();
    // In case some idiot passes an empty map
    if (height == 0) {
        return -1;
    }
    int width = map[0].size();
    queue<pair<cell, int>> queue;
    int days = 0;
    // Push all cells with a bad apple into the queue
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (map[i][j] == 2) {
                queue.push({ { i, j }, days });
            }
        }
    }
    // Perform the BFS loop to rot apples until no more can be reached
    while (!queue.empty()) {
        // Grab a known bad apple
        auto next = queue.front();
        queue.pop();
        int loop = next.second;
        // If current loop is higher than the day counter, update it
        if (loop > days) {
            days = loop;
        }
        // Check all neighboring cells for good apples
        for (int i = 0; i < 4; ++i) {
            int x_coord = next.first.first + dx[i];
            int y_coord = next.first.second + dy[i];
            if (good_apple(map, { x_coord, y_coord })) {
                // Add any vulnerable good appple to the queue
                queue.push({ { x_coord, y_coord }, loop + 1 });
                map[x_coord][y_coord] = 2;
            }
        }
    }
    // See if there are good appples remaining
    for (const vector<int>& row : map) {
        for (const int square : row) {
            if (square == 1) {
                return -1;
            }
        }
    }
    return days;
}

int main(void)
{
    cout << "Days:\t" << bad_apple(MAP) << endl;
}
