/**
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 *
 * 如果不存在公共前缀，返回空字符串 ""。
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
	public:
        string longestCommonPrefix(vector<string>& strs) {
            if (!strs.size()) {
                return "";
            }
            string res = strs[0];
            for (int i = 1; i < strs.size(); i++) {
                string tmp = "";
                for (int j = 0; j < res.length() && j < strs[i].length(); j++) {
                    if (res[j] == strs[i][j]) {
                        tmp.push_back(res[j]);
                    }
                    else {
                        break;
                    }
                }
                res = string(tmp);
            }
            return res;
        }
};

int main() {
    vector<string> strs;
    strs.push_back("aa");
    strs.push_back("a");
    Solution sl;
    cout << sl.longestCommonPrefix(strs);
    return 0;
}
