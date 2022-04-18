class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        // fast走k步，如果在k步之前遇到了空节点，说明链表长度没有k，返回空
        for (int i = 0; i < k; i++) {
            if (fast == nullptr) return 0;
            fast = fast->next;
        }
        // 直到fast为空
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow->val;
    }
};