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

    int height(TreeNode* root) {
        // base case
        if (root == NULL)
            return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int ans = max(leftHeight, rightHeight) + 1;
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        // base case
        if(root == NULL) {
            return true;
        }
        // first case
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int difference = abs(leftHeight - rightHeight);

        bool ans1 = (difference <= 1);

        // Recusive part
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        if (ans1 && leftAns && rightAns)
            return true;
        else
            return false;
    }
};