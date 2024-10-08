class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) {
            return 1;
        }
        if (divisor == 1 && dividend != 0) {
            return dividend;
        }
        if (dividend == std::numeric_limits<int>::min() && divisor == -1) {
            return std::numeric_limits<int>::max();
        }
        if (divisor == std::numeric_limits<int>::min()) {
            return 0;
        }
        int res = 0;
        if (dividend == std::numeric_limits<int>::min()) {
            dividend = divisor > 0 ? dividend + divisor : dividend - divisor;
            res++;
        }
        bool positive = (dividend < 0 == divisor < 0); 
        dividend = std::abs(dividend), divisor = std::abs(divisor);
        while (dividend >= divisor) {
            short count = 0;   // Was hard to understand. It's because a << 0 = a, so << 0 eaquals * 1
            while (((divisor << count) < (std::numeric_limits<int>::max() >> 2)) && dividend >= (divisor << (count + 1))) {
                count++;  // I don't know how it worked with max >> 2
            }             // most likely (divisor << count + 1) < (max << 1), so (divisor << count) < (max << 2)
            res += 1 << count;
            dividend -= divisor << count;
        }
        return positive ? res : -res;
    }
};
