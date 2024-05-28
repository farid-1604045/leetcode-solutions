public class Solution {
    public int MinIncrementForUnique(int[] nums) {
        Array.Sort(nums);
        int count = 0;

        for (int i = 1; i < nums.Length; i++)
        {
            if (nums[i] == nums[i - 1])
            {
                int diff = 1;
                count += 1;
                nums[i] = nums[i] + diff;
            }
            else if (nums[i] < nums[i - 1])
            {
                int diff = Math.Abs(nums[i] - nums[i - 1]) + 1;
                count += diff;
                nums[i] = nums[i] + diff;
            }
        }

        return count;
    }
}