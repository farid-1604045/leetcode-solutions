class Solution {
private:
    int findMax(vector<int>& piles) {
        int maxi = 0;
        for (int num : piles) {
            maxi = max(maxi, num);
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int>& piles, int hourly) {
        long long totalH = 0;
        for (int num : piles) {
            totalH += (num + hourly - 1) / hourly;
        }
        return totalH;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
         int low = 1, high = findMax(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = calculateTotalHours(piles, mid);
            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};