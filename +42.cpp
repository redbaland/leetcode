class Solution {
public:
    int trap(std::vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int res = 0, l = 0, r = height.size() - 1, \
            leftMax = height[l], rightMax = height[r];
        while (l < r) {
            if (rightMax < leftMax) {
                r--;
                rightMax = rightMax > height[r] ? rightMax : height[r];
                res += rightMax - height[r];
            }
            else {
                l++;
                leftMax = leftMax > height[l] ? leftMax : height[l];
                res += leftMax - height[l];
            }
        }
        return res;
    }
};
