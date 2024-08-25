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
    void recoverTree(TreeNode* root) {
        inorderSearch(root);
        swap(swapA->val, swapB->val);
    }
private:
    TreeNode* swapA = nullptr;
    TreeNode* swapB = nullptr;
    TreeNode* prev = new TreeNode(std::numeric_limits<int>::min());

    void inorderSearch(TreeNode* curr) {
        if (!curr) {
            return;
        }
        inorderSearch(curr->left);
        if (!swapA && curr->val < prev->val) { // first node to swap will be
            swapA = prev;                      // bigger than needed in bst
        }
        if (swapA && curr->val < prev->val) {  // second will be smaller
            swapB = curr;
        }
        prev = curr;
        inorderSearch(curr->right);
    }
};
