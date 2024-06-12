public class Solution {
    public void SortColors(int[] nums) {
        int n = nums.Length;
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                Swap(nums, low, mid);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                Swap(nums, mid, high);
                high--;
            }
        }
    }
    static void Swap(int[] nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}