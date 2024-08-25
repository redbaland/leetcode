class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int min = 5000;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[l] < nums[m]) {
                if (nums[l] < min) {
                    min = nums[l];
                }
                l = m + 1;
            }
            else if (nums[l] > nums[m]) {
                if (nums[m] < min) {
                    min = nums[m];
                }
                r = m - 1;
            }
            else {
                if (nums[m] < min) {
                    min = nums[m];
                }
                l++;
            }
        }
        return min;
    }
};
