class Solution {
public:
    std::string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        std::string prev = countAndSay(n - 1);
        std::string res = "";
        unsigned count = 1;
        for (std::size_t i = 0; i < prev.length(); i++) {
            if (i + 1 < prev.length() && prev[i] == prev[i + 1]) {
                count++;
            }
            else {

                res += std::to_string(count) + prev[i];
                count = 1;
            }
        }
        return res;
    }
};
