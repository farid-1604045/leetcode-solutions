class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }
        
        sort(projects.begin(), projects.end());
        
        priority_queue<int> maxProfitHeap;
        
        int index = 0;
        for (int i = 0; i < k; ++i) {
            while (index < n && projects[index].first <= w) {
                maxProfitHeap.push(projects[index].second);
                ++index;
            }
            
            if (maxProfitHeap.empty()) {
                break;
            }

            w += maxProfitHeap.top();
            maxProfitHeap.pop();
        }
        
        return w;
    }
};