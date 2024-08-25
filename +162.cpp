class Solution {
public:
    int findPeakElement(std::vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (true) {
            int m = l + (r - l) / 2;
            if (m > 0 && nums[m - 1] > nums[m]) {
                r = m - 1;
            }
            else if (m < nums.size() - 1 && nums[m + 1] > nums[m]) {
                l = m + 1;
            }
            else {
                return m;
            }
        }
    }
};
