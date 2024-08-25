class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        int wordcount = words.size();
        int wordlength = words[0].length();
        int stringlength = static_cast<int>(s.length());
        std::vector<int> res;
        std::unordered_map<std::string, int> wordmap;
        for (const auto& w : words) {
            wordmap[w]++;
        }
        std::unordered_map<std::string, int> buf;
        for (int i = 0; i < wordlength; i++) {
            std::unordered_map<string, int> wordsinwindow;
            int l = i;
            int count = 0;
            for (int j = i; j < stringlength - wordlength + 1; j += wordlength) {
                std::string word(s, j, wordlength);
                if (wordmap.find(word) != wordmap.end()) {
                    wordsinwindow[word]++;
                    count++;
                    while (wordsinwindow[word] > wordmap[word]) {
                        wordsinwindow[s.substr(l, wordlength)]--;
                        count--;
                        l += wordlength;
                    }
                    if (count == wordcount) {
                        res.push_back(l);
                    }
                }
                else {
                    wordsinwindow.clear();
                    count = 0;
                    l = j + wordlength;
                }
            }
        }
        return res;
    }
};
