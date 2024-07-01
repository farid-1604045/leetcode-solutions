class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n=encoded.size();
        int m=n+1;
        vector<int> ans(m,first);
        // ans[0]=first;

        for(int i=0;i<n;i++){
            ans[i+1]=encoded[i]^ans[i];
        }
        return ans;
    }
};