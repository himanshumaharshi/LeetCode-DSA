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
    void solve(TreeNode* root, string str, vector<string>& ans) {
        if (root == NULL)
            return;
        char ch = root->val + 'a';
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(ch + str);
            return;
        }
        if (root->left)
            solve(root->left, ch + str, ans);
        if (root->right)
            solve(root->right, ch + str, ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> ans;
        string str = "";
        solve(root, str, ans);
        sort(ans.begin(), ans.end());
        return ans[0];
    }
};