class Solution(object):
    def appendCharacters(self, s, t):
        i, j = 0, 0
        len_s, len_t = len(s), len(t)

        # Find the longest prefix of t that is a subsequence of s
        while i < len_s and j < len_t:
            if s[i] == t[j]:
                j += 1
            i += 1

        # The number of characters that need to be appended
        return len_t - j
        