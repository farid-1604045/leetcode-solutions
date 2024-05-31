class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int>ump;
        for(int i=0; i<nums.size(); i++)
        {
            ump[nums[i]]++;
        }
        
        int maxValue = INT_MIN;
        bool ok = 0;
        for(int i=0; i<nums.size(); i++)
        {
            auto it = ump.find(-nums[i]);
            if(it != ump.end())
            {
                ok = 1;
                if(nums[i]>maxValue)
                {
                    maxValue = nums[i];
                }
            }  
        }
        
        return(ok == 1 ? maxValue : -1);
    }
};