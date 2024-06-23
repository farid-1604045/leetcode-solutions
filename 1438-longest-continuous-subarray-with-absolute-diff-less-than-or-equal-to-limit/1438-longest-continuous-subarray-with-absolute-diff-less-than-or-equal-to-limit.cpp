class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int left = 0, right;
        int maxLength = 0;

        for (right = 0; right < nums.size(); ++right) {
            // Maintain the decreasing deque for the max value in the current window
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right])
                maxDeque.pop_back();
            maxDeque.push_back(right);

            // Maintain the increasing deque for the min value in the current window
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right])
                minDeque.pop_back();
            minDeque.push_back(right);

            // If the window is invalid, move the left pointer to the right
            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {
                ++left;
                if (maxDeque.front() < left) maxDeque.pop_front();
                if (minDeque.front() < left) minDeque.pop_front();
            }

            // Update the maxLength
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};