public class Solution {
    public int NumberOfEmployeesWhoMetTarget(int[] hours, int target) {
        int targetHours = 0;
        int n = hours.Length;
        for(int i=0; i<n; i++)
        {
            if(hours[i]>=target)
            {
                targetHours++;
            }
        }
        
        return targetHours;
    }
}