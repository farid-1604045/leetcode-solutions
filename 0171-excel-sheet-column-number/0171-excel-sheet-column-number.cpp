class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.length();
        int powN = n-1;
        long long sum = 0;
        for(int i=0; i<n; i++)
        {
            int charVal = columnTitle[i] - 64;
            sum += pow(26, powN) * charVal;
            powN--;
        }
        
        return sum;
    }
};