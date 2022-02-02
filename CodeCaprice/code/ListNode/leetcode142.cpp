/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    142. 环形链表 II
    给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
*/
// 哈希表
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* cur = head;
        set<ListNode*> post;
        while(cur != nullptr && post.count(cur) == 0){
            post.insert(cur);
            cur = cur->next;
        }
        return cur;
    }
};