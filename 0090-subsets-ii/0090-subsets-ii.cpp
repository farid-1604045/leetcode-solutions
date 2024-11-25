class Solution {
public:
    void uniqueSubsetsUtil(int ind, int n, vector<int>& arr, vector<int>& ans, vector<vector<int>>& res)
    {
        if(ind >= n)
        {
            res.push_back(ans);
            return;
        }

        ans.push_back(arr[ind]);
        uniqueSubsetsUtil(ind + 1, n, arr, ans, res);
        ans.pop_back();
        uniqueSubsetsUtil(ind + 1, n, arr, ans, res);
    }
    
  vector < vector < int >> subsetsWithDup(vector < int > & nums) {
      
     int n = nums.size();
     sort(nums.begin(), nums.end());
     vector<int> ans;
     vector<vector<int>> res;
     uniqueSubsetsUtil(0, n, nums, ans, res);
     set<vector<int>> finalRes;
     finalRes.insert(res.begin(), res.end());
     res.assign(finalRes.begin(), finalRes.end());
     return res;
  }
};