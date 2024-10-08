class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> roman = {
            {'I', 1}, {'V',  5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int res = 0;
        for (std::size_t i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && roman[s[i]] < roman[s[i + 1]]) {
                res -= roman[s[i]];
            }
            else {
                res += roman[s[i]];
            }
        }
        return res;
    }
};
