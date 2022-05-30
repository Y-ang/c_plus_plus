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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* pre = dummyHead, *cur = dummyHead; // 指向head的前一个节点
        for (int i = 0; i <= n; ++i) { // pre是待删除节点的前一个节点，cur最终会指向链表结尾，所以两者之间间隔n + 1
            cur = cur->next;
        }
        while (cur != nullptr) {
            cur = cur->next;
            pre = pre->next;
        }
        ListNode* tmp = pre->next;
        pre->next = pre->next->next;
        delete tmp;
        return dummyHead->next;
    }
};