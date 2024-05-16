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
    bool dfs(TreeNode* root) {
        if (root == NULL)
            return false;

        if (root->left == NULL || root->right == NULL) {
            return root->val;
        }

        bool leftAns;
        if (root->left) {
            leftAns = dfs(root->left);
        }

        bool rightAns;
        if (root->right) {
            rightAns = dfs(root->right);
        }

        if (root->val == 2)
            return leftAns || rightAns;
        else
            return leftAns && rightAns;
    }
    bool evaluateTree(TreeNode* root) {
        bool result = dfs(root);
        return result;
    }
};