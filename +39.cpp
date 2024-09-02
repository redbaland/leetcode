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
            solve(candidates, target - candidates[i], i);
            comb.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        solve(candidates, target, 0);
        return res;
    }
};
