public class Solution {
    public int FindTheWinner(int n, int k) {
        List<int> friends = new List<int>();
        
        for (int i = 1; i <= n; i++)
        {
            friends.Add(i);
        }
        
        int currentPosition = 0;
        
        while (friends.Count > 1)
        {
            currentPosition = (currentPosition + k - 1) % friends.Count;
            friends.RemoveAt(currentPosition);
        }
        
        return friends[0];
    }
}