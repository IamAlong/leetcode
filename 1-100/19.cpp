/**
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 *
 * 示例：
 *
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 *
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0) {
            return head;
        }
        ListNode* quick = head;
        ListNode* slow = head;
        for (int i = 0; i < n; i++) {
            quick = quick->next;
        }
        if (quick == nullptr) {
            return head->next;
        }
        ListNode* tmp = slow;
        ListNode* headRes = head;
        while (quick != nullptr) {
            tmp = slow;
            slow = slow->next;
            quick = quick->next;
        }
        tmp->next = tmp->next->next;
        return headRes;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* tmp = head;
    for (int i = 2; i <= 5; ++i) {
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }
    for (ListNode* h = head; h != nullptr; h = h->next) {
        cout << h->val << "\t";
    }
    cout << endl;
    Solution solution;
    ListNode* newHead = solution.removeNthFromEnd(head, 0);
    for (ListNode* h = newHead; h != nullptr; h = h->next) {
        cout << h->val << "\t";
    }
    cout << endl;
    return 0;
}
