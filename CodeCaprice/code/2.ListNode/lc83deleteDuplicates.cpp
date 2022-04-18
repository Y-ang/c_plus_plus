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
        ListNode* cur = head;
        // 比较当前节点和它下一个节点
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->val == cur->next->val) {  // 若值相同，删除下一个节点
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {                           // 若不同，移动到下一个节点
                cur = cur->next;
            }
        }
        return head;
    }
};