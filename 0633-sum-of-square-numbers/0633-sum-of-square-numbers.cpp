class Solution {
public:
    bool judgeSquareSum(int c) {
        int iteration = sqrt(c);
        int start = 0, end = iteration;
        while(start<=end)
        {
            long long a = (long long)start * start;
            long long b = (long long)end * end;
            if(a+b == c)
            {
                return true;
            }
            if(a+b < c)
            {
                start++;
            }
            if(a+b > c)
            {
                end--;
            }
        }
        return false;
    }
};