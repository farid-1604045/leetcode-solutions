public class Solution {
    public double AverageWaitingTime(int[][] customers) {
        long neededTime = 0;
        long lastNumber = 0;
        int n = customers.Length;
        bool firstTime = true;
        for(int i=0; i<n; i++)
        {
            int arrivalTime = customers[i][0];
            int takenTime = customers[i][1];
            if(firstTime)
            {
                lastNumber = arrivalTime + takenTime;
                neededTime = lastNumber - arrivalTime;
                firstTime = false;
            }
            
            else
            {
                if(arrivalTime<=lastNumber)
                {
                    lastNumber+=takenTime;
                    neededTime+=(lastNumber-arrivalTime);
                }
                else
                {
                    lastNumber = arrivalTime + takenTime;
                    neededTime+=(lastNumber-arrivalTime);
                }
            }
        }
        
        double avgWaitingTime = (double)neededTime/n;
        return avgWaitingTime;
    }
}