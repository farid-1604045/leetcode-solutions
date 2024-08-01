public class Solution {
    public int CountSeniors(string[] details) {
        int cnt = 0;
        int size = details.Length;

        for (int i = 0; i < size; i++)
        {
            int age = 0;
            int ageOfPersonFirst = details[i][11] - '0';
            int ageOfPersonSecond = details[i][12] - '0';
            age += (ageOfPersonFirst * 10);
            age += (ageOfPersonSecond * 1);

            if (age > 60)
            {
                cnt++;
            }
        }

        return cnt;
    }
}