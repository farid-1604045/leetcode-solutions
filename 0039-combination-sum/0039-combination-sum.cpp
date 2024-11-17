class Solution {
public:
    void findCombination(int ind, int sum, int n, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& ds)
    {
        if(ind >= n)
        {
            if(sum == target)
            {
                ans.push_back(ds);
            }
            
            return;
        }
        
        ds.push_back(candidates[ind]);
        
        if(sum + candidates[ind] <= target)
        {
            findCombination(ind, sum + candidates[ind], n, target, candidates, ans, ds);
        }
        
        ds.pop_back();

        findCombination(ind + 1, sum, n, target, candidates, ans, ds);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(0, 0, n, target, candidates, ans, ds);
        return ans;
    }
};