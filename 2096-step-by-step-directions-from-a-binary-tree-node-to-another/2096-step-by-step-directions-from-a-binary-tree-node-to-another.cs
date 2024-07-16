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
    private bool Find(TreeNode n, int val, StringBuilder path) {
        if (n == null) return false;
        if (n.val == val) return true;
        
        if (n.left != null && Find(n.left, val, path)) {
            path.Append('L');
        } else if (n.right != null && Find(n.right, val, path)) {
            path.Append('R');
        }
        
        return path.Length > 0;
    }

    public string GetDirections(TreeNode root, int startValue, int destValue) {
        StringBuilder sPath = new StringBuilder();
        StringBuilder dPath = new StringBuilder();
        
        Find(root, startValue, sPath);
        Find(root, destValue, dPath);
        
        while (sPath.Length > 0 && dPath.Length > 0 && sPath[sPath.Length - 1] == dPath[dPath.Length - 1]) {
            sPath.Length--;
            dPath.Length--;
        }
        
        return new string('U', sPath.Length) + new string(dPath.ToString().ToCharArray().Reverse().ToArray());
    }
}