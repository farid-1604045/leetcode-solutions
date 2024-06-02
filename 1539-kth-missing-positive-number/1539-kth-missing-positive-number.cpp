class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]<=k)
            {
                k++;
            }
            else
            {
                break;
            }
        }
        return k;
//         unordered_map<int,int>ump;
//         int n = arr.size();
//         for(int i=0; i<n; i++)
//         {
//             ump[arr[i]]++;
//         }
        
//         int limit = arr[n-1]+k;
//         vector<int>v;
//         for(int i=1; i<=limit; i++)
//         {
//             if(ump.find(i)==ump.end())
//             {
//                 v.push_back(i);
//             }
//         }
        
//         return v[k-1];
    }
};