class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>weights(heights);
        sort(weights.begin(), weights.end());
        int n = heights.size();
        int count = 0;
        for(int i=0; i<n; i++)
        {
            if(heights[i]!=weights[i])
            {
                count++;
            }
        }
        return count;
    }
};