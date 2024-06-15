public class Solution {
    public int FindMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = profits.Length;
        
        List<(int capital, int profit)> projects = new List<(int, int)>();
        for (int i = 0; i < n; ++i) {
            projects.Add((capital[i], profits[i]));
        }
        
        projects.Sort((a, b) => a.capital.CompareTo(b.capital));
        
        PriorityQueue<int, int> maxProfitHeap = new PriorityQueue<int, int>(Comparer<int>.Create((a, b) =>              b.CompareTo(a)));
        
        int index = 0;
        for (int i = 0; i < k; ++i) {
            while (index < n && projects[index].capital <= w) {
                maxProfitHeap.Enqueue(projects[index].profit, projects[index].profit);
                ++index;
            }

            if (maxProfitHeap.Count == 0) {
                break;
            }

            w += maxProfitHeap.Dequeue();
        }
        
        return w;
    }
}