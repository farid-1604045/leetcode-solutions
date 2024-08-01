class Solution {
public:
    int countSeniors(vector<string>& details) {
        int age = 0;
        int mul1 = 10;
        int mul2 = 1;
        int cnt = 0;
        int size = details.size();
        for(int i=0; i<size; i++)
        {
            age = 0;
            int ageOfPersonFirst = details[i][11] - '0';
            int ageOfPersonSecond = details[i][12] - '0';
            age += (ageOfPersonFirst*mul1);
            age += (ageOfPersonSecond*mul2);
            if(age>60)
            {
                cnt++;
            }
        }
        
        return cnt;
    }
};