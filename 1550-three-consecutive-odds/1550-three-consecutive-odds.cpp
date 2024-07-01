class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool ans = false;
        int cnt = 0;
        int n = arr.size();
        for(int i=0; i<n; i++)
        {
            if(arr[i]%2 != 0)
            {
                cnt++;
                if(cnt == 3)
                {
                    ans = true;
                    break;
                }
            }
            else
            {
                cnt = 0;
            }
        }
        
        return ans;
    }
};