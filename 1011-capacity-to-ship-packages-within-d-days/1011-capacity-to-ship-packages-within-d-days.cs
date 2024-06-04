public class Solution {
    public int FindDays(int[] weights, int cap)
    {
        int days = 1; // First day.
        int load = 0;
        int n = weights.Length; // size of array.
        for (int i = 0; i < n; i++)
        {
            if (load + weights[i] > cap)
            {
                days += 1; // move to next day
                load = weights[i]; // load the weight.
            }
            else
            {
                load += weights[i];
            }
        }
        return days;
    }

    public int LeastWeightCapacity(int[] weights, int d)
    {
        int low = weights.Max();
        int high = weights.Sum();
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int numberOfDays = FindDays(weights, mid);
            if (numberOfDays <= d)
            {
                // eliminate right half
                high = mid - 1;
            }
            else
            {
                // eliminate left half
                low = mid + 1;
            }
        }
        return low;
    }
    public int ShipWithinDays(int[] weights, int days) {
        return LeastWeightCapacity(weights, days);
    }
}