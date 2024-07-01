public class Solution {
    public IList<int> FindWordsContaining(string[] words, char x) {
        List<int> index = new List<int>();
        int n = words.Length;
        for (int i = 0; i < n; i++)
        {
            if (words[i].IndexOf(x) != -1)
            {
                index.Add(i);
            }
        }
        
        return index;
    }
}