/**
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 *
 * 有效字符串需满足：
 *
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 注意空字符串可被认为是有效字符串。
 */

#include <string>
#include <stack>
#include <map>
#include <iostream>

using namespace std;

namespace {
    map<char, char> brackets {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
    };
}

class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) {
            return true;
        }
        stack<char> bracketStack;
        for (auto c : s) {
            if (!bracketStack.empty()) {
                char bracketStackTop = bracketStack.top();
                if (c == brackets[bracketStackTop]) {
                    bracketStack.pop();
                    continue;
                } else if (bracketStackTop != '(' && bracketStackTop != '[' && bracketStackTop != '{') {
                    return false;
                }
            }
            bracketStack.push(c);
        }
        if (!bracketStack.empty()) {
            return false;
        }
        return true;
    }
};

int main() {
    string s = "{[]}";
    Solution solution;
    cout << solution.isValid(s) << endl;
    return 0;
}
