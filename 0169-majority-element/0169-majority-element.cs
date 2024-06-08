public class Solution {
    public int MajorityElement(int[] nums) {
        int n = nums.Length;
        int m = n / 2;
        Dictionary<int, int> ump = new Dictionary<int, int>();

        for (int i = 0; i < n; i++) {
            if (ump.ContainsKey(nums[i])) {
                ump[nums[i]]++;
            } else {
                ump[nums[i]] = 1;
            }
        }

        foreach (var it in ump) {
            if (it.Value > m) {
                return it.Key;
            }
        }

        return -1;
    }
}