class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
       if (words.empty()) return {};

        unordered_map<char, int> commonCount;
        for (char c : words[0]) {
            commonCount[c]++;
        }

        for (auto i = 1; i < words.size(); ++i) {
            unordered_map<char, int> currentCount;
            for (char c : words[i]) {
                currentCount[c]++;
            }

            for (auto& pair : commonCount) {
                pair.second = min(pair.second, currentCount[pair.first]);
            }

            for (auto it = commonCount.begin(); it != commonCount.end();) {
                if (currentCount.find(it->first) == currentCount.end()) {
                    it = commonCount.erase(it);
                } else {
                    ++it;
                }
            }
        }
        
        vector<string> result;
        for (auto& pair : commonCount) {
            for (int i = 0; i < pair.second; ++i) {
                string s = "";
                s+=pair.first;
                result.push_back(s);
            }
        }

        return result;
    }
};