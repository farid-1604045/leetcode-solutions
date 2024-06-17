class Solution {
public:
    bool is_square(int n){
        double sqrt_n=sqrt(n);
        return sqrt_n==int(sqrt_n);
    }
    bool judgeSquareSum(int n) {
        if (n==0) return 1;
        while (n%4==0) n/=4;
        if (n%8==7) return 0;
        int sqrt_n=int(sqrt(n));
        if (is_square(n)) return 1;
        for(int i=1; i<=sqrt_n; i++)
        {
            int y=n-i*i;
            if (is_square(y)) return 1;
        }
        return 0;
    }
};