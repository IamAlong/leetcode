#include <iostream>
#include <vector>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* get_sum(vector<int>& l, vector<int>& r) {
    int i, j;
    vector<int> inter_res;
    for(i = 0, j = 0;
        i < l.size() && j < r.size();
        i++, j++) {
        inter_res.push_back(l[i] + r[j]);
    }
    while (i < l.size()) {
        inter_res.push_back(l[i]);
        i++;
    }
    while (j < r.size()) {
        inter_res.push_back(r[j]);
        j++;
    }
    for(int m = 0; m < inter_res.size(); m++) {
        if (inter_res[m] >= 10) {
            if (m == inter_res.size() - 1) {
                inter_res.push_back(inter_res[m] / 10);
            } else {
                inter_res[m + 1] += inter_res[m] / 10;
            }
            inter_res[m] = inter_res[m] % 10;
        }
    }
    ListNode* head = new ListNode(inter_res[0]);
    ListNode* res = head;
    for (int i = 1; i < inter_res.size(); i++) {
        head->next = new ListNode(inter_res[i]);
        head = head->next;
    }
    return res;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) {
            return nullptr;
        }
        ListNode* ll1 = l1;
        ListNode* ll2 = l2;
        vector<int> l, r;
        while(ll1) {
            l.push_back(ll1->val);
            ll1 = ll1->next;
        }
        while(ll2) {
            r.push_back(ll2->val);
            ll2 = ll2->next;
        }
        ListNode* res = get_sum(l, r);
        return res;
    }
};

int main() {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(8);
    ListNode* l2 = new ListNode(0);
    Solution SL;
    ListNode* res = SL.addTwoNumbers(l1, l2);
    while(res) {
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}
