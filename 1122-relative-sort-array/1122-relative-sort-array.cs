public class Solution {
    public int[] RelativeSortArray(int[] arr1, int[] arr2) {
       Dictionary<int, int> mp = new Dictionary<int, int>();
        foreach (int num in arr1) {
            if (mp.ContainsKey(num)) {
                mp[num]++;
            } else {
                mp[num] = 1;
            }
        }

        // Create the result list based on the order in arr2
        List<int> result = new List<int>();
        foreach (int num in arr2) {
            if (mp.ContainsKey(num)) {
                for (int j = 0; j < mp[num]; j++) {
                    result.Add(num);
                }
                mp.Remove(num); // Remove to avoid adding duplicates later
            }
        }

        // Sort the remaining elements in arr1
        List<int> remainingElements = new List<int>();
        foreach (int num in arr1) {
            if (mp.ContainsKey(num)) {
                remainingElements.Add(num);
            }
        }
        remainingElements.Sort();

        // Add the remaining elements to the result list
        result.AddRange(remainingElements);

        // Convert the result list to an array and return it
        return result.ToArray();
    }
}