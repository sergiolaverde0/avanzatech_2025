#include <deque>
#include <iostream>
#include <set>
#include <utility>

using namespace std;

typedef pair<int, int> cell;

/// Return the minimum number of moves required for a knight to reach a cell in
/// an infinitely large chess board.
int knight_moves(int origin_x, int origin_y, int dest_x, int dest_y)
{
    // Constants for the possible movements of a knight
    static const int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
    static const int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
    // Store cells visited to avoid wasting time going back to the same point
    set<cell> visited;
    // Queue to store cells **and their depth**
    deque<pair<cell, int>> queue;
    // Initialize the BFS algorythm by adding the root to the queue
    int level = 0;
    visited.insert({ origin_x, origin_y });
    queue.push_back({ { origin_x, origin_y }, level });
    // This condition should never be false in an infinitely large board but
    // serves as a sanity check
    while (!queue.empty()) {
        // Grab an entry from the queue
        auto next = queue.front();
        queue.pop_front();
        int x_coord = next.first.first;
        int y_coord = next.first.second;
        level = next.second;
        // Check for exit condition early
        if (x_coord == dest_x && y_coord == dest_y) {
            return level;
        }
        for (int i = 0; i < 8; ++i) {
            cell entry = { x_coord + dx[i], y_coord + dy[i] };
            if (!visited.count(entry)) {
                // Add the possible movements to the queue and the visited list
                // if they haven't been visited yet
                queue.push_back({ entry, level + 1 });
                visited.insert(entry);
            }
        }
    }
    // This code should be unreachable
    return -1;
}

int main(void)
{
    cout << "Moves:\t" << knight_moves(0, 0, 5, 5) << endl;
}
