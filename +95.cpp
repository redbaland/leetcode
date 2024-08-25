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
    std::vector<TreeNode*> generateTrees(int n) {
        return generateFromTo(1, n);
    }
private:
    std::vector<TreeNode*> generateFromTo(int start, int end) {
        if (start > end) {
            return {nullptr};
        }
        std::vector<TreeNode*> ans;
        for (int i = start; i <= end; i++) {
            std::vector<TreeNode*> leftSubtree = generateFromTo(start, i - 1);
            std::vector<TreeNode*> rightSubtree = generateFromTo(i + 1, end);
            for (auto l : leftSubtree) {
                for (auto r : rightSubtree) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
