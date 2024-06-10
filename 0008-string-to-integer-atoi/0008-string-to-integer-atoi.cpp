class Solution {
public:
    int myAtoi(string s) {
        return myAtoiRecursive(s, 0, 1, 0, false);
    }
private:
    int myAtoiRecursive(string& s, int index, int sign, long long result, bool signDetermined)
    {
        if(index >= s.size())
        {
            return result*sign;
        }
        
        
        char currentChar = s[index];
        
        if(!signDetermined && currentChar == ' ')
        {
            return myAtoiRecursive(s, index+1, sign, result, signDetermined);
        }
        
        if(!signDetermined && (currentChar == '-' || currentChar == '+'))
        {
            sign = (currentChar == '-') ? -1 : 1;
            return myAtoiRecursive(s, index+1, sign, result, true);
        }
        
        if(isdigit(currentChar))
        {
            result = result*10 + (currentChar - '0');
            if(sign * result > INT_MAX)
            {
                return INT_MAX;
            }
            
            if(sign * result < INT_MIN)
            {
                return INT_MIN;
            }

            return myAtoiRecursive(s, index+1, sign, result, true);
        }
        
        return sign*result;
    }
};