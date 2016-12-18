#include <iostream>
#include <vector>

using namespace std;

using uint = unsigned int;
using PathLengthWithNode = pair<uint, uint>;

PathLengthWithNode FindFarthestNode(const vector<vector<uint>>& graph, uint rootNode, uint prevNode) {
    PathLengthWithNode farthestNode = {0, rootNode};

    for (const auto& childNode : graph[rootNode]) {
        if (childNode == prevNode) {
            continue;
        }

        auto farthestChildNode = FindFarthestNode(graph, childNode, rootNode);
        ++farthestChildNode.first;
        if (farthestNode < farthestChildNode) {
            farthestNode = farthestChildNode;
        }
    }

    return farthestNode;
}

int main(int /*argc*/, char ** /*argv*/) {
    uint nNodes;
    cin >> nNodes;

    vector<vector<uint>> graph(nNodes);
    for (uint i = 0; i < nNodes - 1; ++i) {
        uint from, to;
        cin >> from >> to;

        graph[from - 1].push_back(to - 1);
        graph[to - 1].push_back(from - 1);
    }

    auto farthestNode = FindFarthestNode(graph, 0, 0);
    farthestNode = FindFarthestNode(graph, farthestNode.second, farthestNode.second);

    cout << farthestNode.first << endl;

    return 0;
}
