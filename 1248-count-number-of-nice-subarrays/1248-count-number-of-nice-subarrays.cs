public class Solution {
    public int NumberOfSubarrays(int[] nums, int k) {
        Dictionary<int, int> prefixCount = new Dictionary<int, int>();
        prefixCount[0] = 1; // Initialize with 0 odd count seen once
        int oddCount = 0, niceSubarrays = 0;
        
        foreach (int num in nums) {
            if (num % 2 != 0) {
                oddCount++;
            }
            if (prefixCount.ContainsKey(oddCount - k)) {
                niceSubarrays += prefixCount[oddCount - k];
            }
            if (prefixCount.ContainsKey(oddCount)) {
                prefixCount[oddCount]++;
            } else {
                prefixCount[oddCount] = 1;
            }
        }
        
        return niceSubarrays;
    }
}