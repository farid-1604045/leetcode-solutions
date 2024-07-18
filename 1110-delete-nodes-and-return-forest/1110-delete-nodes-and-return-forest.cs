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
    private HashSet<int> toDeleteSet;
    
    private TreeNode Dfs(TreeNode node, bool isRoot, List<TreeNode> result) {
        if (node == null) return null;
        
        bool deleted = toDeleteSet.Contains(node.val);
        
        if (isRoot && !deleted) {
            result.Add(node);
        }
        
        node.left = Dfs(node.left, deleted, result);
        node.right = Dfs(node.right, deleted, result);
        
        return deleted ? null : node;
    }
    
    public IList<TreeNode> DelNodes(TreeNode root, int[] to_delete) {
        toDeleteSet = new HashSet<int>(to_delete);
        List<TreeNode> result = new List<TreeNode>();
        Dfs(root, true, result);
        return result;
    }
}