class Solution {
public:
    int longestValidParentheses(std::string s) {
        unsigned opened = 0, closed = 0, max = 0;
        for (unsigned i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                opened++;
            }
            else {
                closed++;
            }
            if (opened == closed && max < opened * 2) {
                max = opened * 2;
            }
            else if (closed > opened) {
                opened = 0;
                closed = 0;
            }
        }
        opened = 0;
        closed = 0;
        for (int j = s.length() - 1; j >= 0; j--) {
            if (s[j] == '(') {
                opened++;
            }
            else {
                closed++;
            }
            if (opened == closed && max < opened * 2) {
                max = opened * 2;
            }
            else if (opened > closed) {
                opened = 0;
                closed = 0;
            }
        }
        return max;
    }
};
