public class Solution {
    public int MinOperations(string[] logs) {
        string parentFolder = "../";
        string sameFolder = "./";
        
        int n = logs.Length;
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(logs[i]==parentFolder)
            {
                if(cnt > 0)
                    cnt--;
            }
            else if(logs[i]==sameFolder)
            {
                
            }
            else
            {
                cnt++;
            }
        }
        
        return cnt < 0 ? 0 : cnt;
    }
}