public class Solution {
    public int RemoveDuplicates(int[] nums) {
        int n = nums.Length;
        int i = 0;
        for(int j=1; j<n; j++)
        {
            if(nums[i]!=nums[j])
            {
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
}