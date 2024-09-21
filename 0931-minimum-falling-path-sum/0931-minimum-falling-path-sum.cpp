class Solution {
public:
    int minFallingPathSumUtil(int i, int j, vector<vector<int> > &triangle, int n, vector<vector<int> > &dp) {
        if (i == n - 1)
            return triangle[i][j];
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int down = INT_MAX, diagonal = INT_MAX, leftdiagonal = INT_MAX;
        
        down = triangle[i][j] + minFallingPathSumUtil(i + 1, j, triangle, n, dp);

        if (j + 1 < n)
            diagonal = triangle[i][j] + minFallingPathSumUtil(i + 1, j + 1, triangle, n, dp);

        if (j - 1 >= 0)
            leftdiagonal = triangle[i][j] + minFallingPathSumUtil(i + 1, j - 1, triangle, n, dp);
        
        return dp[i][j] = min(min(down, diagonal), leftdiagonal);
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = matrix[i][j] + dp[i - 1][j];

                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0) {
                    leftDiagonal += dp[i - 1][j - 1];
                } else {
                    leftDiagonal += 1e9; 
                }

                int rightDiagonal = matrix[i][j];
                if (j + 1 < m) {
                    rightDiagonal += dp[i - 1][j + 1];
                } else {
                    rightDiagonal += 1e9; 
                }

                dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
            }
        }

        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, dp[n - 1][j]);
        }

        return mini;
    }
};