class Solution {
public:
    void findSubsets(int ind, int n, vector<int>& nums, vector<int>& ds, vector<vector<int>>& result) {       
            result.push_back(ds);

            for (int i = ind; i < n; i++) {
                // Skip duplicates
                if (i > ind && nums[i] == nums[i - 1]) continue;

                ds.push_back(nums[i]); // Include nums[i] in the subset
                findSubsets(i + 1, n, nums, ds, result); // Recursive call for the next element
                ds.pop_back(); // Backtrack
        }
    }
    
  vector < vector < int >> subsetsWithDup(vector < int > & nums) {
      
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        vector<vector<int>> result;
        vector<int> ds;
        int n = nums.size();
        findSubsets(0, n, nums, ds, result);

        return result;
  }
};