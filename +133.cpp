/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    std::unordered_map<int, Node*> nodeMap;

    Node* dfs(Node* node) {
        if (nodeMap.find(node->val) != nodeMap.end()) {
            return nodeMap[node->val];
        }
        else {
            Node* copy = new Node(node->val);
            nodeMap[node->val] = copy;
            for (const auto& nei : node->neighbors) {
                copy->neighbors.push_back(dfs(nei));
            }
            return copy;
        }
    }

public:
    Node* cloneGraph(Node* node) {
        return node ? dfs(node) : nullptr;
    }
};
