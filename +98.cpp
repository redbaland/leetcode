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
    bool isValidBST(TreeNode* root) {
        return validateSubtree(root, std::numeric_limits<long>::min(), \
            std::numeric_limits<long>::max());
    }
private:
    bool validateSubtree(TreeNode* node, long min, long max) {
        if (!node) {
            return true;
        }
        if (node->val > min && node->val < max) {
            return validateSubtree(node->left, min, node->val) && \
                validateSubtree(node->right, node->val, max);
        }
        else return false;
    }
};
