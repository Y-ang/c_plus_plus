#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node{
        int key;
        int val;
        Node* next;
        Node* pre;
        Node(int key_, int val_) : key(key_), val(val_), next(nullptr), pre(nullptr) {}
    };

    // 构造函数
    Solution(int capacity){
         // write code here
        this->capacity = capacity;
        front = new Node(-1, -1);
        end = new Node(-1, -1);
        front->next = end;
        end->pre = front;
    }

    void pop_front() {
        Node* deletedNode = front->next;
        hash.erase(deletedNode->key);               // 在hashtable中删除首元素的键值对
        deletedNode->next->pre = deletedNode->pre;  // 删除首元素
        front->next = deletedNode->next;
        delete deletedNode;
    }

    void push_end(Node* node) {
        node->pre = end->pre;    // 新插入节点的指向
        node->next = end;
        end->pre->next = node;   // 改变之前节点的指向
        end->pre = node;
    }

    void remove_node(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    
    int get(int key) {
         // write code here
        if (hash.count(key) == 0) return -1; // 没有该缓存
        Node* cur = hash[key];  // 否则，通过哈希表找到该节点
        remove_node(cur);       // 删除链表中的节点
        push_end(cur);          // 将节点移动到链表末尾
        return cur->val;
    }
    
    void set(int key, int value){
         // write code here
        Node* cur;
        if (hash.count(key) != 0) {     // 已经存在该缓存，修改缓存的值
            cur = hash[key];
            cur->val = value;
            remove_node(cur);          // 删除节点在链表中间的位置
        } else {
            if (hash.size() == capacity) {   // 如果缓存已满，删除头节点
                pop_front();
            }
            cur = new Node(key, value);  // 不存在该缓存，新建该缓存，并添加到hashtable中
            hash[key] = cur;
        }
        push_end(cur);
    }

private:
    int capacity;
    Node* front;
    Node* end;
    unordered_map<int, Node*> hash;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* solution = new Solution(capacity);
 * int output = solution->get(key);
 * solution->set(key,value);
 */