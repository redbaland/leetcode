class Solution {
public:
    int jump(std::vector<int>& nums) {
        int res = 0, l = 0, r = 0;
        while (r < nums.size() - 1) {
            int max = 0;
            for (int i = l; i <= r; i++) {
                max = i + nums[i] > max ? i + nums[i] : max;
            }
            l = r + 1;
            r = max;
            res++;
        }
        return res;
    }
};
