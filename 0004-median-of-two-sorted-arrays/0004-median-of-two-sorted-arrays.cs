public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        List<int> nums = new List<int>();
        
        // Add elements from nums1 to the list
        foreach (int num in nums1)
        {
            nums.Add(num);
        }
        
        // Add elements from nums2 to the list
        foreach (int num in nums2)
        {
            nums.Add(num);
        }
        
        // Sort the combined list
        nums.Sort();
        
        int n = nums.Count;
        double median;
        
        // If the number of elements is even, take the average of the middle two
        if (n % 2 == 0)
        {
            int mid1 = n / 2;
            int mid2 = mid1 - 1;
            median = (nums[mid1] + nums[mid2]) / 2.0;
        }
        else
        {
            // If the number of elements is odd, take the middle element
            int mid = n / 2;
            median = nums[mid];
        }
        
        return median;
    }
}