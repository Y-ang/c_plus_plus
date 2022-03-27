class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 存在删除第一个节点的情况，所以要创建一个虚拟节点指向头节点的前一个
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;
        while (fast != nullptr && n--) {
            fast = fast->next;
        }
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* tmp= slow->next;
        slow->next = slow->next->next;
        delete tmp;
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }

};