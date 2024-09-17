class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int>result(n+1, 0);
        for(int i=0; i<n; i++)
        {
            if(result[nums[i]] == 0)
            {
                result[nums[i]]++;
            }
            
            else
            {
                return nums[i];
            }
        }
        
        return -1;
    }
};