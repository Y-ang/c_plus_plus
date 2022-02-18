#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
    链表相交
    给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
*/

// 方法一：两个链表的开始cur节点对齐后开始对比，开始cur指向长度较小的链表的开始位置。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        while(curA != nullptr){
            lenA++;
            curA = curA -> next;
        }
        while(curB != nullptr){
            lenB++;
            curB = curB -> next;
        }
        curA = headA;
        curB = headB;
        if(lenB > lenA){
            swap(lenA, lenB);
            swap(curA, curB);
        }
        int gap = lenA - lenB;
        while(gap--){
            curA = curA -> next;
        }
        while(curA != curB){
            curA = curA -> next;
            curB = curB -> next;
        }
        return curA;
    }
};

//方法二：双指针
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA, *curB = headB;
        while(curA != curB){
            curA = curA == nullptr ? headB : curA->next;
            curB = curB == nullptr ? headA : curB->next;
        }
        return curA;
    }
};

int main(){
    Solution su;
    ListNode* lista = new ListNode(0);
    ListNode* listb = new ListNode(0);
    ListNode* cur1 = new ListNode(1);
    ListNode* cur2 = new ListNode(2);

    lista->next = cur2;
    listb->next = cur1;
    listb->next->next = cur2;
    
    ListNode* intersec = su.getIntersectionNode(lista, listb);
    return 0;
}