public class Solution {
    public IList<IList<int>> GetAncestors(int n, int[][] edges) {
        List<int>[] graph = new List<int>[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new List<int>();
        }
        int[] inDeg = new int[n];
        foreach (var edge in edges) {
            graph[edge[0]].Add(edge[1]);
            inDeg[edge[1]]++;
        }

        // Initialize the queue with nodes having zero in-degree
        Queue<int> queue = new Queue<int>();
        for (int i = 0; i < n; i++) {
            if (inDeg[i] == 0) {
                queue.Enqueue(i);
            }
        }

        // To store the ancestors of each node
        HashSet<int>[] ancestors = new HashSet<int>[n];
        for (int i = 0; i < n; i++) {
            ancestors[i] = new HashSet<int>();
        }

        // BFS to find all ancestors for each node
        while (queue.Count > 0) {
            int u = queue.Dequeue();
            foreach (var v in graph[u]) {
                inDeg[v]--;
                ancestors[v].Add(u);
                foreach (var ancestor in ancestors[u]) {
                    ancestors[v].Add(ancestor);
                }
                if (inDeg[v] == 0) {
                    queue.Enqueue(v);
                }
            }
        }

        // Convert the sets to sorted lists
        IList<IList<int>> result = new List<IList<int>>();
        for (int i = 0; i < n; i++) {
            List<int> sortedAncestors = ancestors[i].ToList();
            sortedAncestors.Sort();
            result.Add(sortedAncestors);
        }

        return result;
    }
}