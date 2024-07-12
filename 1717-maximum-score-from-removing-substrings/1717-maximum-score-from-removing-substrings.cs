public class Solution {
    public int MaximumGain(string s, int x, int y) {
        int n = s.Length;
        List<char> v = new List<char>();
        List<char> v1 = new List<char>();
        int ans = 0;
        bool f;

        if (x > y) {
            f = true;
        } else {
            f = false;
        }

        foreach (char a in s) {
            if (v.Count > 0) {
                if (f) {
                    if (v[v.Count - 1] == 'a' && a == 'b') {
                        ans += x;
                        v.RemoveAt(v.Count - 1);
                    } else {
                        v.Add(a);
                    }
                } else {
                    if (v[v.Count - 1] == 'b' && a == 'a') {
                        ans += y;
                        v.RemoveAt(v.Count - 1);
                    } else {
                        v.Add(a);
                    }
                }
            } else {
                v.Add(a);
            }
        }

        foreach (char a in v) {
            if (v1.Count > 0) {
                if (!f) {
                    if (v1[v1.Count - 1] == 'a' && a == 'b') {
                        ans += x;
                        v1.RemoveAt(v1.Count - 1);
                    } else {
                        v1.Add(a);
                    }
                } else {
                    if (v1[v1.Count - 1] == 'b' && a == 'a') {
                        ans += y;
                        v1.RemoveAt(v1.Count - 1);
                    } else {
                        v1.Add(a);
                    }
                }
            } else {
                v1.Add(a);
            }
        }

        return ans;
    }
}