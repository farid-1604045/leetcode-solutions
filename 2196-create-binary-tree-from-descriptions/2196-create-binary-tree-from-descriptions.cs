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
    public TreeNode CreateBinaryTree(int[][] descriptions) {
        var nodes = new Dictionary<int, TreeNode>();
        var children = new HashSet<int>();
        
        // Create nodes and keep track of all children
        foreach (var desc in descriptions) {
            int parent = desc[0], child = desc[1], isLeft = desc[2];
            
            if (!nodes.ContainsKey(parent)) {
                nodes[parent] = new TreeNode(parent);
            }
            if (!nodes.ContainsKey(child)) {
                nodes[child] = new TreeNode(child);
            }
            
            if (isLeft == 1) {
                nodes[parent].left = nodes[child];
            } else {
                nodes[parent].right = nodes[child];
            }
            
            children.Add(child);
        }
        
        // The root is the node which is not a child of any other node
        TreeNode root = null;
        foreach (var node in nodes) {
            if (!children.Contains(node.Key)) {
                root = node.Value;
                break;
            }
        }
        
        return root;
    }
}