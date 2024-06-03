public class Solution {
    private int FindMax(int[] piles) {
        int maxi = 0;
        foreach (int num in piles) {
            maxi = Math.Max(maxi, num);
        }
        return maxi;
    }

    private long CalculateTotalHours(int[] piles, int hourly) {
        long totalH = 0;
        foreach (int num in piles) {
            totalH += (num + hourly - 1) / hourly;
        }
        return totalH;
    }
    public int SmallestDivisor(int[] nums, int threshold) {
        int low = 1;
        int high = FindMax(nums);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long totalH = CalculateTotalHours(nums, mid);
            if (totalH <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}