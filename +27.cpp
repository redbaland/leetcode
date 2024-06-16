class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        std::size_t j = 0;
        for (std::size_t i = 0; i < nums.size(); i++){
            if (nums[i] != val) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
