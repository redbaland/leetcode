class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        std::string res;
        for (std::size_t j = 0; j < numRows; j++) {
            for (std::size_t i = j; i < s.length(); i += 2 * (numRows - 1)) {
                res += s[i];
                if (0 < j && j < numRows - 1 && (i + 2 * (numRows - 1 - j)) < s.length()) {
                    res += s[i + 2 * (numRows - 1 - j)];
                }
            }
        }
        return res;
    }
};
