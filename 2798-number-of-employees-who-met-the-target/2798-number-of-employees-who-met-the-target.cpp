class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int targetHours = 0;
        int n = hours.size();
        for(int i=0; i<n; i++)
        {
            if(hours[i]>=target)
            {
                targetHours++;
            }
        }
        
        return targetHours;
    }
};