class Solution {
public:
    int minimumMoves(string s) {
        int n = s.length();
        int cnt = 0;
        for(int i=0; i<n; )
        {
            int m = i;
            
            if(s[m] == 'X')
            {
                cnt++;
                s[m] = 'O';
                
                if(m+1<n) 
                {
                    s[i+1] = 'O';
                    i+=1;
                }
            
                if(m+2<n)
                {
                    s[m+2] = 'O';
                    i+=2;
                }
                
                else
                {
                    i++;
                }
                
            }
            else
            {
                i++;
            }
        }
        
        return cnt;
    }
};