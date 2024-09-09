class Solution {
public:
    int solveUtil(int ind, int start, vector<int>& arr, vector<int>& dp) {
        
        if(ind<start)
        {
            return 0;
        }
        if (dp[ind] != -1)
            return dp[ind];
        
        int pick = arr[ind] + solveUtil(ind - 2, start, arr, dp);
        int nonPick = 0 + solveUtil(ind - 1, start, arr, dp); 

        return dp[ind] = max(pick, nonPick);
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        vector<int> dp1(n+1, -1);
        int max1 = solveUtil(n - 2, 0, nums, dp1);
        
        vector<int> dp2(n+1, -1);
        int max2 = solveUtil(n - 1, 1, nums, dp2);
        
        return max(max1, max2);
    }
};