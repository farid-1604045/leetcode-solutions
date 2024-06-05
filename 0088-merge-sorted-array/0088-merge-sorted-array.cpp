class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> left_half(m);
        vector<int> right_half(n);

        for (int i = 0; i < m; ++i)
            left_half[i] = nums1[i];
        for (int j = 0; j < n; ++j)
            right_half[j] = nums2[j];
        
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < m && j < n) {
            if (left_half[i] <= right_half[j]) {
                nums1[k] = left_half[i];
                ++i;
            } else {
                nums1[k] = right_half[j];
                ++j;
            }
            ++k;
        }

        while (i < m) {
            nums1[k] = left_half[i];
            ++i;
            ++k;
        }

        while (j < n) {
            nums1[k] = right_half[j];
            ++j;
            ++k;
        }
    }
};