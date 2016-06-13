#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        return DFS(node, m);
    }
    UndirectedGraphNode* DFS(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& m) {
        if (m.find(node) != m.end()) {
            return m[node];
        }
        UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
        m[node] = copy;
        for (int i = 0; i < (int)node->neighbors.size(); i++) {
            copy->neighbors.push_back(DFS(node->neighbors[i], m));
        }
        return copy;
    }

};

int main() {
    Solution s;
    return 0;
}