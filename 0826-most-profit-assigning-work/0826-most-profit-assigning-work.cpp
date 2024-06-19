class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int,int>>jobs(n);
        for(int i=0; i<n; i++)
        {
            jobs[i] = {difficulty[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        
        int maxProfit = 0, maxJobProfit = 0, jobIndex = 0;
        for(auto ability : worker)
        {
            while(jobIndex<n && ability>=jobs[jobIndex].first)
            {
                maxJobProfit = max(maxJobProfit, jobs[jobIndex].second);
                jobIndex++;
            }
            maxProfit+=maxJobProfit;
        }
        return maxProfit;
    }
};