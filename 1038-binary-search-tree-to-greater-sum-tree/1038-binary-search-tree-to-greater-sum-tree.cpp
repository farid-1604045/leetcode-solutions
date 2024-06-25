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
    int sum = 0;
    
    void Traverse(TreeNode* node) {
        if (node == nullptr) return;
        
        // Traverse right subtree
        Traverse(node->right);
        
        // Update the current node's value
        sum += node->val;
        node->val = sum;
        
        // Traverse left subtree
        Traverse(node->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        Traverse(root);
        return root;
    }
};