class Solution {
public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> res;
    for (std::size_t i = 0; i < numRows; i++) {
      res.emplace_back(i + 1, 0);
      for (std::size_t j = 0; j <= i; j++) {
        j == 0 || j == i ? res[i][j] = 1
                         : res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
      }
    }
    return res;
  }
};
