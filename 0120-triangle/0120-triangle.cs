public class Solution {
    public int MinimumPathSumUtil(int i, int j, IList<IList<int>> triangle, int n, int[][] dp)
    {
        if (i == n - 1)
        {
            return triangle[i][j];
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int down = triangle[i][j] + MinimumPathSumUtil(i + 1, j, triangle, n, dp);
        int diagonal = triangle[i][j] + MinimumPathSumUtil(i + 1, j + 1, triangle, n, dp);

        return dp[i][j] = Math.Min(down, diagonal);
    }
    public int MinimumTotal(IList<IList<int>> triangle) {
        int n = triangle.Count;
        int[][] dp = new int[n][];
        for (int i = 0; i < n; i++)
        {
            dp[i] = new int[n];
            Array.Fill(dp[i], -1);
        }

        return MinimumPathSumUtil(0, 0, triangle, n, dp);
    }
}