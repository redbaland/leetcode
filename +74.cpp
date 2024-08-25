class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;
        int left = 0, top = 0;
        while (top <= m && left <= n) {
            unsigned vertical_mid = (top + m) / 2;
            unsigned horizontal_mid = (left + n) / 2;
            if (matrix[vertical_mid][horizontal_mid] == target) {
                return true;
            }
            else if (matrix[vertical_mid][horizontal_mid] < target) {
                if (matrix[vertical_mid][matrix[0].size() - 1] >= target) {
                    left = horizontal_mid + 1;
                }
                else {
                    left = 0;
                    top = vertical_mid + 1;
                } 
            }
            else {
                if (matrix[vertical_mid][0] <= target) {
                    n = horizontal_mid - 1;
                }
                else {
                    n = matrix[0].size() - 1;
                    m = vertical_mid - 1;
                }
            }
        }
        return false;
    }
};
