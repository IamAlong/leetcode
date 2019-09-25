/**
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/**
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    }

    int getLength(string s,  size_t l, size_t r) {
        if (l >= r) {
            return 1;
        }
        size_t  mid = (l + r) / 2;


    }

    int max3(size_t l_length, size_t m_length, size_t r_length) {
        return max(max(l_length, m_length), r_length);
    }
};
*/

#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 1 || s.length() == 0) {
            return s.length();
        }
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); j++) {
                if (s.substr(i, j - i).find(s[j]) != s.npos) {
                    if (j - i > max) {
                        max = j - i;
                    }
                    i = s.substr(i, j - i).find(s[j]) + i;
                    break;
                } else if (j ==  s.length() - 1) {
                    if (j  - i + 1  >  max) {
                        return j - i + 1;
                    }
                }
            }
        }
        return max;
    }
};

int main() {
    Solution slt;
    string s{"cbb"};
    int res = slt.lengthOfLongestSubstring(s);
    cout << res << endl;
    return 0;
}
