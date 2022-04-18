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


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0) return head;
        // 因为是删除节点，所以要遍历到要删除节点的前一个节点;且存在删除第一个节点的情况，素以需要头节点
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        // 因为要定位到前一个节点，所以走k+1步
        for (int i = 0; i <= n; i++) {
            if (fast == nullptr) return nullptr;
            fast = fast->next;
        }
        // fast和slow一起走，直到fast为空节点
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        // 删除slow后面的节点
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        return dummyHead->next;
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