#include <iostream>
#include <limits>
#include <stdexcept>
#include <unordered_map>

using namespace std;

typedef unordered_map<char, unordered_map<char, int>> adjacency;

const int64_t INF = numeric_limits<int64_t>::max();

/// Takes an adjancency matrix, a start node and an end node, and returns the
/// length of the shortest path.
/// The matrix is allowed to have negative weights, but negative cycles will
/// produce an exception.
/// The matrix must include all nodes as keys; if a node has no neighbors, it
/// must be expressed by an empty map.
int bellmanFord(const adjacency& matrix, char start, char end)
{
    if (matrix.find(start) == matrix.end()) {
        throw runtime_error("The start node does not exist in the adjacency \
                matrix given.");
    }
    if (matrix.find(end) == matrix.end()) {
        throw runtime_error("The end node does not exist in the adjacency \
                matrix given.");
    }
    if (matrix.size() == 0) {
        throw runtime_error("The adjacency matrix received is empty.");
    }
    if (start == end) {
        return 0;
    }
    unordered_map<char, int64_t> distance;
    unordered_map<char, char> previous;
    for (const auto& [node, trash] : matrix) {
        if (node == '\0') {
            throw runtime_error("Invalid character to to represent a node found \
                    in the adjacency matrix.");
        }
        distance[node] = INF;
        previous[node] = '\0';
    }
    distance[start] = 0;
    for (size_t i = 0; i < matrix.size() - 1; ++i) {
        for (const auto& [node, neighbors] : matrix) {
            for (const auto& [point, travel] : neighbors) {
                // Do not relax nodes that have not yet been reached
                if (distance[node] == INF) {
                    continue;
                }
                if (distance[node] + travel < distance[point]) {
                    distance[point] = distance[node] + travel;
                    previous[point] = node;
                }
            }
        }
    }
    if (distance[end] == INF) {
        throw runtime_error("No path to the end could be found.");
    }
    // Check for negative cycles
    for (const auto& [node, neighbors] : matrix) {
        for (const auto& [point, travel] : neighbors) {
            // Do not relax nodes that have not yet been reached
            if (distance[node] == INF) {
                continue;
            }
            if (distance[node] + travel < distance[point]) {
                // A negative cycle was found
                throw runtime_error("A negative cycle was found.");
            }
        }
    }
    return distance[end];
}

int main()
{
    adjacency ADJ = { { 's', { { 't', 6 }, { 'y', 7 } } },
        { 't', { { 'x', 5 }, { 'y', 8 }, { 'z', -4 } } },
        { 'x', { { 't', -2 } } },
        { 'y', { { 'x', -3 }, { 'z', 9 } } },
        { 'z', { { 'x', 7 } } } };

    cout << bellmanFord(ADJ, 's', 'z') << endl;
}
