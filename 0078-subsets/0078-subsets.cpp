class Solution {
public:
    void subsetsUtil(vector<int>& nums, int ind, int n, vector<int>& ans, vector<vector<int>>& res)
    {
        if(ind >= n)
        {
            res.push_back(ans);
            return;
        }
        
        ans.push_back(nums[ind]);
        
        subsetsUtil(nums, ind + 1, n, ans, res);
        
        ans.pop_back();
        
        subsetsUtil(nums, ind + 1, n, ans, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        int n = nums.size();
        subsetsUtil(nums, 0, n, ans, res);
        return res;
    }
};