public class Solution {
    public int NumWaterBottles(int numBottles, int numExchange) {
        int maxBottle = numBottles;
        int remBottle = numBottles;
        while(remBottle>=numExchange)
        {
            int cntBottle = remBottle/numExchange;
            maxBottle += cntBottle;
            int remainder = remBottle%numExchange;
            remBottle = cntBottle + remainder;
        }
        
        return maxBottle;
    }
}