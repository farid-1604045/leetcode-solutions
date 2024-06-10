
const int mod = 1000000007;

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long odd = n / 2;
        long long even = (n - odd);
        long long oddPow = power(4, odd);
        long long evenPow = power(5, even);
        long long ans = (oddPow * evenPow) % mod;
        return ans;
    }
private:
    long long power(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
};