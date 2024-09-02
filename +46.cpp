class Solution {
private:
    std::vector<std::vector<int>> res;

    void backtrack(std::vector<int>& nums, int ind) {
        if (ind == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = ind; i < nums.size(); i++) {
            int tmp = nums[ind] ^ nums[i];
            nums[ind] = nums[i];
            nums[i] = tmp ^ nums[ind];
            backtrack(nums, ind + 1);
            nums[i] = tmp ^ nums[i];
            nums[ind] = tmp ^ nums[i];
        }
    }
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};
