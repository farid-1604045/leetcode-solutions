class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        int prefix_sum = 0;
        unordered_map<int, int> remainder_freq;
        remainder_freq[0] = 1;

        for (int num : nums) {
            prefix_sum += num;
            int remainder = prefix_sum % k;
            if (remainder < 0)
                remainder += k;
            count += remainder_freq[remainder];
            remainder_freq[remainder]++;
        }

        return count;
    }
};