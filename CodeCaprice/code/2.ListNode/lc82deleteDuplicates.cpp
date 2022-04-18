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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        // 设置虚头节点，以相同操作处理链表重复元素（头节点可能也是重复元素）
        ListNode* dummyHead = new ListNode(INT_MIN, head);
        ListNode* cur = dummyHead;
        // 比较下一个节点和下下节点是否值相同
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {      // 两节点值相同
                int tmpVal = cur->next->val;
                while (cur->next && cur->next->val == tmpVal) { // 逐个删除相同的元素
                    ListNode* tmp = cur->next;
                    cur->next = cur->next->next;
                    delete tmp;
                }
            } else {
                cur = cur->next;    // 两节点值不同
            }
        }
        return dummyHead->next;
    }
};