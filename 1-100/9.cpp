/**
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 注意：不使用字符串有数字超界的可能，故tmp使用long long型
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        bool result = true;
        if (x < 0) {
            return false;
        }
        else if (x == 0) {
            return true;
        }
        else {
            long long tmp = 0;
            int y = x;
            while (y > 0) {
                tmp = tmp * 10 + y % 10;
                y /= 10;
            }
            if (tmp != x) {
                result = false;
            }
        }
        return result;
    }
};

int main() {
    Solution sl;
    int x = 2147483647;
    if (sl.isPalindrome(x)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
