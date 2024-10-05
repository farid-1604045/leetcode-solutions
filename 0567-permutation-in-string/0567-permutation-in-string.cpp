class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
    
        if (len1 > len2) return false;

        vector<int> s1_count(26, 0), window_count(26, 0);

        for (char c : s1) {
            s1_count[c - 'a']++;
        }

        for (int i = 0; i < len1; i++) {
            window_count[s2[i] - 'a']++;
        }

        if (s1_count == window_count) return true;

        for (int i = len1; i < len2; i++) {
            window_count[s2[i] - 'a']++;
            window_count[s2[i - len1] - 'a']--;

            if (s1_count == window_count) return true;
        }

        return false;
    }
};