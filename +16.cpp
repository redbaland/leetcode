class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int closestSum = nums[0] + nums[1] + nums[2];
        int minDiff = std::numeric_limits<int>::max();
        std::sort(nums.begin(), nums.end());
        for (std::size_t i = 0; i < nums.size() - 1; i++) {
            /*if (i > 0 && nums[i] == nums[i - 1]) {  // Commenting this sections lets code run 5ms faster
                continue;                             // but require more memory. Speed memory trade I guess
            }*/
            unsigned int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                bool diffSigns = target * sum < 0 ? true : false;
                if (sum < target) {
                    l++;
                    /*while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }*/
                }
                else if(sum > target) {
                    r--;
                    /*while (l < r && nums[r] == nums[r + 1]) {
                        r--;
                    }*/
                }
                else {
                    return sum;
                }
                int diff = diffSigns ? std::abs(target) + std::abs(sum) : std::abs(target - sum);
                if (diff < minDiff) {
                    minDiff = diff;
                    closestSum = sum;
                }
            }
        }
        return closestSum;
    }
};
