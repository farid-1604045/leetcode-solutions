public class Solution {
    public string ReverseParentheses(string s) {
        List<int> opened = new List<int>();
        StringBuilder res = new StringBuilder();

        for (int i = 0; i < s.Length; ++i) {
            if (s[i] == '(') {
                opened.Add(res.Length);
            } else if (s[i] == ')') {
                int j = opened[opened.Count - 1];
                opened.RemoveAt(opened.Count - 1);
                Reverse(res, j, res.Length - 1);
            } else {
                res.Append(s[i]);
            }
        }
        return res.ToString();
    }

    private void Reverse(StringBuilder sb, int left, int right) {
        while (left < right) {
            char temp = sb[left];
            sb[left] = sb[right];
            sb[right] = temp;
            left++;
            right--;
        }
    }
}