class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2;
        int ind2 = n / 2;
        int ind1 = ind2 - 1;
        int cnt = 0;
        int ind1el = -1, ind2el = -1;

        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                if (cnt == ind1) ind1el = nums1[i];
                if (cnt == ind2) ind2el = nums1[i];
                cnt++;
                i++;
            }
            else {
                if (cnt == ind1) ind1el = nums2[j];
                if (cnt == ind2) ind2el = nums2[j];
                cnt++;
                j++;
            }
        }

        while (i < n1) {
            if (cnt == ind1) ind1el = nums1[i];
            if (cnt == ind2) ind2el = nums1[i];
            cnt++;
            i++;
        }
        while (j < n2) {
            if (cnt == ind1) ind1el = nums2[j];
            if (cnt == ind2) ind2el = nums2[j];
            cnt++;
            j++;
        }

        if (n % 2 == 1) {
            return (double)ind2el;
        }

        return (double)((double)(ind1el + ind2el)) / 2.0;
//         vector<int>nums;
//         for(int i=0; i<nums1.size(); i++)
//         {
//             nums.push_back(nums1[i]);
//         }
        
//         for(int i=0; i<nums2.size(); i++)
//         {
//             nums.push_back(nums2[i]);
//         }
        
//         sort(nums.begin(), nums.end());
        
//         int n = nums.size();
//         double median;
//         if(n%2 == 0)
//         {
//             int m = n/2;
//             int n = m-1;
//             median = (nums[m]+nums[n])/2.0;
//         }
//         else
//         {
//             int m = n/2;
//             median = nums[m];
//         }
        
//         return median;
    }
};