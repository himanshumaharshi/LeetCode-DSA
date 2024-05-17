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
private:
    TreeNode* solve(TreeNode* root,int target){
        if(root==NULL){
            return NULL;
        }
        
        root->left=solve(root->left,target);
        root->right=solve(root->right,target);
        if(root->left==NULL && root->right==NULL){
            if((root->val) == target){
                return NULL;
            }
            else{
                return root;
            }
        }
        return root;
        
    } 
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root->val ==target && root->right==NULL && root->left==NULL ){
            return NULL;
        }
        return solve(root,target);
        
    }
};