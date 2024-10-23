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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root)
        {
            return nullptr;
        }
        
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({NULL, root});
        
        while(q.size())
        {
            int s = q.size();
            int layerSum = 0;
            unordered_map<TreeNode*, int> sumForParent;
            vector<pair<TreeNode*, TreeNode*>> layer;
            while(s--)
            {
                auto [parent, node] = q.front();
                q.pop();
                layer.push_back({parent, node});        
                layerSum += node->val;
                sumForParent[parent] += node->val;
                if(node->left)
                {
                    q.push({node, node->left});
                }
                
                if(node->right)
                {
                    q.push({node, node->right});
                }
            }
            
            for(auto [parent, node] : layer)
            {
                node->val = layerSum - sumForParent[parent];
            }
        }
        
        return root;
    }
};