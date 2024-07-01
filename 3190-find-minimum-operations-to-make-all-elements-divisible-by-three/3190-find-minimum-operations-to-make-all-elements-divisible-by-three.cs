public class Solution {
    public int MinimumOperations(int[] nums) {
        int minOperation = 0;
        int n = nums.Length;
        for(int i=0; i<n; i++)
        {
            if(nums[i]%3 != 0)
            {
                minOperation++;
            }
        }
        return minOperation;
    }
}