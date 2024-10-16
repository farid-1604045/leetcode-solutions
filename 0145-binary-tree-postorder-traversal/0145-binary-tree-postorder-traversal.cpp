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
    void getPostOrderTraversalUtil(TreeNode *root, vector<int>& postorderTraversalVector)
    {
        if(root == nullptr)
        {
            return;
        }

        getPostOrderTraversalUtil(root->left, postorderTraversalVector);
        getPostOrderTraversalUtil(root->right, postorderTraversalVector);
        postorderTraversalVector.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorderTraversalVector;
        getPostOrderTraversalUtil(root, postorderTraversalVector);
        return postorderTraversalVector;
    }
};