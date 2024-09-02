class Solution {
private:
  bool solved = false;

  std::vector<char> findPossible(std::vector<std::vector<char>> &board, int x, int y) {
    std::unordered_map<char, bool> chars = {
        {'1', true}, {'2', true}, {'3', true}, {'4', true}, {'5', true},
        {'6', true}, {'7', true}, {'8', true}, {'9', true}};
    for (int i = 0; i < 9; i++) {
      if (board[y][i] != '.') {
        chars[board[y][i]] = false;
      }
      if (board[i][x] != '.') {
        chars[board[i][x]] = false;
      }
      if (board[(y / 3) * 3 + i / 3][(x / 3) * 3 + i % 3] != '.') {
        chars[board[(y / 3) * 3 + i / 3][(x / 3) * 3 + i % 3]] = false;
      }
    }
    std::vector<char> possible;
    for (const auto &[key, value] : chars) {
      if (value) {
        possible.push_back(key);
      }
    }
    return possible;
  }

  void solve(std::vector<std::vector<char>> &board, int x, int y) {
    if (x == 8 && y == 8) {
      solved = true;
      return;
    }
    for (int j = y; j < 9; j++) {
      for (int i = x; i < 9; i++) {
        if (board[j][i] == '.') {
          std::vector<char> possible = findPossible(board, i, j);
          if (!possible.empty()) {
            for (char p : possible) {
              if (!solved) {
                board[j][i] = p;
                solve(board, i, j);
              } else {
                return;
              }
            }
            if (!solved) {
              board[j][i] = '.';
              return;
            } else {
              return;
            }
          } else {
            return;
          }
        } else if (i == 8 && j == 8) {
          solved = true;
          return;
        }
      }
      x = 0;
    }
  }

public:
  void solveSudoku(std::vector<std::vector<char>> &board) {
    solve(board, 0, 0);
  }
};
