class Solution {
public:
    double myPow(double x, int n) {
        if (n == INT_MIN) {
            x = x * x;
            n = n / 2;
        }

        // Handle negative exponent
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        
        return myPowRecursive(x, n);
    }
private:
    double myPowRecursive(double x, int n)
    {
        if (n == 0) return 1;
        // if (n == 1) return x;

        // Recursion with divide and conquer
        double half = myPowRecursive(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
};