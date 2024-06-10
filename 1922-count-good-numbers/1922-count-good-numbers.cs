public class Solution {
    private const int mod = 1000000007;
    public int CountGoodNumbers(long n) {
        long odd = n / 2;
        long even = n - odd;
        long oddPow = Power(4, odd);
        long evenPow = Power(5, even);
        long ans = (oddPow * evenPow) % mod;
        return (int)ans;
    }
    private long Power(long baseVal, long exp) {
        long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * baseVal) % mod;
            }
            baseVal = (baseVal * baseVal) % mod;
            exp /= 2;
        }
        return result;
    }
}