class Solution {
public:
    bool search(std::vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] == target) {
            return true;
        }      
        else if (nums[l] < nums[m]) {
            if (target < nums[m] && target >= nums[l]) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        else if (nums[l] > nums[m]) {
            if (target > nums[m] && target <= nums[r]) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        else {
            l++;
        }   
    }
    return false;        
    }
};
