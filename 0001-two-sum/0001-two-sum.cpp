class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>ump;
        vector<int>v;
        for(int i=0; i<n; i++)
        {
            int complement = target - nums[i];
            if(ump.find(complement)!=ump.end() && ump[complement]!=i)
            {
                auto p = ump.find(complement);
                v.push_back(p->second);
                v.push_back(i);
                break;
            }
            ump[nums[i]] = i;
        }
        return v;
    }
};