class Solution {
public:
    bool isPalindrome(std::string s) {
        bool res = true;
        int n = s.length();
        int l = 0, r = n - 1;
        while (l <= r) {
            while ((s[l] < 97 || s[l] > 122) && (s[l] < 48 || s[l] > 57)) {
                if (s[l] > 64 && s[l] < 91) {
                    s[l] += 32;
                    break;
                }
                else if (l < n - 1) {
                    l++;
                }
                else {
                    return true;
                }
            }
            while ((s[r] < 97 || s[r] > 122) && (s[r] < 48 || s[r] > 57)) {
                if (s[r] > 64 && s[r] < 91) {
                    s[r] += 32;
                    break;
                }
                else if (r > 0) {
                    r--;
                }
                else {
                    return true;
                }
            }
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return res;
    }
};
