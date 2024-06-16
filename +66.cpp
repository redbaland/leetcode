class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::vector<int> res = {}; 
        int sum = digits[digits.size() - 1] + 1;
        bool carry = sum > 9 ? true : false;
        res.insert(res.begin(), sum % 10);
        for (int i = digits.size() - 2; i >= 0; i--) {
            sum = digits[i] + (int)carry;
            res.insert(res.begin(), sum % 10);
            carry = sum > 9 ? true : false;        
        }
        if (carry) {
            res.insert(res.begin(), 1);
        }
        return res;
    }
};
