class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        std::vector<int> res(2,1);
        for (std::size_t i = 0; i < numbers.size() - 1; i++) {
            int l = i + 1, r = numbers.size() - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (target == numbers[m] + numbers[i]) {
                    res[0] += i;
                    res[1] += m;
                    return res;
                }
                else if (target < numbers[m] + numbers[i]) {
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
        }
        return res;
    }
};
