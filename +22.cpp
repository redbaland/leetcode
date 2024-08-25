class Solution {
private:
    std::vector<std::string> res;

    void dfs(int n, int opening, int closing, std::string s) {
        if (opening == n && closing == n) {
            res.push_back(s);
            return;
        }
        if (opening < n) {
            dfs(n, opening + 1, closing, s + "(");
        }
        if (opening > closing) {
            dfs(n, opening, closing + 1, s + ")");
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        if (!n) {
            return {};
        }
        dfs(n, 0, 0, "");
        return res;
    }
};
