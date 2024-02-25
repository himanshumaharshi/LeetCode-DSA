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

    bool solve(TreeNode* root, long long int lowerBound, long long int upperBound) {
        if (root == NULL) {
            return true;
        }
        if (root->val > lowerBound && root->val < upperBound) {
            bool leftAns = solve(root->left, lowerBound, root->val);
            bool rightAns = solve(root->right, root->val, upperBound);
            return leftAns && rightAns;
        }
        else {
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        long long int lowerBound = LLONG_MIN;
        long long int upperBound = LLONG_MAX;
        bool ans = solve(root, lowerBound, upperBound);
        return ans;
    }
};