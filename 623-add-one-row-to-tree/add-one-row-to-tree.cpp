/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node, int level, int val) {
        if (node == nullptr)
            return;
        level -= 1;
        if (level == 1) {
            node->left = new TreeNode(val, node->left, nullptr);
            node->right = new TreeNode(val, nullptr, node->right);
        } else {
            dfs(node->left, level, val);
            dfs(node->right, level, val);
        }
        return;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1)
            return new TreeNode(val, root, nullptr);
        dfs(root, depth, val);
        return root;
    }
};