public class Solution {
    public int[] LeftRightDifference(int[] nums) {
        List<int> leftsum = new List<int>();
        List<int> rightsum = new List<int>();
        int left = 0;
        int right = 0;
        
        leftsum.Add(left);
        for (int i = 0; i < nums.Length - 1; i++)
        {
            left = left + nums[i];
            leftsum.Add(left);
        }
        
        for (int i = 1; i < nums.Length; i++)
        {
            right = right + nums[i];
        }
        
        rightsum.Add(right);
        
        for (int i = 1; i < nums.Length; i++)
        {
            right = right - nums[i];
            rightsum.Add(right);
        }
        
        List<int> ans = new List<int>();
        
        for (int i = 0; i < nums.Length; i++)
        {
            ans.Add(Math.Abs(leftsum[i] - rightsum[i]));
        }
        
        return ans.ToArray();
    }
}