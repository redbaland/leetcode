class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    std::size_t j = 0;
    for (std::size_t i = 0; i < nums.size() - 1; i++) {
      if (nums[i] != nums[i + 1]) {
        j < i ? nums[++j] = nums[i + 1] : ++j;
      }
    }
    return ++j;
  }
};
