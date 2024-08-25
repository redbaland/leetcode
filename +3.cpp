class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> substring;
        int l = 0;
        int maxlen = 0;
        for (int r = 0; r < s.length(); r++) {
            while (substring.find(s[r]) != substring.end()) {
                substring.erase(s[l]);
                l++;
            }
            substring.insert(s[r]);
            if (r - l + 1 > maxlen) {
                maxlen = r - l + 1;
            }
        }
        return maxlen;
    }
};
