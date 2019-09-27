#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res;
        int num1_i = 0, num2_i = 0;
        int num1_j = nums1.size() - 1, num2_j = nums2.size() - 1;
        while(num1_i <= num1_j && num2_i <= num2_j) {
            if (num1_i == num1_j && num2_i == num2_j) {
                return (nums1[num1_j] + nums2[num2_i]) / 2.0;
            }
            if (nums1[num1_i] < nums2[num2_i]) {
                num1_i++;
            } else {
                num2_i++;
            }
            if (nums1[num1_j] > nums2[num2_j]) {
                num1_j--;
            } else {
                num2_j--;
            }
        }
        if (num1_i <= num1_j) {
            if ((num1_j - num1_i + 1) % 2 == 0) {
                res = (nums1[(num1_i + num1_j) / 2] + nums1[(num1_i + num1_j) / 2 + 1]) / 2.0;
            } else {
                res = nums1[(num1_i + num1_j) / 2];
            }
        } else if (num2_i <= num2_j) {
            if ((num2_j - num2_i + 1) % 2 == 0) {
                res = (nums2[(num2_i + num2_j) / 2] + nums2[(num2_i + num2_j) / 2 + 1]) / 2.0;
            } else {
                res = nums2[(num2_i + num2_j) / 2];
            }
        } else {
            if (num1_j < 0 || num2_i == nums2.size()) {
                res = (nums2[num2_j] + nums1[num1_i]) / 2.0;
            } else {
                res = (nums1[num1_j] + nums2[num2_i]) / 2.0;
            }
        }
        return res;
    }
};

int main() {
    vector<int> num1 = {1, 4};
    vector<int> num2 = {2, 3, 5, 6};
    Solution sl;
    double res = sl.findMedianSortedArrays(num1, num2);
    cout << res << endl;
    return 0;
}
