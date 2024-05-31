class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int xor2no = 0;
        for (int num : nums) {
            xor2no ^= num;
        }

        unsigned int lowestBit = xor2no & -(unsigned int)xor2no;

        vector<int> result(2, 0);
        for (int num : nums) {
            if ((lowestBit & num) == 0) {
                result[0] ^= num;
            } else {
                result[1] ^= num;
            }
        }

        return result;
        // vector<int>ans;
        // unordered_map<int,int>ump;
        // for(int i=0; i<nums.size(); i++)
        // {
        //     ump[nums[i]]++;
        // }
        // for(auto it: ump)
        // {
        //     if(it.second == 1)
        //     {
        //         ans.push_back(it.first);
        //     }
        // }
        // return ans;
    }
};