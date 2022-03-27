class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* post = nullptr;
        while (cur != nullptr) {   // 顺序不能反
            post = cur->next;
            cur->next = pre;
            pre = cur;
            cur = post;
        }
        return pre;
    }
};