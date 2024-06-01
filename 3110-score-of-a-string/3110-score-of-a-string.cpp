class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for(int i=0; i<s.size()-1; i++)
        {
            if(s[i]!=s[i+1])
            {
                int m = s[i];
                int n = s[i+1];
                sum += abs(m-n);
            }
        }
        return sum;
    }
};