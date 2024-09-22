public class Solution {
    public int MinFallingPathSum(int[][] matrix) {
        int n = matrix.Length;
        int m = matrix[0].Length;
        
        int[][] dp = new int[n][];
        for (int i = 0; i < n; i++) {
            dp[i] = new int[m];
        }

        // Initialize dp for the first row
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Bottom-up dynamic programming
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = matrix[i][j] + dp[i - 1][j];

                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0) {
                    leftDiagonal += dp[i - 1][j - 1];
                } else {
                    leftDiagonal += (int)1e9; // A large constant instead of int.MaxValue
                }

                int rightDiagonal = matrix[i][j];
                if (j + 1 < m) {
                    rightDiagonal += dp[i - 1][j + 1];
                } else {
                    rightDiagonal += (int)1e9; // A large constant instead of int.MaxValue
                }

                dp[i][j] = Math.Min(up, Math.Min(leftDiagonal, rightDiagonal));
            }
        }

        // Find the minimum path sum from the last row
        int mini = int.MaxValue;
        for (int j = 0; j < m; j++) {
            mini = Math.Min(mini, dp[n - 1][j]);
        }

        return mini;
    }
}