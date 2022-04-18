/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        // fast走k步，如果在k步之前遇到了空节点，说明链表长度没有k，返回空
        for (int i = 0; i < k; i++) {
            if (fast == nullptr) return nullptr;
            fast = fast->next;
        }
        // 直到fast为空
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};