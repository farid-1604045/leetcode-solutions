class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return AtMost(nums, goal) - AtMost(nums, goal - 1);
    }
private:
    int AtMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int left = 0, right = 0, sum = 0, count = 0;
        
        while (right < nums.size()) {
            sum += nums[right];

            while (sum > goal) {
                sum -= nums[left];
                left++;
            }

            count += right - left + 1;
            right++;
        }

        return count;
    }
};