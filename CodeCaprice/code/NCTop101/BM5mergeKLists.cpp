/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode* res = mergeSort(lists, 0, lists.size() - 1);
        return res;
    }
    ListNode* mergeSort(vector<ListNode*>& lists, int left, int right) {
        if (left > right) return nullptr;  // 必须有这行判断，否则在list为空时，left=0,right=-1,会报错
        else if (left == right) return lists[left];
        int mid = left + ((right - left) >> 1);
        ListNode* pHead1 = mergeSort(lists, left, mid);
        ListNode* pHead2 = mergeSort(lists, mid + 1, right);
        return merge(pHead1, pHead2);
    }
    ListNode* merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr) return pHead2;
        if (pHead2 == nullptr) return pHead1;
        ListNode* dummyHead = new ListNode(-1);
        ListNode* cur = dummyHead;
        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }
        if (pHead1) {
            cur->next = pHead1;
        } else {
            cur->next = pHead2;
        }
        return dummyHead->next;
    }
};