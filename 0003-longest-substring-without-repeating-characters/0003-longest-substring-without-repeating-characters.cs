public class Solution {
    public int LengthOfLongestSubstring(string s) {
        Dictionary<char, int> charIndexMap = new Dictionary<char, int>();
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.Length; ++right)
        {
            if (charIndexMap.ContainsKey(s[right]))
            {
                left = Math.Max(charIndexMap[s[right]] + 1, left);
            }
            charIndexMap[s[right]] = right;
            maxLength = Math.Max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
}