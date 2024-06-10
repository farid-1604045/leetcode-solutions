
const int mod = 1000000007;

class Solution {
public:
//     long long power(long long x, long long n){
//         if(n == 0){
//             return 1;
//         }
//         long long ans = power(x, n/2);
//         ans *= ans;
//         ans %= mod;
//         if(n%2==1){
//             ans *= x;
//             ans %= mod;
//         }
//         return ans;
//     }
// public:
//     int countGoodNumbers(long long n) {
//         long long numberOfOddPlaces = n/2;
//         long long numberOfEvenPlaces = n/2 + n%2;
//         return (power(5, numberOfEvenPlaces) * power(4, numberOfOddPlaces))%mod;
//     }
    int countGoodNumbers(long long n) {
        long long odd = n / 2;
        long long even = n/2 + n%2;
        long long oddPow = power(4, odd);
        long long evenPow = power(5, even);
        int ans = (oddPow * evenPow) % mod;
        return ans;
    }
private:
    long long power(long long x, long long n)
    {
        if (n == 0) 
        {
            return 1;
        }

        // Recursion with divide and conquer
        long long half = power(x, n / 2);
        half = (half*half)%mod;
        if(n%2==1)
        {
            half = (half*x)%mod;
        }
        return half;
    }
// private:
//     long long power(long long base, long long exp) {
//         long long result = 1;
//         while (exp > 0) {
//             if (exp % 2 == 1) {
//                 result = (result * base) % mod;
//             }
//             base = (base * base) % mod;
//             exp /= 2;
//         }
//         return result;
//     }
};