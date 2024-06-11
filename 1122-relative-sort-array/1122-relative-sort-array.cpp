class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int>mp;
        for(int i=0; i<arr1.size(); i++)
        {
            mp[arr1[i]]++;
        }
        
        vector<int>result;
        for(int i=0; i<arr2.size(); i++)
        {
            int size = mp[arr2[i]];
            for(int j=0; j<size; j++)
            {
                result.push_back(arr2[i]);
            }
        }
        
        sort(arr1.begin(), arr1.end());
        map<int,int>mp2;
        for(int i=0; i<arr2.size(); i++)
        {
            mp2[arr2[i]]++;
        }
        
        for(int i=0; i<arr1.size(); i++)
        {
            if(mp2.find(arr1[i]) == mp2.end())
            {
                result.push_back(arr1[i]);
            }
        }
        
        return result;
    }
};