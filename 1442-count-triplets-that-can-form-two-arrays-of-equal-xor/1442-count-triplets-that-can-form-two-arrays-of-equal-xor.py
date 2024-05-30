class Solution(object):
    def countTriplets(self, arr):
        prefixXOR = [0] * (len(arr) + 1)
        for i in range(len(arr)):
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i]

        count = 0
        for j in range(len(arr)):
            for k in range(j + 1, len(arr)):
                if prefixXOR[j] == prefixXOR[k + 1]:
                    count += (k - j)

        return count
        