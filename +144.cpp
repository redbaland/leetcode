/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        std::stack<TreeNode*> stack;
        while (root || !stack.empty()) {    
            while (root) {
                stack.push(root);
                res.push_back(root->val);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            root = root->right;
        }
        return res;
    }
};
