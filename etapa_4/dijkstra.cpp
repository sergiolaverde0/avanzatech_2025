#include <cstdint>
#include <functional>
#include <limits>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int64_t INF = numeric_limits<int64_t>::max();

typedef pair<int64_t, char> edge;
typedef unordered_map<char, unordered_map<char, int>> adjacency;

/// Calculate the length of the shortest path between two vertices in a
/// connected graph.
/// Returns -1 on failure.
int dijkstra(const adjacency& matrix, char start, char end)
{
    // Sanity checks
    if (matrix.find(start) == matrix.end()) {
        return -1;
    }
    if (matrix.find(end) == matrix.end()) {
        return -1;
    }
    if (matrix.size() == 0) {
        return -1;
    }
    if (start == end) {
        return 0;
    }
    // Set all distances to a sufficiently large value
    unordered_map<char, int64_t> distance;
    for (const auto& [node, _] : matrix) {
        distance[node] = INF;
    }
    distance[start] = 0;
    priority_queue<edge, vector<edge>, greater<>> min_queue;
    min_queue.push({ distance[start], start });
    while (!min_queue.empty()) {
        const auto& [offset, current] = min_queue.top();
        min_queue.pop();
        // Remove stale entries.
        // I hate this, feels like a hack and is unclear at first, but works
        // because the offset to the current point only decreases and is never
        // infinite, so larger entries must be outdated
        if (offset != distance[current]) {
            continue;
        }
        for (const auto& [neighbor, travel] : matrix.at(current)) {
            if (travel < 0) {
                return -1;
            }
            if (offset + travel < distance[neighbor]) {
                // Update distance
                distance[neighbor] = offset + travel;
                min_queue.push({distance[neighbor], neighbor});
            }
        }
    }
    if (distance[end] == INF) {
        return -1;
    }
    return distance[end];
}
