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
    void inorderTraversal(TreeNode* root, vector<int>& inorder) {
        if (root == NULL) {
            return;
        }
        // left node call
        inorderTraversal(root->left, inorder);
        // push current value in inorder vector
        inorder.push_back(root->val);
        // right node call
        inorderTraversal(root->right, inorder);
    }
    TreeNode* createBST(vector<int> inorder, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int mid = start + (end - start) / 2;
        // create new Node
        TreeNode* newNode = new TreeNode(inorder[mid]);

        // call for left
        newNode->left = createBST(inorder, start, mid - 1);

        // call for right
        newNode->right = createBST(inorder, mid + 1, end);

        return newNode;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        // traverse tree using inorder traversal so that we have elements in array in sorted order
        inorderTraversal(root, inorder);

        // now create new BST using inorder traversal output
        // in this call we have (inorder array, array starting index, array ending index)
        TreeNode* BST = createBST(inorder, 0, inorder.size() - 1);
        
        return BST;
    }
};