public class Solution {
    public int FindMaxK(int[] nums) {
        Dictionary<int, int> ump = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; i++) {
            if (ump.ContainsKey(nums[i])) {
                ump[nums[i]]++;
            } else {
                ump[nums[i]] = 1;
            }
        }

        int maxValue = int.MinValue;
        bool ok = false;
        for (int i = 0; i < nums.Length; i++) {
            if (ump.ContainsKey(-nums[i])) {
                ok = true;
                if (nums[i] > maxValue) {
                    maxValue = nums[i];
                }
            }
        }

        return (ok ? maxValue : -1);
    }
}