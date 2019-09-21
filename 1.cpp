#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Num_Id {
    int num_;
    size_t id_;
    Num_Id(int num, size_t id)
        : num_ { num },
          id_ { id } {
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<Num_Id> num_id;
        for (size_t index = 0; index < nums.size(); index++) {
            num_id.push_back(Num_Id(nums[index], index));
        }
        sort(num_id.begin(), num_id.end(),
             [](Num_Id ni1, Num_Id ni2) {
                return ni1.num_ < ni2.num_;
             }
        );
        size_t id_min = 0, id_max = num_id.size() - 1;
        while (num_id[id_min].num_ + num_id[id_max].num_ != target) {
            if (num_id[id_min].num_ + num_id[id_max].num_ > target) {
                id_max--;
            } else {
                id_min++;
            }
        }
        vector<int> res;
        res.push_back(num_id[id_min].id_);
        res.push_back(num_id[id_max].id_);
        return res;
    }
};

int main() {
    int a[4] = {3, 2, 4};
    vector<int> vi(a, a + 3);
    Solution s;
    vector<int> res = s.twoSum(vi, 6);
    for(auto i : res) {
        cout << i << endl;
    }
    return 0;
}
