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
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        ListNode* tail = head;
        while (cur != nullptr) {
            for (int i = 1; i <= k; i++) {  // 如果当前组不满k个节点，直接返回
                if (tail == nullptr) return dummyHead->next;
                tail = tail->next;
            }
            for (int i = 1; i < k; ++i) {  // 反转本次k个节点
                ListNode* post = cur->next;
                cur->next = post->next;
                post->next = pre->next;
                pre->next = post;
            }
            pre = cur;      
            cur = cur->next;   // 到下一组的首节点
        }
        return dummyHead->next;
    }
};