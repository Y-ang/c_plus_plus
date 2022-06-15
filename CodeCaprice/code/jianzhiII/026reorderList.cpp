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
    void reorderList(ListNode* head) {
        // 反转后半段链表，然后合并
        if (head == nullptr || head->next == nullptr) return;
        // 1. 找中间节点（左侧）
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 2. 反转后半段
        ListNode* l1 = head;
        ListNode* l2 = slow->next;
        slow->next = nullptr;
        l2 = reverseList(l2);
        // 3. 合并前后两段
        mergeList(l1, l2);
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
    void mergeList(ListNode* l1, ListNode* l2) {
        while (l1 != nullptr && l2 != nullptr) { // l1链表长度 >= l2链表长度
            ListNode* l1Post = l1->next;
            ListNode* l2Post = l2->next;
            l1->next = l2;
            l2->next = l1Post;
            l1 = l1Post;
            l2 = l2Post;
        }
    }
};