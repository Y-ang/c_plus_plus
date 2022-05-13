#include <bits/stdc++.h>
using namespace std;


struct  ListNode
{
    int val;
    ListNode* next;
    ListNode(int val_, ListNode* next_) : val(val_), next(next_) {}
};

// 先遍历再反转
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while (head != nullptr) {
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// 先遍历得到长度， 然后申请数组空间
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        int len = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            len++;
            cur = cur->next;
        }
        vector<int> res(len);
        cur = head;
        while (cur != nullptr) {
            res[--len] = cur->val;
            cur = cur->next;
        }
        return res;
    }
};