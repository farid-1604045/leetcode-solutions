class Solution {
public:
    bool canWePlace(vector<int> &stalls, int dist, int cows) {
        int n = stalls.size(); //size of array
        int cntCows = 1; //no. of cows placed
        int last = stalls[0]; //position of last placed cow.
        for (int i = 1; i < n; i++) {
            if (stalls[i] - last >= dist) {
                cntCows++; //place next cow.
                last = stalls[i]; //update the last location.
            }
            if (cntCows >= cows) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size(); //size of array
        //sort the stalls[]:
        sort(position.begin(), position.end());

        int low = 1, high = position[n - 1] - position[0];
        //apply binary search:
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canWePlace(position, mid, m) == true) {
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return high;
    }
};