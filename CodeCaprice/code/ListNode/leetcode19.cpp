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
// 快慢指针法
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        while(fast->next != nullptr && n--){
            fast = fast->next;
        }
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};



// 通过逆转链表删除指定节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverseList(head);
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* cur = dummyHead;
        while(--n){
            cur = cur->next;
        }
        if(cur->next == nullptr){
            return nullptr;
        }
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        head = reverseList(dummyHead->next);
        return head;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* tmp;
        while(cur != nullptr){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};