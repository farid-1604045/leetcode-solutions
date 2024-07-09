class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long neededTime = 0;
        long long lastNumber = 0;
        int n = customers.size();
        bool firstTime = true;
        for(int i=0; i<customers.size(); i++)
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
};