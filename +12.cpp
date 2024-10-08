class Solution {
public:
    std::string intToRoman(int num) {
        std::string res;
        std::array<int, 13> arabic = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        std::vector<std::string> roman = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        while (num) {
            for (int i = arabic.size() - 1; i >= 0; i--) {
                if (num / arabic[i]) {
                    for (int j = 0; j < num / arabic[i]; j++) {
                        res += roman[i];
                    }
                    num %= arabic[i];
                    break;
                }
            }
        }
        return res;
    }
};
