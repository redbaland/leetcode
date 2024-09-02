class Solution {
private:
    std::vector<std::vector<int>> res;
    std::vector<int> comb;

    void solve(std::vector<int>& candidates, int target, int ind) {
        if (target == 0) {
            res.push_back(comb);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = ind; i < candidates.size(); i++) {
            comb.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1);
            comb.pop_back();
            while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) {
                i++;
            }
        }
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);
        return res;
    }
};
