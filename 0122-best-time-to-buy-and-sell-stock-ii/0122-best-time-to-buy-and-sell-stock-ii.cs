public class Solution {
    public int MaxProfit(int[] prices) {
        int maxi = 0, profit = 0;
        int n = prices.Length;
        int buy = prices[0];
        for(int i=1; i<n; i++)
        {
            if(prices[i]<buy)
            {
                buy = prices[i];
            }
            else
            {
                profit = prices[i]-buy;
                buy = prices[i];
                maxi+=profit;
            }
        }
        return maxi;
    }
}