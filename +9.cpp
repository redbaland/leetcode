class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long invert = 0;
        int x_copy = x;
        while (x_copy) {
            int digit = x_copy % 10;
            x_copy /= 10;
            invert = invert * 10 + digit;
        }
        return x == invert;
    }
};
