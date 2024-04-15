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
    void inorder(TreeNode* root, long num, long& sum) {
        if (!root)
            return;

        num += root->val;
        if (!root->left && !root->right)
            sum += num;

        inorder(root->left, num * 10, sum);
        inorder(root->right, num * 10, sum);
    }
    int sumNumbers(TreeNode* root) {
        long num = 0, sum = 0;
        inorder(root, num, sum);
        return sum;
    }
};