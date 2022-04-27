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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        while (cur1 != cur2) {
            cur1 = cur1 == nullptr ? pHead2 : cur1->next;
            cur2 = cur2 == nullptr ? pHead1 : cur2->next;
        }
        return cur1;
    }
};