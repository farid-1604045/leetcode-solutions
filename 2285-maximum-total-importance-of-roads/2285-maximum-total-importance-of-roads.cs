public class Solution {
    public long MaximumImportance(int n, int[][] roads) {
        // Array to store the degree of each city
        int[] degree = new int[n];
        
        // Count the degree of each city
        foreach (var road in roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        
        // List of city indices
        List<int> cities = Enumerable.Range(0, n).ToList();
        
        // Sort the cities based on their degree in descending order
        cities.Sort((a, b) => degree[b].CompareTo(degree[a]));
        
        // Array to store the values assigned to each city
        int[] value = new int[n];
        for (int i = 0; i < n; i++) {
            value[cities[i]] = n - i;
        }
        
        // Calculate the maximum total importance of all roads
        long totalImportance = 0;
        foreach (var road in roads) {
            totalImportance += value[road[0]] + value[road[1]];
        }
        
        return totalImportance;
    }
}