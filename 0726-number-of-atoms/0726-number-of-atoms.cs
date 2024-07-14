public class Solution {
    private int i;
    public string CountOfAtoms(string formula) {
        StringBuilder ans = new StringBuilder();
        i = 0;
        var counts = CountOfAtoms(formula.ToCharArray());
        foreach (var name in counts.Keys) {
            ans.Append(name);
            int count = counts[name];
            if (count > 1) ans.Append(count);
        }
        return ans.ToString();
    }
    
    private SortedDictionary<string, int> CountOfAtoms(char[] f) {
        var ans = new SortedDictionary<string, int>();
        while (i < f.Length) {
            if (f[i] == '(') {
                i++;
                var tmp = CountOfAtoms(f);
                int count = GetCount(f);
                foreach (var entry in tmp) {
                    if (ans.ContainsKey(entry.Key)) {
                        ans[entry.Key] += entry.Value * count;
                    } else {
                        ans[entry.Key] = entry.Value * count;
                    }
                }
            } else if (f[i] == ')') {
                i++;
                return ans;
            } else {
                string name = GetName(f);
                if (ans.ContainsKey(name)) {
                    ans[name] += GetCount(f);
                } else {
                    ans[name] = GetCount(f);
                }
            }
        }
        return ans;
    }

    private string GetName(char[] f) {
        StringBuilder name = new StringBuilder();
        name.Append(f[i++]);
        while (i < f.Length && char.IsLower(f[i])) {
            name.Append(f[i++]);
        }
        return name.ToString();
    }

    private int GetCount(char[] f) {
        int count = 0;
        while (i < f.Length && char.IsDigit(f[i])) {
            count = count * 10 + (f[i] - '0');
            i++;
        }
        return count == 0 ? 1 : count;
    }
}