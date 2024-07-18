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
    public int CountPairs(TreeNode root, int distance) {
        int count = 0;

        List<int> Dfs(TreeNode node) {
            if (node == null) return new List<int>();

            // If it's a leaf node, return a list with a single element, 1 (distance from the leaf itself)
            if (node.left == null && node.right == null) return new List<int> { 1 };

            List<int> leftDistances = Dfs(node.left);
            List<int> rightDistances = Dfs(node.right);

            // Count pairs from left and right subtrees
            foreach (int ld in leftDistances) {
                foreach (int rd in rightDistances) {
                    if (ld + rd <= distance) {
                        count++;
                    }
                }
            }

            // Prepare distances to propagate up the tree
            List<int> currentDistances = new List<int>();
            foreach (int ld in leftDistances) {
                if (ld + 1 <= distance) {
                    currentDistances.Add(ld + 1);
                }
            }
            foreach (int rd in rightDistances) {
                if (rd + 1 <= distance) {
                    currentDistances.Add(rd + 1);
                }
            }

            return currentDistances;
        }

        Dfs(root);
        return count;
    }
}