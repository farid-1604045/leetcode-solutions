class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> char_counts;

        for (char c : s) {
            char_counts[c]++;
        }

        int palindrome_length = 0;
        bool odd_found = false;

        for (auto& pair : char_counts) {
            int count = pair.second;
            if (count % 2 == 0) {
                palindrome_length += count;
            } else {
                palindrome_length += count - 1;
                odd_found = true;
            }
        }
        if (odd_found) {
            palindrome_length += 1;
        }

        return palindrome_length;
    }
};