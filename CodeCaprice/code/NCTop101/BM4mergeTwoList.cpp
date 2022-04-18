/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr) return pHead2;
        if (pHead2 == nullptr) return pHead1;
        ListNode* dummyHead = new ListNode(INT_MIN);  // 加表头
        ListNode* cur = dummyHead;
        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {  // 指向值较小的节点
                cur->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;    // 移动到下一个节点
        }
        if (pHead1) {  // 保存剩下的节点
            cur->next = pHead1;
        } else {
            cur->next = pHead2;
        }
        return dummyHead->next;
    }
};