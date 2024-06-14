class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>ump;
        ump[0] = 1;
        int n = nums.size();
        int countNumber = 0;
        int cumulativeSum = 0;
        for(int i=0; i<n; i++)
        {
            cumulativeSum+=nums[i];
            if(ump.find(cumulativeSum-goal)!=ump.end())
            {
                countNumber += ump[cumulativeSum-goal];
            }
            ump[cumulativeSum]++;
        }
        return countNumber;
    }
};