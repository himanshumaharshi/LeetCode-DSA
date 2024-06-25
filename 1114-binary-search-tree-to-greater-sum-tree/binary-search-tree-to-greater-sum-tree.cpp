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
    TreeNode* solve(TreeNode*& root, int& sum) {
        if (root == NULL) {
            return root;
        }
        // make call for right side as we want to create greater tree
        // as largest value always reside in right side in BST
        if (root->right)
            solve(root->right, sum);
        
        // calculate sum with current root with previous sum
        sum += root->val;
        root->val = sum;

        // call for left side after calculating sum till root and right
        if (root->left)
            solve(root->left, sum);
            
        return root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return root;
    }
};