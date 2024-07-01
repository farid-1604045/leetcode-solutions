public class Solution {
    public int[] Decode(int[] encoded, int first) {
        int n = encoded.Length;
        int m = n + 1;
        int[] ans = new int[m];
        ans[0] = first;

        for (int i = 0; i < n; i++)
        {
            ans[i + 1] = encoded[i] ^ ans[i];
        }
        return ans;
    }
}