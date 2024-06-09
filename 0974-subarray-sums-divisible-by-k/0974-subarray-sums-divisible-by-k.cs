public class Solution {
    public int SubarraysDivByK(int[] nums, int k) {
        int count = 0;
        int prefixSum = 0;
        Dictionary<int, int> remainderFreq = new Dictionary<int, int>();
        remainderFreq[0] = 1; // Initialize with one occurrence of 0 remainder

        foreach (int num in nums)
        {
            prefixSum += num;
            int remainder = prefixSum % k;
            if (remainder < 0) // Ensure remainder is positive
                remainder += k;
            count += remainderFreq.GetValueOrDefault(remainder);
            if (remainderFreq.ContainsKey(remainder))
                remainderFreq[remainder]++;
            else
                remainderFreq[remainder] = 1;
        }

        return count;
    }
}