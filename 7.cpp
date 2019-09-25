/**
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 *
 * 假设我们的环境只能存储得下  32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。
 * 请根据这个假设，如果反转后整数溢出那么就返回 0。
 * ref: https://leetcode-cn.com/problems/reverse-integer/
 */


#include <iostream>
#include <limits.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }
        int result = 0;
        int y = x;
        while (y != 0) {
            int number = y % 10;
            y /= 10;
        /// cout << "reuslt: " << result << "\ty: " << y << endl;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && y % 10 > 7)
                || result < INT_MIN / 10 || (result == INT_MIN / 10 && y % 10 < -8)) {
                return 0;
            }
            result = 10 * result + number;
        }
        return result;
    }
};

int main() {
    Solution sl;
    int x = -2147483412;
    int res = sl.reverse(x);
    cout << res << endl;
    return 0;
}
