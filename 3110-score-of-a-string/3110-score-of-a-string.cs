public class Solution {
    public int ScoreOfString(string s) {
        int sum = 0;
        for(int i=0; i<s.Length-1; i++)
        {
            if(s[i]!=s[i+1])
            {
                int m = s[i];
                int n = s[i+1];
                sum += Math.Abs(m-n);
            }
        }
        return sum;
    }
}