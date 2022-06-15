/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        /*
            存在三种情况：
                1. 插入的值在最大值和最小值之间，找到cur->val <= insertVal <= cur->next->val的位置
                2. 插入的值大于最大值，找到最大值和最小值的位置，在最大值之后插入
                3. 插入的值小于最小值，找到最大值和最小值的位置，在最小值之前插入
        */
        if (head == nullptr) {   // 循环链表为空
            head = new Node(insertVal);
            head->next = head;
            return head;
        }

        Node* cur = head;
        while (cur->next != head) {
            // 情况一
            if (cur->val <= insertVal && cur->next->val >= insertVal) break;
            if (cur->val > cur->next->val) {
                // 情况二 插入元素大于最大值
                if (cur->val <= insertVal) break;
                // 情况三 插入元素小于最小值
                if (cur->next->val >= insertVal) break;
            }
            cur = cur->next;
        }
        Node* node = new Node(insertVal, cur->next);
        cur->next = node;
        return head;
    }
};