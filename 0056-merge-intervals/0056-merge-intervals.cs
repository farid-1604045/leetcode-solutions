public class Solution {
    public int[][] Merge(int[][] intervals) {
        
        List<int[]> intervalsList = new List<int[]>(intervals);

        // Sort the intervals based on the start time
        intervalsList.Sort((a, b) => a[0].CompareTo(b[0]));

        List<int[]> ans = new List<int[]>();
        int n = intervalsList.Count;

        for (int i = 0; i < n; i++) {
            int start = intervalsList[i][0];
            int end = intervalsList[i][1];
            if (ans.Count > 0 && end <= ans[ans.Count - 1][1]) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (intervalsList[j][0] <= end) {
                    end = Math.Max(end, intervalsList[j][1]);
                } else {
                    break;
                }
            }
            ans.Add(new int[] { start, end });
        }

        return ans.ToArray();
    }
}