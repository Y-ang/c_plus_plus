#include<bits/stdc++.h>
using namespace std;



struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        if (head1 == nullptr) return head2;
        if (head2 == nullptr) return head1;
        head1 = reverseList(head1);
        head2 = reverseList(head2);
        ListNode* post = nullptr;
        int sum = 0;
        int carry = 0;
        while (head1 != nullptr || head2 != nullptr || carry != 0) {
            int val1 = head1 == nullptr ? 0 : head1->val;
            int val2 = head2 == nullptr ? 0 : head2->val;
            sum = val1 + val2 + carry;
            
            carry = sum / 10;
            sum = sum % 10;
            
            ListNode* cur = new ListNode(sum);
            cur->next = post;  // 指向后面一个节点
            post = cur;

            if (head1 != nullptr) head1 = head1->next;
            if (head2 != nullptr) head2 = head2->next;
        }
        return post;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        while (head) {
            ListNode* post = head->next;
            head->next = pre;
            pre = head;
            head = post;
        }
        return pre;
    }
};