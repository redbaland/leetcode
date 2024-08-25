/* It passes tests but worst case complexity is O(n) instead of O(logn)
better to use approach with two calls of binary search, one for left bound and other
for right bound */
 
class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> res(2, -1);
        int l = 0, r = nums.size() - 1;
        int leftInd = 0, rightInd = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                leftInd = mid;
                rightInd = mid;
                while (true) {
                    if (leftInd > 0 && nums[leftInd - 1] == target) {
                        leftInd--;
                    }
                    else {
                        break;
                    }
                }
                while (true) {
                    if (rightInd < nums.size() - 1 && nums[rightInd + 1] == target) {
                        rightInd++;
                    }
                    else {
                        break;
                    }
                }
                res[0] = leftInd;
                res[1] = rightInd;
                return res;
            }
            else if (target > nums[mid]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return res;
    }
};
