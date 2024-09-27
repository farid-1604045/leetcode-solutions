class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + n), right(nums.begin() + n, nums.end());
        
        // Helper function to generate all subset sums of size k from a given array
        auto subsetSums = [](const vector<int>& arr) {
            int n = arr.size();
            vector<vector<int>> result(n + 1); // result[i] contains all subset sums of size i
            result[0] = {0};
            for (int num : arr) {
                for (int i = n - 1; i >= 0; --i) {
                    for (int sum : result[i]) {
                        result[i + 1].push_back(sum + num);
                    }
                }
            }
            return result;
        };
        
        // Generate all subset sums for left and right halves
        vector<vector<int>> leftSums = subsetSums(left), rightSums = subsetSums(right);
        
        // Total sum of all elements
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int halfSum = totalSum / 2;
        int minDiff = INT_MAX;
        
        // For each size, find the best partition by comparing left and right subsets
        for (int i = 0; i <= n; ++i) {
            sort(rightSums[n - i].begin(), rightSums[n - i].end());
            for (int leftSum : leftSums[i]) {
                int target = halfSum - leftSum;
                auto it = lower_bound(rightSums[n - i].begin(), rightSums[n - i].end(), target);
                // Check two closest sums on the right side
                if (it != rightSums[n - i].end()) {
                    int rightSum = *it;
                    int subsetSum = leftSum + rightSum;
                    minDiff = min(minDiff, abs(totalSum - 2 * subsetSum));
                }
                if (it != rightSums[n - i].begin()) {
                    int rightSum = *(--it);
                    int subsetSum = leftSum + rightSum;
                    minDiff = min(minDiff, abs(totalSum - 2 * subsetSum));
                }
            }
        }
        
        return minDiff;
    }
};