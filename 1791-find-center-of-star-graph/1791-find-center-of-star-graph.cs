public class Solution {
    public int FindCenter(int[][] edges) {
        Dictionary<int, int> nodeCount = new Dictionary<int, int>();
        
        foreach (var edge in edges)
        {
            if (!nodeCount.ContainsKey(edge[0]))
            {
                nodeCount[edge[0]] = 0;
            }
            if (!nodeCount.ContainsKey(edge[1]))
            {
                nodeCount[edge[1]] = 0;
            }

            nodeCount[edge[0]]++;
            nodeCount[edge[1]]++;
        }

        foreach (var kvp in nodeCount)
        {
            if (kvp.Value == edges.Length)
            {
                return kvp.Key;
            }
        }

        return -1; 
    }
}