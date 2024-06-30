class Solution {
public:
    std::string longestPalindrome(std::string s) {
        unsigned lmax = 0, rmax = 0, maxlength = 1;

        // cycle for even substrings
        for (std::size_t i = 0; i < s.length() - 1; i++) {
            int l = i, r = i + 1;
            unsigned length = 0;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                length += 2;
                if (length > maxlength) {
                    maxlength = length;
                    lmax = l;
                    rmax = r;
                }
                l--;
                r++;
            }    
        }

        // cycle for odd substrings
        for (std::size_t i = 1; i < s.length() - 1; i++) {
            int l = i - 1, r = i + 1;
            unsigned length = 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                length += 2;
                if (length > maxlength) {
                    maxlength = length;
                    lmax = l;
                    rmax = r;
                }
                l--;
                r++;
            }
        }

        std::string res(s, lmax, rmax - lmax + 1);
        return res;
    }
};
