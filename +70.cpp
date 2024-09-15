class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, curr = 1;
        for (int i = 2; i < n + 1; i++) {
            int tmp = curr;
            curr = prev + curr;
            prev = tmp;
        }
        return curr;
    }
};
