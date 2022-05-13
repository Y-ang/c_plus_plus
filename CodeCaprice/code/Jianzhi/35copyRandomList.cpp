#include <bits/stdc++.h>
using namespace std;



// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// 方法二：复制节点插入到原节点的后面，复制节点的random就是原节点的下一个节点
// 时间复杂度O(n)  空间复杂度O(1)
class Solution {
public:
    unordered_map<Node*, Node*> cachedNode;
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        Node* cur = head;
        // insert the new nodes
        while (cur != nullptr) {
            Node* newNode = new Node(cur->val);  
            newNode->next = cur->next;
            cur->next = newNode;
            cur = newNode->next;
        }
        // 修改新节点的random指针的指向
        cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->random == nullptr) cur->next->random = nullptr;
            else cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        // 拆分新节点
        Node* newHead = head->next;
        cur = head->next;
        while (head != nullptr && cur != nullptr) {
            head->next = cur->next;
            head = head->next;
            cur->next = head == nullptr ? nullptr : head->next;   // 拷贝节点的下一个节点为空，head和newhead的链尾都指向空
            cur = cur->next; 
        }
        return newHead;
    }
};

// 方法一： 哈希表 + 回溯 时间复杂度O(n) 空间复杂度O(n)
/* 
    哈希表：记录该节点的拷贝节点是被创建过，如果创建过，就直接返回该节点；否则就新建节点进行深拷贝
    回溯：有next指针和random指针，这两个指针在后面可能没有被关键过；所以要回溯地进行拷贝
 */
class Solution {
public:
    unordered_map<Node*, Node*> cachedNode;
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        if (cachedNode.find(head) == cachedNode.end()) {
            Node* newNode = new Node(head->val);
            cachedNode[head] = newNode;  // 要先把节点加入哈希表中，再进行递归创建next random
            newNode->next = copyRandomList(head->next);
            newNode->random = copyRandomList(head->random);
        }
        return cachedNode[head];
    }
};

