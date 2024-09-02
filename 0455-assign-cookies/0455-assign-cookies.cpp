class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = s.size();
        int m = g.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int j = 0;
        for(int i=0; i<n; i++)
        {
            if(j<m && s[i]>=g[j])
            {
                count++;
                j++;
            }
        }
        return count;
    }
};