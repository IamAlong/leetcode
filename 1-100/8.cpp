/**
请你来实现一个 atoi 函数，使其能将字符串转换成整数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。

当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0。

说明：

假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-to-integer-atoi
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) {
            return 0;
        }
        size_t first_not_space = str.find_first_not_of(" ");
        /// cout << "first_not_space: " << first_not_space << endl;
        if (first_not_space == str.npos) {
            return 0;
        }
        if (!(str[first_not_space] >= '0' && str[first_not_space] <= '9'
              || str[first_not_space] == '+' || str[first_not_space] == '-')) {
            return 0;
        }
        size_t next_invalid_num = first_not_space;
        if (str[first_not_space] == '+' || str[first_not_space] == '-') {
            next_invalid_num += 1;
            if (str[next_invalid_num] < '0' || str[next_invalid_num] > '9') {
                return 0;
            }
        }
        while (next_invalid_num < str.length()) {
            if (str[next_invalid_num] >= '0' && str[next_invalid_num] <= '9') {
                ++next_invalid_num;
            } else {
                break;
            }
        }
        /// cout << "next_invalid_num: " << next_invalid_num << endl;
        /// cout << "str: " << str << endl;
        string num_str = "";
        if (next_invalid_num == str.npos) {
            num_str = str.substr(first_not_space);
        } else {
            num_str = str.substr(first_not_space, next_invalid_num - first_not_space);
        }
        /// cout << "num_str: " << num_str << endl;
        int res = 0;
        try {
            res = stoi(num_str.c_str());
        } catch (...) {
            if (str[first_not_space] == '-') {
                res = INT_MIN;
            } else {
                res = INT_MAX;
            }
        }
        return res;
    }
};

int main() {
    Solution sl;
    string test = "- 53546545151 4";
    cout << sl.myAtoi(test) << endl;
    return 0;
}
