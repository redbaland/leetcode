// class Solution {
// private:
//     bool jump(std::vector<int>& nums, std::vector<bool>& dp, unsigned position) {
//         dp[position] = true;
//         for (unsigned i = nums[position]; i >= 1; i--) {
//             if (position + i >= nums.size() - 1) {
//                 return true;
//             }
//             if (!dp[position + i] && jump(nums, dp, position + i)) {
//                 return true;
//             }
//         }
//         return false;
//     }
// public:
//     bool canJump(std::vector<int>& nums) {
//         if (nums.size() == 1) {
//             return true;
//         }
//         std::vector<bool> dp(nums.size(), false);
//         return jump(nums, dp, 0);
//     }
// };
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int goal = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] + i >= goal) {
                goal = i;
            }
        }
        return goal == 0 ? true : false;
    }
};
