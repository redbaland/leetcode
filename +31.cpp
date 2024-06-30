class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return;
        }

        // looking for local extremum
        // swaping element to the left(which is smaller than extremum) with the 
        // smallest bigger element on the left
        // then sorting the tail to get exactly next permutation
        // if no extremum found sorting the entire array
        unsigned l = 0, r = 0;
        for (std::size_t i = nums.size() - 1; i > 0; i--) {
            l = nums[i - 1];
            if (nums[i] > l && nums[i] >= r) {
                unsigned elToSwap = nums[i], elInd = i;
                for (std::size_t j = i; j < nums.size(); j++) {
                    if (nums[j] > l && nums[j] < elToSwap) {
                        elToSwap = nums[j];
                        elInd = j;
                    }
                }
                nums[i - 1] = elToSwap;
                nums[elInd] = l;
                std::sort(nums.begin() + i, nums.end());
                return;
            }
            r = nums[i];
        }
        std::sort(nums.begin(), nums.end());
        return;
    }
};
