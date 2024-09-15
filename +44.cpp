class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        std::vector<bool> prev(p.length() + 1, false);
        std::vector<bool> curr(p.length() + 1, false);
        prev[0] = true;

        for (std::size_t i = 0; i < p.length(); i++) {
            if (p[i] == '*') {
                prev[i + 1] = prev[i];
            }
        }

        for (std::size_t i = 0; i < s.length(); i++) {
            for (std::size_t j = 0; j < p.length(); j++) {
                if (p[j] == s[i] || p[j] == '?') {
                    curr[j + 1] = prev[j];
                }
                else if (p[j] == '*') {
                    curr[j + 1] = (curr[j] || prev[j + 1]);
                }
                else {
                    curr[j + 1] = false;
                }
            }
            std::swap(prev, curr);
            curr[0] = false;
        }

        return prev[p.length()];
    }
};
