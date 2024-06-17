public class Solution {
        public bool IsSquare(int n) {
        double sqrtN = Math.Sqrt(n);
        return sqrtN == (int)sqrtN;
    }

    public bool JudgeSquareSum(int n) {
        if (n == 0) return true;
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return false;
        int sqrtN = (int)Math.Sqrt(n);
        if (IsSquare(n)) return true;
        for (int i = 1; i <= sqrtN; i++) {
            int y = n - i * i;
            if (IsSquare(y)) return true;
        }
        return false;
    }
}