class Solution {
public:
    int mazeObstaclesUtil(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid)
    {
        if(row>=0 && col>=0 && obstacleGrid[row][col] == 1)
        {
            return 0;
        }
        
        if(row == 0 && col == 0)
        {
            return 1;
        }
        
        if(row<0 || col<0)
        {
            return 0;
        }
        
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }
        
        int up = mazeObstaclesUtil(row-1, col, dp, obstacleGrid);
        int left = mazeObstaclesUtil(row, col-1, dp, obstacleGrid);
        
        return dp[row][col] = up+left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return mazeObstaclesUtil(n-1, m-1, dp, obstacleGrid);
    }
};