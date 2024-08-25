class Solution {
public:
    int numTrees(int n) const {
        std::vector<int> numberOfTrees(n + 1, 0);
        numberOfTrees[0] = numberOfTrees[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                numberOfTrees[i] += numberOfTrees[j - 1] * numberOfTrees[i - j];
            }
        }
        return numberOfTrees[n];
    }
};
