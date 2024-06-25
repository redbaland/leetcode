class Solution {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int> &nums, long target) {
    if (nums.size() < 4) {
        return {};  // should be {{}}, but it doesn't pass test answer []
        }

    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;
    std::vector<int> quadruplet(4, 0);

    // recursion solution for n sum
    std::function<void(unsigned, unsigned, long)> nSum =
        [&nums, &quadruplet, &res, &nSum](unsigned n, unsigned start,
                                          long target) {
          if (n != 2) {
            for (std::size_t i = start; i < nums.size() - n + 1; i++) {
              if (i > start && nums[i] == nums[i - 1]) {
                continue;
              }
              quadruplet[quadruplet.size() - n] = nums[i];
              nSum(n - 1, i + 1, target - nums[i]);
            }
            return;
          }

          // base case n == 2
          unsigned l = start, r = nums.size() - 1;
          while (l < r) {
            if (nums[l] + nums[r] < target) {
              l++;
            } else if (nums[l] + nums[r] > target) {
              r--;
            } else {
              quadruplet[quadruplet.size() - 2] = nums[l];
              quadruplet[quadruplet.size() - 1] = nums[r];
              res.push_back(quadruplet);
              l++;
              while (l < r && nums[l - 1] == nums[l]) {
                l++;
              }
            }
          }
        };

    nSum(4, 0, target);
    return res;
  }
};
