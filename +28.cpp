class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (haystack.length() < needle.length()) {
            return -1;
        }
        for (std::size_t i = 0; i <= haystack.length() - needle.length(); i++) {
            if (haystack.compare(i, needle.length(), needle) == 0) {
                return i;
            }        
        }
        return -1;
    }
};
