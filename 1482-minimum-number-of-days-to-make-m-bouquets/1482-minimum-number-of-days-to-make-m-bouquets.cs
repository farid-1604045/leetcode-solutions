public class Solution {
    private bool Possible(int[] arr, int day, int m, int k) {
        int n = arr.Length;
        int cnt = 0;
        int noOfBouquets = 0;

        // Count the number of bouquets
        for (int i = 0; i < n; i++) {
            if (arr[i] <= day) {
                cnt++;
            } else {
                noOfBouquets += (cnt / k);
                cnt = 0;
            }
        }
        noOfBouquets += (cnt / k);
        return noOfBouquets >= m;
    }

    private int RoseGarden(int[] arr, int k, int m) {
        long val = (long)m * k;
        int n = arr.Length;
        if (val > n) return -1;

        // Find maximum and minimum
        int mini = int.MaxValue, maxi = int.MinValue;
        for (int i = 0; i < n; i++) {
            mini = Math.Min(mini, arr[i]);
            maxi = Math.Max(maxi, arr[i]);
        }

        // Apply binary search
        int low = mini, high = maxi;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (Possible(arr, mid, m, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    public int MinDays(int[] bloomDay, int m, int k) {
        return RoseGarden(bloomDay, k, m);
    }
}