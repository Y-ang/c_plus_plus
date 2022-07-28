class LRUCache {

public:
    struct Node{
        int key;
        int val;
        Node* left;
        Node* right;
        Node(int key_, int val_) : key(key_), val(val_), left(nullptr), right(nullptr) {}
    };

    LRUCache(int capacity) {
        this->capacity = capacity;
        front = new Node(-1, -1);
        end = new Node(-1, -1);
        front->right = end;
        end->left = front;
    }
    
    /*
        get和put涉及到三个操作：pop_front, push_end, remove_node
        get: remove_node, push_end
        put: pop_front remove_node push_end
    */
    void pop_front() {
        Node* cur = front->right;
        front->right = cur->right;
        cur->right->left = front;
        hashTable.erase(cur->key);  // 删除哈希表中的关键字和节点
        delete cur;                 // 删除该节点
    }

    void remove_node(Node* node) { // 不删除该节点，只是断开当前节点在链表中的位置
        node->left->right = node->right;
        node->right->left = node->left;
    }

    void push_end(Node* node) {
        node->left = end->left;   // 插入当前节点
        node->right = end;
        node->left->right = node; // 改变之前节点的指向
        end->left = node;
    }

    int get(int key) {
        if (hashTable.count(key) == 0) return -1;
        Node* node = hashTable[key];
        remove_node(node);
        push_end(node);
        return node->val;
    }
    
    void put(int key, int value) {
        // 关键字已存在
        if (hashTable.count(key)) {
            Node* node = hashTable[key];
            node->val = value;
            remove_node(node);
            push_end(node);
        } else {
            if (hashTable.size() == capacity) {
                pop_front();
            }
            Node* node = new Node(key, value);
            push_end(node);
            hashTable[key] = node; 
        }
    }

private:
    unordered_map<int, Node*> hashTable; // 关键字和节点之间的映射
    int capacity;  // 缓存中节点最大的数量
    Node* front;   // 记录开始位置和结束位置，便于删除和插入节点 
    Node* end;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */