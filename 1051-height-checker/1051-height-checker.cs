public class Solution {
    public int HeightChecker(int[] heights) {
        int[] weights = new int[heights.Length];
        Array.Copy(heights, weights, heights.Length);
        Array.Sort(weights);
        
        int n = heights.Length;
        int count = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (heights[i] != weights[i])
            {
                count++;
            }
        }
        
        return count;
    }
}