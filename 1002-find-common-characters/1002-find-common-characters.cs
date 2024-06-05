public class Solution {
    public IList<string> CommonChars(string[] words) {
        if (words.Length == 0) return new List<string>();

        Dictionary<char, int> commonCount = new Dictionary<char, int>();
        foreach (char c in words[0])
        {
            if (commonCount.ContainsKey(c))
            {
                commonCount[c]++;
            }
            else
            {
                commonCount[c] = 1;
            }
        }

        for (int i = 1; i < words.Length; ++i)
        {
            Dictionary<char, int> currentCount = new Dictionary<char, int>();
            foreach (char c in words[i])
            {
                if (currentCount.ContainsKey(c))
                {
                    currentCount[c]++;
                }
                else
                {
                    currentCount[c] = 1;
                }
            }

            List<char> keysToRemove = new List<char>();
            foreach (var pair in commonCount)
            {
                if (currentCount.ContainsKey(pair.Key))
                {
                    commonCount[pair.Key] = Math.Min(pair.Value, currentCount[pair.Key]);
                }
                else
                {
                    keysToRemove.Add(pair.Key);
                }
            }

            foreach (char key in keysToRemove)
            {
                commonCount.Remove(key);
            }
        }

        List<string> result = new List<string>();
        foreach (var pair in commonCount)
        {
            for (int i = 0; i < pair.Value; ++i)
            {
                result.Add(pair.Key.ToString());
            }
        }

        return result;
    }
}