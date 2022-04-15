/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        for (int i = 1; i < m; ++i) {
            pre = cur;
            cur = cur->next;
        }
        for (int i = m; i < n; i++) {
            ListNode* post = cur->next;
            cur->next = post->next;
            post->next = pre->next;
            pre->next = post;
        }
        return dummyHead->next;
    }
};