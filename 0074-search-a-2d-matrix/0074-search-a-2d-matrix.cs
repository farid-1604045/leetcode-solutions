public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
        int row = matrix.Length;  // Get the number of rows
        int col = matrix[0].Length;  // Get the number of columns
        bool ans = false;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == target) {
                    ans = true;
                    break;
                }
            }
            if (ans) {
                break;  // Break the outer loop if target is found
            }
        }
        
        return ans;
    }
}