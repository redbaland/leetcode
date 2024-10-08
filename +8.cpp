class Solution {
public:
    int myAtoi(std::string s) {
        int max = std::numeric_limits<int>::max();
        int min = std::numeric_limits<int>::min();
        long res = 0;
        bool positive = true;
        std::size_t i = 0;
        for (; i < s.length() && s[i] == ' '; i++) {}
        if (s[i] == '-') {
            positive = false;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }
        for (; i < s.length() && s[i] == '0'; i++) {}
        for (; i < s.length(); i++) {
            if (0 <= s[i] - '0' && s[i] - '0' <= 9) { 
                res = res * 10 + (s[i] - '0');
                if (positive && res >= max) {
                    return max;
                }
                if (!positive && (-1) * res <= min) {
                    return min;
                }
            }
            else {
                break;
            }
        }
        return positive ? res : res * (-1);
    }
};
