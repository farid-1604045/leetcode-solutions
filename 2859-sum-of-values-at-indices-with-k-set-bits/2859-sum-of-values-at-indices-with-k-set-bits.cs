public class Solution {
    public int SumIndicesWithKSetBits(IList<int> nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.Count; i++)
        {
            int binary = 0;
            int x = i;
            while (x != 0)
            {
                binary += x % 2;
                if (binary > k) break;
                x /= 2;
            }
            if (binary == k) sum += nums[i];
        }
        return sum;
    }
}