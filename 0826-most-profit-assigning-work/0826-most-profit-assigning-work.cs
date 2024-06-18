public class Solution {
    public int MaxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int n = difficulty.Length;
        List<Tuple<int, int>> jobs = new List<Tuple<int, int>>();
        
        for (int i = 0; i < n; i++) {
            jobs.Add(new Tuple<int, int>(difficulty[i], profit[i]));
        }
        
        jobs.Sort((a, b) => a.Item1.CompareTo(b.Item1));
        Array.Sort(worker);
        
        int maxProfit = 0, jobIndex = 0, maxJobProfit = 0;
        
        foreach (int ability in worker) {
            while (jobIndex < n && ability >= jobs[jobIndex].Item1) {
                maxJobProfit = Math.Max(maxJobProfit, jobs[jobIndex].Item2);
                jobIndex++;
            }
            maxProfit += maxJobProfit;
        }
        
        return maxProfit;
    }
}