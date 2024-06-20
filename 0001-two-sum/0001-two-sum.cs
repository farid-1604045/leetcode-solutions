public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int n = nums.Length;
        Dictionary<int, int> ump = new Dictionary<int, int>();
        int[] result = new int[2];

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (ump.ContainsKey(complement) && ump[complement] != i) {
                result[0] = ump[complement];
                result[1] = i;
                return result;
            }
            if (!ump.ContainsKey(nums[i])) {
                ump[nums[i]] = i;
            }
        }
        return null;
    }
}