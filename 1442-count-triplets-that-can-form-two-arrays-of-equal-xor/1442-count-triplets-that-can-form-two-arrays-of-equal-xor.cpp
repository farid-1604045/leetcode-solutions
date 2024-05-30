class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixXOR(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
        }

        int count = 0;
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (prefixXOR[j] == prefixXOR[k + 1]) {
                    count += (k - j);
                }
            }
        }

        return count;
    }
};