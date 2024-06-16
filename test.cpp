#include <iostream>
#include <vector>

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

int main() {
  Solution s;
  int target1 = 0, target2 = 2, target3 = 4, target4 = 6;
  std::vector<int> nums = {1, 3, 5};
  int k1 = s.searchInsert(nums, target1);
  int k2 = s.searchInsert(nums, target2);
  int k3 = s.searchInsert(nums, target3);
  int k4 = s.searchInsert(nums, target4);
  std::cout << k1 << std::endl;
  std::cout << k2 << std::endl;
  std::cout << k3 << std::endl;
  std::cout << k4 << std::endl;
  return 0;
}
