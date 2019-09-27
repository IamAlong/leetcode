/**
 *将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

 *比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N

 *之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

 *来源：力扣（LeetCode）
 *链接：https://leetcode-cn.com/problems/zigzag-conversion
 *著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        size_t tmp_str_length = 2 * numRows - 3;
        string res = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < s.length(); j += (tmp_str_length + 1)) {
                if (i == 0 || i == numRows - 1) {
                    res += s[j];
                    continue;
                }
                res += s[j];
                if (j + tmp_str_length - 2 * i + 1 < s.length()) {
                    res += s[j + tmp_str_length - 2 * i + 1];
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sl;
    string str = "PAYPALISHIRING";
    int num = 3;
    string res = sl.convert(str, num);
    cout << res << endl;
    return 0;
}
