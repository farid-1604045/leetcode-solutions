class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max = 0;
        int ans = 0;
        bool flag = false;
        vector<int>result;
        int size = mat.size();
        int c_size = mat[0].size();
        for(int i=0; i<size; i++)
        {
            int cnt = 0;
            for(int j=0; j<c_size; j++)
            {
                if(mat[i][j] == 1)
                {
                    cnt++;
                }
            }
            
            if(cnt>max)
            {
                flag = true;
                max = cnt;
                ans = i;
            }
        }
        result.push_back(ans);
        result.push_back(max);
        return result;
    }
};