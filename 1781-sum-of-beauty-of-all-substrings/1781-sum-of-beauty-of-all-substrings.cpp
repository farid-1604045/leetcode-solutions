class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int totalBeauty = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++;
                totalBeauty += calculateBeauty(freq);
            }
        }

        return totalBeauty;
    }
    
    int calculateBeauty(const vector<int>& freq) {
        int maxFreq = INT_MIN;
        int minFreq = INT_MAX;

        for (int count : freq) {
            if (count > 0) {
                maxFreq = max(maxFreq, count);
                minFreq = min(minFreq, count);
            }
        }

        return maxFreq - minFreq;
    }
};