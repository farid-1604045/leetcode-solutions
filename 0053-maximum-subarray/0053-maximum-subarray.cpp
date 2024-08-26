class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxi = LONG_MIN;
        long long sum = 0;
        int n = nums.size();
        int start = 0;
        int ansStart = -1, ansEnd = -1;
        for (int i = 0; i < n; i++) {

            if (sum == 0) start = i; // starting index

            sum += nums[i];

            if (sum > maxi) {
                maxi = sum;

                ansStart = start;
                ansEnd = i;
            }

            // If sum < 0: discard the sum calculated
            if (sum < 0) {
                sum = 0;
            }
        }
        
        return maxi;
    }
};