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
        // 设置虚拟节点，因为首节点可能也重复需要删掉
        ListNode* dummyHead = new ListNode(INT_MIN);
        dummyHead->next = head;
        ListNode* cur = head;
        ListNode* pre = dummyHead;  // 第一个节点会重复需要删掉，所以需要虚拟节点统一操作
        while (cur && cur->next) {
            if (cur->val != cur->next->val) {
                pre->next = cur;
                pre = pre->next;
                cur = cur->next;
            } else {
                while (cur && cur->next && cur->val == cur->next->val) {
                    cur = cur->next;
                }
                if (cur) cur = cur->next;
            }
        }
        if (cur) pre->next = cur;
        else pre->next = nullptr;
        return dummyHead->next;
    }
};