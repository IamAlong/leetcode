/**
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
 * 使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

 * 注意：答案中不可以包含重复的三元组。

 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

 * 满足要求的三元组集合为：
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 */

#include <set>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > 0) {
                break;
            }
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    ++j;
                    continue;
                }
                if (nums[i] + nums[j] > 0) {
                    break;
                }
                int sum_jk = nums[j] + nums[k];
                if (sum_jk + nums[i] > 0) {
                    --k;
                }
                else if (sum_jk + nums[i] < 0) {
                    ++j;
                }
                else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sl;
    vector<int> nums = {-2,0,0,2,2};
    auto res = sl.threeSum(nums);
    for (auto n : res) {
        for (auto t : n) {
            cout << t << "\t";
        }
        cout << endl;
    }
}
