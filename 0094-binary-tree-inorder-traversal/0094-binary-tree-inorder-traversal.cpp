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
    void getInOrderTraversalUtil(TreeNode *root, vector<int>& inorderTraversalVector)
    {
        if(root == nullptr)
        {
            return;
        }

        getInOrderTraversalUtil(root->left, inorderTraversalVector);
        inorderTraversalVector.push_back(root->val);
        getInOrderTraversalUtil(root->right, inorderTraversalVector);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderTraversalVector;
        getInOrderTraversalUtil(root, inorderTraversalVector);
        return inorderTraversalVector;
    }
};