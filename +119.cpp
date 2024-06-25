class Solution {
public:
    std::vector<int> getRow(const int rowIndex) {
        std::vector<int> res(rowIndex + 1, 1);
        for (std::size_t  i = 1; i < rowIndex; i++) {
            res[i] = res[i - 1] * (rowIndex - i + 1) / i;
        }
        return res;
    }
};
