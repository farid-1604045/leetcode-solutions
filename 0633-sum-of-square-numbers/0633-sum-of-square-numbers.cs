public class Solution {
    public bool JudgeSquareSum(int n) {
        int end = (int)Math.Sqrt(n);
        int start = 0;
        while (start <= end) {
            long a = (long)start * start;
            long b = (long)end * end;
            if (a + b == n) {
                return true;
            }
            if (a + b < n) {
                start++;
            } else {
                end--;
            }
        }
        return false;
    }
}