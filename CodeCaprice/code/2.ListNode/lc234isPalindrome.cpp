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
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* fast = head;
        ListNode* mid = head;
        // 找到中间节点
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            mid = mid->next;
        }
        mid = reverseList(mid);  // 反转后半个链表
        // 比较两个链表是否相同
        while (mid != nullptr && head != nullptr) {
            if (mid->val != head->val) return false;
            mid = mid->next;
            head = head->next;
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