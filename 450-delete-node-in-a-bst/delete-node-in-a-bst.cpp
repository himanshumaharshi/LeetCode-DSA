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

    int maxVal(TreeNode* root) { // for max val of right subtree (method 1)
        TreeNode *temp = root;
        if (temp == NULL)
            return -1;
        while(temp->right != NULL) {
            temp = temp->right;
        }
        return temp->val;
    }

    // int minVal(TreeNode* root) { // for min val of left subtree (method 2)
    //     TreeNode *temp = root;
    //     if (temp == NULL)
    //         return -1;
    //     while(temp->left != NULL) {
    //         temp = temp->left;
    //     }
    //     return temp->val;
    // }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case
        if (root == NULL) {
            return NULL;
        }

        if (root->val == key) {
            // check four conditions
            if (root->left == NULL && root->right == NULL) {
                // we are at leaf node
                return NULL;
            }
            else if (root->left != NULL && root->right == NULL) {
                // node have only left child and no right child
                return root->left;
            }
            else if (root->left == NULL && root->right != NULL) {
                // node have only left child and no right child
                return root->right;
            }
            else {
                // node have both childs in this we have two methods
                // ---- method 1: maximum value from left subtree (inorder predecessor) ----
                int inorderPre = maxVal(root->left);
                root->val = inorderPre;
                root->left = deleteNode(root->left, inorderPre);
                return root;

                // ---- method 2: minimum value from right subtree (inorder successor) ----
                // int inorderSucc = minVal(root->right);
                // root->val = inorderSucc;
                // root->right = deleteNode(root->right, inorderSucc);
                // return root;
            }
        }
        else if (root->val < key) {
            // search in right subtree
            root->right = deleteNode(root->right, key);
        }
        else if (root->val > key) {
            // search in left subtree
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};