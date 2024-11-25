class Solution {
public:
    void permuteUtil(int n, vector<int>& nums, vector<bool>& freq, vector<int>& ds, vector<vector<int>>& result)
    {
        if(ds.size() == n)
        {
            result.push_back(ds);
            return;
        }
        for(int i = 0; i < n; i++)
        {
            if(!freq[i])
            {
                freq[i] = true;
                ds.push_back(nums[i]);
                permuteUtil(n, nums, freq, ds, result);
                ds.pop_back();
                freq[i] = false;
            } 
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> ds;
        vector<bool> freq(n, false);
        permuteUtil(n, nums, freq, ds, result);
        
        return result;
    }
};