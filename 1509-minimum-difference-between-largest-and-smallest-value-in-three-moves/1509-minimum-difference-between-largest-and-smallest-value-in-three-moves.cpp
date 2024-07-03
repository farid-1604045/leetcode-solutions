class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        
        sort(nums.begin(), nums.end());

        int scenario1 = nums[n-4] - nums[0];
        int scenario2 = nums[n-3] - nums[1];
        int scenario3 = nums[n-2] - nums[2];
        int scenario4 = nums[n-1] - nums[3];

        return min({scenario1, scenario2, scenario3, scenario4});
    }
};