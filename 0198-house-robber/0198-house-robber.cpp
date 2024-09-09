class Solution {
public:
    int f(int ind, vector<int>& nums, vector<int>& dp)
    {
        if(ind<0)
        {
            return 0;
        }
        
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        
        int not_take = 0 + f(ind-1, nums, dp);
        
        int take = f(ind-2, nums, dp) + nums[ind];
        
        return dp[ind] = max(take, not_take);;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return f(n-1, nums, dp);
    }
};