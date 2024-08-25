class Solution {
public:
  std::string simplifyPath(std::string path) {
    std::stack<std::string> stack;
    std::string dir;
    for (auto i = 0; auto character : path) {
      i++;
      if (character != '/') {
        dir.push_back(character);
      }
      if ((character == '/' || i == path.length()) && dir.length() > 0) {
        if (dir.compare("..") == 0 && !stack.empty()) {
          stack.pop();
        } else if (dir.compare("..") != 0 && dir.compare(".") != 0) {
          stack.push(dir);
        }
        dir.clear();
      }
    }
    std::string res;
    while (!stack.empty()) {
      res.insert(0, stack.top());
      res.insert(0, "/");
      stack.pop();
    }
    return res.length() ? res : "/";
  }
};
