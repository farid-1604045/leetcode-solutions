class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftsum ;
        vector<int> rightsum ; 
        int left = 0 ;  int right = 0 ;
        leftsum.push_back(left);
        for(int i=0; i<nums.size()-1; i++)
        {
            left = left + nums[i];
            leftsum.push_back(left);
        }
        
        for(int i=1 ; i<nums.size(); i++){
            right = right+nums[i];
        } 
        
        rightsum.push_back(right);
        
        for(int i=1 ; i<nums.size() ;i++){
            right = right - nums[i];
            rightsum.push_back(right);
        }
        
        vector<int> ans ;
        
        for(int i=0 ; i<nums.size() ;i++)
        {
            ans.push_back(abs(leftsum[i]-rightsum[i]));
        }
        return ans ; 
    }
};