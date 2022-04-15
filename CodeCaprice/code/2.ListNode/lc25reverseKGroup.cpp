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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        ListNode* tail = head;  // 指向下一组的首节点，用于判断当前组是否有k个节点
        while (cur != nullptr) {
            for (int i = 1; i <= k; i++) {  // 如果当前组不满k个节点，直接返回
                if (tail == nullptr) return dummyHead->next;
                tail = tail->next;
            }
            for (int i = 1; i < k; ++i) {  // 反转本次k个节点
                ListNode* post = cur->next;
                cur->next = post->next;
                post->next = pre->next;
                pre->next = post;
            }
            pre = cur;      
            cur = cur->next;   // 到下一组的首节点
        }
        return dummyHead->next;
    }
};