/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
   
    private int sum = 0;
    
    public TreeNode BstToGst(TreeNode root) {
        Traverse(root);
        return root;
    }
    
    private void Traverse(TreeNode node) {
        if (node == null) return;
        
        // Traverse right subtree
        Traverse(node.right);
        
        // Update the current node's value
        sum += node.val;
        node.val = sum;
        
        // Traverse left subtree
        Traverse(node.left);
    }
}