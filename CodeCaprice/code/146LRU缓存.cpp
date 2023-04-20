#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int value;
    Node* pre;
    Node* next;
    Node() : key(-1), value(-1), pre(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        front = new Node();
        end = new Node();
        front->next = end;
        end->pre = front;
    }
    
    // 从链表中删除节点
    Node* removeNode (Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        return node;
    }

    // 向链表末尾添加节点
    void insertNode(Node* node) {
        node->next = end;
        node->pre = end->pre;
        end->pre->next = node;
        end->pre = node;
    }

    int get(int key) {
        if (!hash_table.count(key)) {
            return -1;
        }
        Node* node = hash_table[key];
        node = removeNode(node);
        insertNode(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (hash_table.count(key)) {     // 如果链表中已有该键，则更新对应的值，并讲该节点放到链表末尾
            Node* node = hash_table[key];
            node->value = value;
            node = removeNode(node);
            insertNode(node);
            hash_table[key] = node;
        } else {
            if (hash_table.size() == cap) {   // 如果链表的长度达到上限，删除队头缓存（节点和哈希表都要删除）
                int key = front->next->key;
                hash_table.erase(key);
                Node* node = removeNode(front->next);
                delete node;
            }
            Node* node = new Node();  // 添加新页面
            node->value = value;
            node->key = key;
            insertNode(node);
            hash_table[key] = node;
        }
    }
private:
    Node* front;  // 链表的开始为最久未被使用
    Node* end;    // 链表的末尾为最近被使用的
    unordered_map<int, Node*> hash_table;  // 键和节点的映射，
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache* cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    cache->get(1);       // 返回  1
    cache->put(3, 3);    // 该操作会使得密钥 2 作废
    cache->get(2);       // 返回 -1 (未找到)
    cache->put(4, 4);    // 该操作会使得密钥 1 作废
    cache->get(1);       // 返回 -1 (未找到)
    cache->get(3);       // 返回  3
    cache->get(4);       // 返回  4
    return 0;
}