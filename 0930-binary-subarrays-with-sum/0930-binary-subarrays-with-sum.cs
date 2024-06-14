public class Solution {
    public int NumSubarraysWithSum(int[] nums, int goal) {
        Dictionary<int, int> cumulativeSumCount = new Dictionary<int, int>();
        cumulativeSumCount[0] = 1;  // Initialize with sum 0 occurring once
        int cumulativeSum = 0;
        int count = 0;

        foreach (int num in nums) {
            cumulativeSum += num;

            if (cumulativeSumCount.ContainsKey(cumulativeSum - goal)) {
                count += cumulativeSumCount[cumulativeSum - goal];
            }

            if (cumulativeSumCount.ContainsKey(cumulativeSum)) {
                cumulativeSumCount[cumulativeSum]++;
            } else {
                cumulativeSumCount[cumulativeSum] = 1;
            }
        }

        return count;
    }
}