#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x, ListNode* p) : val(x), next(p) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        // 快指针走两步，慢指针走一步，直到在环内相遇
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        // 如果没有环则退出
        if (fast == nullptr || fast->next == nullptr) return nullptr;
        slow = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }

};

int main() {
    ListNode* four = new ListNode(-4, nullptr);
    ListNode* three = new ListNode(0, four);
    ListNode* two = new ListNode(2, three);
    ListNode* one = new ListNode(3, two);
    four->next = two;
    Solution  su;
    su.detectCycle(one);

    return 0;
}