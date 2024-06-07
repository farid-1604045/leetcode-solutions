class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> rootSet(dictionary.begin(), dictionary.end());
        istringstream iss(sentence);
        ostringstream oss;
        string word;
        bool firstWord = true;

        while (iss >> word) {
            string prefix;
            for (size_t i = 1; i <= word.length(); ++i) {
                prefix = word.substr(0, i);
                if (rootSet.find(prefix) != rootSet.end()) {
                    word = prefix;
                    break;
                }
            }
            if (!firstWord) {
                oss << " ";
            }
            oss << word;
            firstWord = false;
        }

        return oss.str();
    }
};