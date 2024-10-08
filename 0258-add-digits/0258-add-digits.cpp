class Solution {
public:
    int addDigits(int num) {
        string str = to_string(num);
        while(str.length() != 1)
        {
            int n = str.length();
            int sum = 0;
            for(int i=0; i<n; i++)
            {
                int x = str[i] - '0';
                sum += x;
            }
            str = to_string(sum);
        }
        
        return stoi(str);
    }
};