public class Solution {
    public bool CheckSubarraySum(int[] nums, int k) {
        Dictionary<int, int> mp = new Dictionary<int, int>();
        mp[0] = -1;
        int sum = 0;

        for (int i = 0; i < nums.Length; i++) {
            sum += nums[i];
            int mod = sum % k;
            if (!mp.ContainsKey(mod)) {
                mp[mod] = i;
            } else if (i - mp[mod] > 1) {
                return true;
            }
        }
        return false;
    }
}