/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
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