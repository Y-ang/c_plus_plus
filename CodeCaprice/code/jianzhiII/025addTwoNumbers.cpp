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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        int sum = 0;
        int carry = 0;
        ListNode* post = nullptr;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = l1 == nullptr ? 0 : l1->val;
            int val2 = l2 == nullptr ? 0 : l2->val;
            sum = val1 + val2 + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode* cur = new ListNode(sum, post);
            post = cur;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return post;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        while (head != nullptr) {
            ListNode* post = head->next;
            head->next = pre;
            pre = head;
            head = post;
        }
        return pre;
    }
};