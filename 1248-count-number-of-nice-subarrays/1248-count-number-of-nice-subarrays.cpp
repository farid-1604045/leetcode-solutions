class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int oddCount = 0, niceSubarrays = 0;
        
        for (int num : nums) {
            if (num % 2 != 0) {
                oddCount++;
            }
            if (prefixCount.find(oddCount - k) != prefixCount.end()) {
                niceSubarrays += prefixCount[oddCount - k];
            }
            prefixCount[oddCount]++;
        }
        
        return niceSubarrays;
    }
};