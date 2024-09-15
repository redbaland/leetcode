class Solution {
private:
    std::unordered_map<std::string, bool> match_map;

    bool dfs(int s_ptr, int p_ptr, std::string s, std::string p) {
        std::string key = std::to_string(s_ptr) + '_' + std::to_string(p_ptr);
        if (match_map.find(key) != match_map.end()) {
            return match_map[key];
        }
        if (s_ptr >= s.length() && p_ptr >= p.length()) {
            return true;
        }
        else if (p_ptr >= p.length()) {
            return false;
        }
        else {
            bool char_match = s_ptr < s.length() && \
                (s[s_ptr] == p[p_ptr] || p[p_ptr] == '.');
            if (p_ptr < p.length() - 1 && p[p_ptr + 1] == '*') {
                match_map[key] = dfs(s_ptr, p_ptr + 2, s, p) || \
                    (char_match && dfs(s_ptr + 1, p_ptr, s, p));
                return match_map[key];
            }
            else if (char_match) {
                match_map[key] = dfs(++s_ptr, ++p_ptr, s, p);
                return match_map[key];
            }
            else {
                match_map[key] = false;
                return false;
            }
        }
    }
public:
    bool isMatch(std::string s, std::string p) {
        return dfs(0, 0, s, p);
    }
};
