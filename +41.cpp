class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int res = nums.size() + 1;
        for (auto& el : nums) {
            if (el < 0) {
                el = 0;
            }
        }
        for (auto& el : nums) {
            if (std::abs(el) - 1 >= 0 && std::abs(el) - 1 < nums.size()) {
                if (nums[std::abs(el) - 1] == 0) {
                    nums[std::abs(el) - 1] = -res;
                }
                else if (nums[std::abs(el) - 1] > 0) {
                    nums[std::abs(el) - 1] *= -1;
                }
            }
        }
        for (std::size_t i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                return i + 1;
            }
        }
        return res;
    }
};
