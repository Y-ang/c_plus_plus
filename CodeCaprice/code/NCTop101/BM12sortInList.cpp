#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
};

class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        // 自顶向下 时间O(nlogn) 空间logn
        return mergeSort(head, nullptr);  // 左闭右开空间
    }
    ListNode* mergeSort(ListNode* head, ListNode* tail) {
        // 链表中只有一个或两个节点，直接返回
        if (head == nullptr || head->next == nullptr) return head;
        // 需要给next节点置为nullptr，以表示链表的结束；也不会影响到以tail开始的链表
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        // fast走一步，slow走两步，直到终点; 找出中间节点
        while (fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
       
        ListNode* pHead1 = mergeSort(head, slow); // 左闭右开区间
        ListNode* pHead2 = mergeSort(slow, tail);
        return merge(pHead1, pHead2);
    }
    ListNode* merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr) return pHead2;
        if (pHead2 == nullptr) return pHead1;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* cur = dummyNode;
        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }
        if (pHead1) {
            cur->next = pHead1;
        } else {
            cur->next = pHead2;
        }
        return dummyNode->next;
    }

};

// 自底向上 迭代法
class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        // 自底向上 时间O(nlogn) 空间O(1)
        int len = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            len++;
            cur = cur->next;
        }
        ListNode* dummyHead = new ListNode(INT_MIN);
        dummyHead->next = head;
        for (int subLen = 1; subLen < len; subLen <<= 1) { // 合并区间块的大小
            ListNode* pre = dummyHead; // 指向未排序的链表
            ListNode* cur = dummyHead->next; // 从头开始分治
            // subLen长度的两区间的分治
            while (cur) {
                ListNode* head1 = cur;  // 第一个待排序的链表
                for (int i = 1; i < subLen && cur != nullptr && cur->next != nullptr; i++) {
                    cur = cur->next;
                }
                ListNode* head2 = cur->next;
                cur->next = nullptr; // 断开head1
                cur = head2; // 开始拼第二个带排序的链表
                for (int i = 1; i < subLen && cur != nullptr && cur->next != nullptr; i++) {
                    cur = cur->next;
                }
                
                ListNode* tmp = nullptr;
                if (cur != nullptr) {  // cur有可能为空，即head2有可能为空
                    tmp = cur->next;     // 保存下一次排序的开始节点
                    cur->next = nullptr; // 断开head2
                }
                    
                pre->next = merge(head1, head2); // pre指向开头
                while (pre->next != nullptr) {   // pre指向没有排序的链表的开头
                    pre = pre->next;
                }
                cur = tmp;   // 开始subLen长度的下一个两区间的归并排序
            }
        }
        return dummyHead->next;
    }

    ListNode* merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr) return pHead2;
        if (pHead2 == nullptr) return pHead1;
        ListNode* dummyNode = new ListNode(INT_MIN);
        ListNode* cur = dummyNode;
        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }
        if (pHead1) {
            cur->next = pHead1;
        } else {
            cur->next = pHead2;
        }
        return dummyNode->next;
    }

};