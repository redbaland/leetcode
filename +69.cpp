class Solution {
public:
    int mySqrt(int x) {
        if (x < 2)
            return x;
        unsigned l = 1, r = x;
        while (l <= r) {
            unsigned mid = (l + r) / 2;
            unsigned long long square = (unsigned long long)mid * (unsigned long long)mid;
            if (square == x) {
                return mid;
            }
            else if (square > x) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return r;
    }
};
