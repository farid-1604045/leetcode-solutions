public class Solution {
    public int LengthOfLastWord(string s) {
        int n = s.Length;
        int length = 0;
        for(int i=n-1; i>=0; i--)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
            {
                length++;
                if(i>0 && s[i-1]==' ')
                {
                    break;
                }
            }
        }
        return length;
    }
}