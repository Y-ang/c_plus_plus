/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if (pHead == nullptr) return pHead;
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        // 如有环，找到相遇节点；若无环，跳出循环
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        // 没有环
        if (fast == nullptr || fast->next == nullptr) return nullptr;
        // 有环，从相遇结点出发，与从头节点出发的节点相遇就是换入口节点
        slow = pHead;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};