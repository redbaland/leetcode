class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::unordered_set<char> rows[9];
        std::unordered_set<char> cols[9];
        std::unordered_set<char> boxes[9];

        for (std::size_t i = 0; i < board.size(); i++) {
            for (std::size_t j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                else {
                    if (rows[i].count(board[i][j]) || cols[j].count(board[i][j]) \
                                || boxes[3 * (i / 3) + j / 3].count(board[i][j])) {
                            return false;
                        }
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    boxes[3 * (i / 3) + j / 3].insert(board[i][j]);         
                }
            }
        }

        return true;
    }
};
