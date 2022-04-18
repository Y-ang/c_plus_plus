/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode* dummyHead = new ListNode(INT_MIN);  // 加表头
        ListNode* cur = dummyHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {  // 指向值较小的节点
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;    // 移动到下一个节点
        }
        if (list1) {  // 保存剩下的节点
            cur->next = list1;
        } else {
            cur->next = list2;
        }
        return dummyHead->next;
    }
};