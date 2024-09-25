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
        int halfOfSubsetValue;
        int n = nums.size();
        int totalOfSubsetValue = 0;
        for(int i=0; i<n; i++)
        {
            totalOfSubsetValue += nums[i];
        }
        if(totalOfSubsetValue % 2 != 0)
        {
            return false;
        } 
        
        halfOfSubsetValue = totalOfSubsetValue/2;
        
        vector<vector<int>>dp(n+1, vector<int>(halfOfSubsetValue+1, -1));
        
        return canPartitionUtil(n-1, halfOfSubsetValue, dp, nums);
    }
};