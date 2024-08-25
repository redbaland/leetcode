class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string res;
        std::sort(strs.begin(), strs.end());
        for (int i = 0; i < strs[0].length() && i < \
            strs[strs.size() - 1].length(); i++) {
                if (strs[0][i] != strs[strs.size() - 1][i]) {
                    return res;
                }
                res += strs[0][i];
            }
        return res;
    }
};
