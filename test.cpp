#include <iostream>
#include <string>

class Solution {
public:
  bool isPalindrome(std::string s) {
    bool res = true;
    int n = s.length();
    int l = 0, r = n - 1;
    while (l <= r) {
      while (s[l] < 97 || s[l] > 122) {
        if (s[l] > 64 && s[l] < 91) {
          s[l] += 32;
          break;
        } else if (l < n - 1) {
          l++;
        } else {
          break;
        }
      }
      while (s[r] < 97 || s[r] > 122) {
        if (s[r] > 64 && s[r] < 91) {
          s[r] += 32;
          break;
        } else if (r > 0) {
          r--;
        } else {
          break;
        }
      }
      if (s[l] != s[r]) {
        std::cout << s[l] << s[r];
        return false;
      }
      l++;
      r--;
    }
    return res;
  }
};

int main() {
  Solution S;
  std::string s = "A man, a plan, a canal: Panama";
  std::cout << S.isPalindrome(s);
}
