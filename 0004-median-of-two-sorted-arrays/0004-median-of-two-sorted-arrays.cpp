class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums;
        for(int i=0; i<nums1.size(); i++)
        {
            nums.push_back(nums1[i]);
        }
        
        for(int i=0; i<nums2.size(); i++)
        {
            nums.push_back(nums2[i]);
        }
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        double median;
        if(n%2 == 0)
        {
            int m = n/2;
            int n = m-1;
            median = (nums[m]+nums[n])/2.0;
        }
        else
        {
            int m = n/2;
            median = nums[m];
        }
        
        return median;
    }
};