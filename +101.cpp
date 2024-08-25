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
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isSame(root->left, root->right);
    }
private:
    bool isSame(TreeNode* first, TreeNode* second) {
        if (!first && !second) {
            return true;
        }
        else if (first && second && first->val == second->val) {
            return isSame(first->left, second->right) \
                && isSame(first->right, second->left);
        }
        else {
            return false;
        }
    }
};
