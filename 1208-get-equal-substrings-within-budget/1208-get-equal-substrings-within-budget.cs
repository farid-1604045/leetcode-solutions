public class Solution {
    public int EqualSubstring(string s, string t, int maxCost) {
        int start = 0;
        int maxLength = 0;
        int currentCost = 0;

        for (int end = 0; end < s.Length; ++end) {
            currentCost += Math.Abs(s[end] - t[end]);

            while (currentCost > maxCost) {
                currentCost -= Math.Abs(s[start] - t[start]);
                ++start;
            }

            maxLength = Math.Max(maxLength, end - start + 1);
        }

        return maxLength;
    }
}