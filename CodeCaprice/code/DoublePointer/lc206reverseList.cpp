struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x, ListNode* p) : val(x), next(p) {}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pre = nullptr;   // 初始化为空节点，链表末尾指向空
        while (pHead != nullptr) {
            ListNode* post = pHead ->next;  // 保存后一个节点的位置
            pHead->next = pre;              // 改变指向
            pre = pHead;                    // pre指向当前
            pHead = post;                   // 当前指向后
        }
        return pre;
    }
};
