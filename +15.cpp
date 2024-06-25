class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());
    for (std::size_t i = 0; i < nums.size() - 1 && nums[i] <= 0; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      unsigned int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum > 0) {
          r--;
        } else if (sum < 0) {
          l++;
        } else {
          std::vector<int> triplet = {nums[i], nums[l], nums[r]};
          res.push_back(triplet);
          l++;
          while (l < r && nums[l] == nums[l - 1]) {
            l++;
          }
        }
      }
    }
    return res;
  }
};
