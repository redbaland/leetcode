class Solution {
public:
    std::string minWindow(std::string s, std::string t) const {
        std::string res;
        if (s.length() < t.length()) {
            return res;
        }
        unsigned minlength = s.length() + 1;
        unsigned start = 0;
        std::unordered_map<char, int> characters;
        for (auto c : t) {
            characters[c]++;
        }
        unsigned l = 0, charcount = 0;
        std::unordered_map<char, int> seencharacters;
        for (unsigned r = 0; r < s.length(); r++) {
            if (characters.find(s[r]) != characters.end()) {    
                if (characters[s[r]] > seencharacters[s[r]]) {
                    charcount++;
                }
                seencharacters[s[r]]++;
            }
            if(charcount == t.length()) {
                while (true) {
                    if (characters.find(s[l]) != characters.end() && characters[s[l]] == seencharacters[s[l]]) {
                        break;
                    }
                    else if (characters.find(s[l]) != characters.end()) {
                        seencharacters[s[l]]--;
                        l++;
                    }
                    else {
                        l++;
                    }
                }
                int length = r - l + 1;
                if (length < minlength) {
                    minlength = length;
                    start = l;
                }
            }
        }
        if (minlength < s.length() + 1) {
            res = s.substr(start, minlength);
        }
        return res;
    }
};
