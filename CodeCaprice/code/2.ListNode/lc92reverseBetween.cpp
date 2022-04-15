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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyHead = new ListNode(INT_MIN, head);
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        for (int i = 1; i < left; ++i) {
            pre = cur;
            cur = cur->next;
        }
        for (int i = left; i < right; i++) {
            ListNode* post = cur->next;
            cur->next = post->next;
            post->next = pre->next;
            pre->next = post;
        }
        return dummyHead->next;
    }
};