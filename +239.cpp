class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> res(nums.size() - k + 1, 0);
        std::deque<unsigned> d;
        int l = 0;
        for (unsigned i = 0; i < nums.size(); i++) {
            // constructing monotonically decreasing queue { 3, -1 ... }
            while (!d.empty() && nums[d.back()] < nums[i]) {
                d.pop_back();
            }
            d.push_back(i);
            if (l > d.front()) {
                d.pop_front(); // if largest element is out of bounds pop it
            }
            if (i + 1 >= k) {
                res[(i + 1) - k] = nums[d.front()];
                l++;
            }
        }
        return res;
    }
};
