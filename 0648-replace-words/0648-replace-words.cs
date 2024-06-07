public class Solution {
    public string ReplaceWords(IList<string> dictionary, string sentence) {
        HashSet<string> rootSet = new HashSet<string>(dictionary);
        StringReader sr = new StringReader(sentence);
        StringWriter sw = new StringWriter();
        string word;
        bool firstWord = true;

        while ((word = ReadWord(sr)) != null)
        {
            string prefix = null;
            for (int i = 1; i <= word.Length; ++i)
            {
                prefix = word.Substring(0, i);
                if (rootSet.Contains(prefix))
                {
                    word = prefix;
                    break;
                }
            }
            if (!firstWord)
            {
                sw.Write(" ");
            }
            sw.Write(word);
            firstWord = false;
        }

        return sw.ToString();
    }

    private string ReadWord(StringReader sr)
    {
        StringBuilder sb = new StringBuilder();
        int ch;
        while ((ch = sr.Read()) != -1)
        {
            if (char.IsWhiteSpace((char)ch))
            {
                if (sb.Length > 0)
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
            sb.Append((char)ch);
        }
        return sb.Length > 0 ? sb.ToString() : null;
    }

}