public class Solution {
    public int RomanToInt(string s) {
        int sum = 0;
        Dictionary<char, int> romanValues = new Dictionary<char, int>
        {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int prevValue = 0;
        foreach (char c in s)
        {
            int value = romanValues[c];
            if (value > prevValue)
            {
                sum -= 2 * prevValue;
            }
            sum += value;
            prevValue = value;
        }

        return sum;
    }
}