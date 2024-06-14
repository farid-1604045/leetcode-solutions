class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            if (charIndexMap.find(s[right]) != charIndexMap.end()) {
                left = max(charIndexMap[s[right]] + 1, left);
            }
            charIndexMap[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};