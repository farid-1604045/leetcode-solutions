public class Solution {
        private int FindMax(int[] piles) {
        int maxi = 0;
        foreach (int num in piles) {
            maxi = Math.Max(maxi, num);
        }
        return maxi;
    }

    // Helper method to calculate the total hours required at a given eating speed
    private long CalculateTotalHours(int[] piles, int hourly) {
        long totalH = 0;
        foreach (int num in piles) {
            totalH += (num + hourly - 1) / hourly; // Efficient ceiling of integer division
        }
        return totalH;
    }

    public int MinEatingSpeed(int[] piles, int h) {
        int low = 1, high = FindMax(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long totalH = CalculateTotalHours(piles, mid);
            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}