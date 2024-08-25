class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
        std::vector<bool> splitable(s.length() + 1, false);
        splitable[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (dict.find(s.substr(j, i - j)) != dict.end() && splitable[j]){
                    splitable[i] = true;
                    break;
                }
            }
        }
        return splitable[s.length()];
    }
};
