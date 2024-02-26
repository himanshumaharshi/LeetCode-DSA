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

    void printRightView(TreeNode *root, vector<int> &ans, int level)
    {
        // base case
        if (root == NULL)
            return;

        if (level == ans.size())
            ans.push_back(root->val);

        // right call
        printRightView(root->right, ans, level + 1);
        // left call
        printRightView(root->left, ans, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int level = 0;
        printRightView(root, ans,  level);
        return ans;
    }
};