public class Solution {
    public int FindKthPositive(int[] arr, int k) {
        Dictionary<int, int> ump = new Dictionary<int, int>();
        int n = arr.Length;

        for (int i = 0; i < n; i++)
        {
            if (ump.ContainsKey(arr[i]))
            {
                ump[arr[i]]++;
            }
            else
            {
                ump[arr[i]] = 1;
            }
        }

        int limit = arr[n - 1] + k;
        List<int> v = new List<int>();

        for (int i = 1; i <= limit; i++)
        {
            if (!ump.ContainsKey(i))
            {
                v.Add(i);
            }
        }

        return v[k - 1];
    }
}