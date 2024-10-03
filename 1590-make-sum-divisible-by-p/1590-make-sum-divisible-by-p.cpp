class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total_sum = 0;
        for(auto num : nums)
        {
            total_sum += num;
        }
        
        int remainder = total_sum % p;
        
        if(remainder == 0)
        {
            return 0;
        }
        
        unordered_map<long long, int>mod_map;
        mod_map[0] = -1;
        long long prefix_sum = 0;
        int min_length = nums.size();
        
        for(int i=0; i<nums.size(); i++)
        {
            prefix_sum = (prefix_sum + nums[i])%p;
            int target = (prefix_sum - remainder + p)%p;
            if(mod_map.find(target) != mod_map.end())
            {
                min_length = min(min_length, i-mod_map[target]);
            }
            
            mod_map[prefix_sum] = i;
        }
        
        return (min_length == nums.size()) ? -1 : min_length;
    }
};