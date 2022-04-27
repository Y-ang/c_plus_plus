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
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {  // 当前节点和后一节点重复
                cur->next = cur->next->next;
            } else {
                cur = cur->next;   // 无重复
            }
        }
        return head;
    }
};