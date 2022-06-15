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
    bool isPalindrome(ListNode* head) {
        // 反转后半段链表，看两段链表是否相同
        // 1. 靠右的中间节点
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 2. 反转右半段链表
        slow = reverseList(slow);
        while (slow != nullptr) {  // 右半段长度小于等于左半段长度
            if (head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        while (head) {
            ListNode* post = head->next;
            head->next = pre;
            pre = head;
            head = post;
        }
        return pre;
    }
};