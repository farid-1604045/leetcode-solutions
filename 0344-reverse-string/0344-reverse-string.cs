public class Solution {
    public void ReverseString(char[] s) {
        int n = s.Length;
        int m = n / 2;

        for (int i = 0; i < m; i++)
        {
            Swap(ref s[i], ref s[n - i - 1]);
        }
    }
    static void Swap(ref char a, ref char b)
    {
        char temp = a;
        a = b;
        b = temp;
    }
}