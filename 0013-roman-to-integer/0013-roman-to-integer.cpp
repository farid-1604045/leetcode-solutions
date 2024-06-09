class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int prevValue = 0;
        for(char i : s)
        {
            int value = romanValues[i];
            if(value > prevValue)
            {
                sum-=(2*prevValue);
            }
            sum+=value;
            prevValue=value;
        }
        return sum;
    }
};