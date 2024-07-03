public class Solution {
    public int MinDifference(int[] nums) {
        int n = nums.Length;
        if (n <= 4) return 0; // If there are 4 or fewer elements, we can make all elements the same with at most 3 moves.

        Array.Sort(nums);

        // We need to consider four possible scenarios:
        // 1. Change the three largest elements to the fourth largest element.
        // 2. Change the two largest elements and the smallest element to the third largest element.
        // 3. Change the largest element and the two smallest elements to the second largest element.
        // 4. Change the three smallest elements to the second smallest element.

        int scenario1 = nums[n-4] - nums[0];
        int scenario2 = nums[n-3] - nums[1];
        int scenario3 = nums[n-2] - nums[2];
        int scenario4 = nums[n-1] - nums[3];

        return Math.Min(Math.Min(scenario1, scenario2), Math.Min(scenario3, scenario4));
    }
}