public class Solution {
    public int MinPatches(int[] nums, int n) {
        long maxReach = 0;
        int patches = 0, i = 0;

        while (maxReach < n) {
            if (i < nums.Length && nums[i] <= maxReach + 1) {
                maxReach += nums[i];
                i++;
            } else {
                maxReach += maxReach + 1;
                patches++;
            }
        }

        return patches;
    }
}