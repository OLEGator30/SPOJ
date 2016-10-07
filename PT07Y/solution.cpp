#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

string OrderedPair(size_t first, size_t second) {
    return (first < second)
        ? to_string(first) + " " + to_string(second)
        : to_string(second) + " " + to_string(first);
}

bool DFS(const vector<vector<size_t>>& graph, size_t root, vector<bool>& seenNodes,
    unordered_set<string>& unseenEdges)
{
    if (seenNodes[root]) {
        return false;
    }

    seenNodes[root] = true;
    for (size_t i = 0; i < graph[root].size(); ++i) {
        auto ptr = unseenEdges.find(OrderedPair(root, graph[root][i]));
        if (ptr == unseenEdges.end()) {
            continue;
        }
        unseenEdges.erase(ptr);

        if (!DFS(graph, graph[root][i], seenNodes, unseenEdges)) {
            return false;
        }
    }

    return true;
}

int main(int /*argc*/, char ** /*argv*/) {
    size_t nNodes, nEdges;
    cin >> nNodes;
    cin >> nEdges;

    vector<vector<size_t>> graph(nNodes);
    unordered_set<string> unseenEdges;
    for (size_t i = 0; i < nEdges; ++i) {
        size_t first, second;
        cin >> first;
        cin >> second;

        graph[first - 1].push_back(second - 1);
        graph[second - 1].push_back(first - 1);

        unseenEdges.insert(OrderedPair(first - 1, second - 1));
    }

    vector<bool> seenNodes(graph.size());

    if (!DFS(graph, 0, seenNodes, unseenEdges)) {
        cout << "NO" << endl;
        return 0;
    }

    for (const auto& item : seenNodes) {
        if (!item) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
