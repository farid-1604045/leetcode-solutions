class Solution {
public:
    bool canPartitionUtil(int ind, int target, vector<vector<int>>& dp, vector<int>& nums)
    {
        if(target == 0)
        {
            return true;
        }
        
        if(ind == 0)
        {
            return target == nums[0];
        }
        
        if(dp[ind][target] != -1)
        {
            return dp[ind][target];
        }
        
        bool notTake = canPartitionUtil(ind-1, target, dp, nums);
        
        bool taken = false;
        
        if(nums[ind] <= target)
        {
            taken = canPartitionUtil(ind-1, target-nums[ind], dp, nums);
        }
        
        return dp[ind][target] = taken || notTake;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalOfSubsetValue = 0;

        // Calculate the total sum of the array
        for(int i = 0; i < n; i++) {
            totalOfSubsetValue += nums[i];
        }

        // If the total sum is odd, we cannot partition it into two equal subsets
        if(totalOfSubsetValue % 2 != 0) {
            return false;
        }

        int halfOfSubsetValue = totalOfSubsetValue / 2;

        // Create a DP table with dimensions (n) x (halfOfSubsetValue + 1)
        vector<vector<bool>> dp(n, vector<bool>(halfOfSubsetValue + 1, false));

        // Base case: A sum of 0 can always be formed with an empty subset
        for(int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Base case: If we have only one element, we can form a subset with sum nums[0]
        // if(nums[0] <= halfOfSubsetValue) {
        //     dp[0][nums[0]] = true;
        // }
        for (int target = 0; target <= halfOfSubsetValue; target++) {
            dp[0][target] = (nums[0] == target);
        }

        // Fill the dp table
        for(int ind = 1; ind < n; ind++) {
            for(int target = 1; target <= halfOfSubsetValue; target++) {
                // Exclude the current element
                bool notTaken = dp[ind-1][target];

                // Include the current element if it doesn't exceed the target
                bool taken = false;
                if(nums[ind] <= target) {
                    taken = dp[ind-1][target - nums[ind]];
                }

                // Store the result
                dp[ind][target] = notTaken || taken;
            }
        }

        // The answer will be stored at dp[n-1][halfOfSubsetValue]
        return dp[n-1][halfOfSubsetValue];
        
        
//         int halfOfSubsetValue;
//         int n = nums.size();
//         int totalOfSubsetValue = 0;
//         for(int i=0; i<n; i++)
//         {
//             totalOfSubsetValue += nums[i];
//         }
//         if(totalOfSubsetValue % 2 != 0)
//         {
//             return false;
//         } 
        
//         halfOfSubsetValue = totalOfSubsetValue/2;
        
//         vector<vector<int>>dp(n+1, vector<int>(halfOfSubsetValue+1, -1));
        
//         return canPartitionUtil(n-1, halfOfSubsetValue, dp, nums);
    }
};