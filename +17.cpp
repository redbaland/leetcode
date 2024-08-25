class Solution {
private:
    unordered_map<char, string> mapping = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

    std::vector<std::string> ans;

    void combinationFrom(std::string digits, int index, std::string combination = "") {
        if (index == digits.length()) {
            ans.push_back(combination);
            return;
        }
        else {
            for (char c : mapping[digits[index]]) {
                combinationFrom(digits, index + 1, combination + c);
            }
        }
    }

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) {
            return {};
        }
        combinationFrom(digits, 0);
        return ans;
    }
};
