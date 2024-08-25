class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> notClosedParentheses;
        for (auto el : s) {
            switch (el) {
                case '}':
                    if (notClosedParentheses.empty() || notClosedParentheses.top() != '{') {
                        return false;
                    }
                    else {
                        notClosedParentheses.pop();
                    }
                    break;
                case ']':
                    if (notClosedParentheses.empty() || notClosedParentheses.top() != '[') {
                        return false;
                    }
                    else {
                        notClosedParentheses.pop();
                    }
                    break;
                case ')':
                    if (notClosedParentheses.empty() || notClosedParentheses.top() != '(') {
                        return false;
                    }
                    else {
                        notClosedParentheses.pop();
                    }
                    break;
                default:
                    notClosedParentheses.push(el);
                    break;
            }
        }
        return notClosedParentheses.empty();
    }
};
