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

// 定义一个新的链表res保存反转的链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* res = new ListNode(0);
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* cur = dummyHead;
        while(cur->next != nullptr){
            addAtHead(cur->next->val, res);
            cur = cur->next;
        }
        ListNode* tmp = res;
        res = res->next;
        delete tmp;
        return res;

    }
    void addAtHead(int val, ListNode* res){
        ListNode* tmp = new ListNode(val, res->next);
        res->next = tmp;
        return;
    }
};


// 双指针法反转链表方向
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
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