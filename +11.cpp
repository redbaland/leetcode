class Solution {
public:
    int maxArea(const std::vector<int>& height) {
        unsigned int maxWater = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r) {
            unsigned int minHeight = 0;
            unsigned int length = r - l;
            if (height[r] > height[l]) { 
                minHeight = height[l];
                l++;
            }
            else {
                minHeight = height[r];
                r--;
            }
            unsigned int curWater = minHeight * length;
            if (curWater > maxWater) {
                maxWater = curWater;
            }
        }
        return maxWater;
    }
};
