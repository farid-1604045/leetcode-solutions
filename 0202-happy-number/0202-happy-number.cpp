class Solution {
public:
    bool isHappy(int n) {
        bool ok = true;
        long long num = n;
        unordered_set<long long> ust;
        
        while(num != 1)
        {
            auto it = ust.find(num);
            if (it != ust.end()) 
            {
                ok = false;
                break;
            }
            ust.insert(num);

            string newNum = to_string(num);
            long long sum = 0;
            for(int i=0; i<newNum.size(); i++)
            {
                int numchar = newNum[i] - '0';
                sum += (numchar * numchar);
            }
            num = sum;
        }
        
        return ok;
    }
};