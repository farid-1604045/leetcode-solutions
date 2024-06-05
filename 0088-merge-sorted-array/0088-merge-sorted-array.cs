public class Solution {
    public void Merge(int[] nums1, int m, int[] nums2, int n) {
        List<int> leftHalf = new List<int>(m);
        List<int> rightHalf = new List<int>(n);

        for (int i = 0; i < m; ++i)
            leftHalf.Add(nums1[i]);
        for (int j = 0; j < n; ++j)
            rightHalf.Add(nums2[j]);

        int leftIndex = 0;
        int rightIndex = 0;
        int k = 0;

        while (leftIndex < m && rightIndex < n)
        {
            if (leftHalf[leftIndex] <= rightHalf[rightIndex])
            {
                nums1[k] = leftHalf[leftIndex];
                ++leftIndex;
            }
            else
            {
                nums1[k] = rightHalf[rightIndex];
                ++rightIndex;
            }
            ++k;
        }

        while (leftIndex < m)
        {
            nums1[k] = leftHalf[leftIndex];
            ++leftIndex;
            ++k;
        }

        while (rightIndex < n)
        {
            nums1[k] = rightHalf[rightIndex];
            ++rightIndex;
            ++k;
        }
    }
}