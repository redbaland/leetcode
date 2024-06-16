class Solution {
public:
  int searchInsert(std::vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    unsigned int i = 0;
    while (l <= r) {
      i = (l + r) / 2.0;
      if (nums[i] == target) {
        return i;
      } else if (nums[i] < target) {
        l = i + 1;
      } else {
        r = i - 1;
      }
    }
    return nums[i] < target ? ++i : i;
  }
};

