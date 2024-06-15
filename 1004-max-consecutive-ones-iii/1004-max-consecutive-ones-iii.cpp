class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLength = 0;
        int start = 0;
        int zeroCount = 0;

        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] == 0) {
                zeroCount++;
            }

            while (zeroCount > k) {
                if (nums[start] == 0) {
                    zeroCount--;
                }
                start++;
            }

            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};