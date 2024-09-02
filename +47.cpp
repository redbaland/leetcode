class Solution {
private:
    std::vector<std::vector<int>> res;
    std::vector<int> permutation;
    std::unordered_map<int, unsigned> countMap;
    unsigned len;

    void backtrack() {
        if (permutation.size() == len) {
            res.push_back(permutation);
            return;
        }
        for (auto& [key, val] : countMap) {
            if (val) {
                permutation.push_back(key);
                val--;
                backtrack();
                val++;
                permutation.pop_back();
            }
        }
    }

public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        for (auto num : nums) {
            countMap[num]++;
        }
        len = nums.size();
        backtrack();
        return res;
    }
};
