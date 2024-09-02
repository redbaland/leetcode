class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_queue;
        for (int i = 0; i < nums.size(); i++) {
            min_queue.push(nums[i]);
            if (min_queue.size() > k) {
                min_queue.pop();
            } 
        }
        return min_queue.top();
    }
};
