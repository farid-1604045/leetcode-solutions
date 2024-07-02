class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>ump;
        for(int i=0; i<nums1.size(); i++)
        {
            ump[nums1[i]]++;
        }
        
        vector<int>result;
        for(auto it:nums2)
        {
            if(ump[it]>0)
            {
                result.push_back(it);
                ump[it]--;
            }
        }
        return result;
    }
};