public class Solution {
    public int CountPairs(IList<int> nums, int target) {
        int n = nums.Count;
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int sum = nums[i]+nums[j];
                if(sum < target)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
}