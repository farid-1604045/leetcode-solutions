class Solution {
public:
    void combSum(int ind, int n, vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& result)
    {       
        if(target == 0)
        {
            result.push_back(ds);
            return;
        }
            
        for(int i = ind; i<n; i++)
        {
            if(i > ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            
            ds.push_back(candidates[i]);
            combSum(i + 1, n, candidates, target - candidates[i], ds, result);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int>ds;
        int n = candidates.size();
        combSum(0, n, candidates, target, ds, result);
        
        return result;
    }
};