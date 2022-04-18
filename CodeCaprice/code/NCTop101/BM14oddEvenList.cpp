#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next; // 偶数的第一个节点，最后一个奇节点指向它
        // 每次遍历奇偶节点，奇节点指向偶节点的下一个，更新奇节点；偶节点指向奇节点下一个，更新偶节点
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;  // 最后一个奇节点指向第一个偶节点
        return head;
    }
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return head;
        ListNode* preOdd = head; // 前一个even节点
        ListNode* odd = head->next->next; // 奇数
        ListNode* pre = head->next; // 当前even的前一个节点
        // 每次交换将当前odd交换到前一个odd后面的位置
        while (odd != nullptr) {
            pre->next = odd->next;
            odd->next = preOdd->next;
            preOdd->next = odd;
            preOdd = odd; // 前一个even的位置
            odd = pre; // 第一个偶数的位置
            // 到下一个odd的位置
            if (odd != nullptr && odd->next != nullptr) {
                odd = odd->next->next;
                pre = pre->next;
            } else {
                break;
            }
        }

        return head;
    }
};