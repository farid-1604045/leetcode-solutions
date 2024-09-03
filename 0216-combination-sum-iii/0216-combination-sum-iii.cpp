class Solution {
    vector<vector<int>>result;
public:
    void try_combination(vector<int>& temp, int k, int n, int start)
    {
        if(temp.size() == k)
        {
            if(n == 0)
            {
                result.push_back(temp);
                return;
            }
        }
        
        for(int i=start; i<=9; i++)
        {
            temp.push_back(i);
            try_combination(temp, k, n-i, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        try_combination(temp, k, n, 1);
        return result;
    }
};