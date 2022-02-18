class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(): val(0), next(NULL) {}
        ListNode(int x): val(x), next(NULL) {}
        ListNode(int x, ListNode* node): val(x), next(node) {}
    };
    MyLinkedList() {
        _dummyHead = new ListNode(0);
        _size = 0;
    }
    
    int get(int index) {
        if(index >= _size || index < 0){
            return -1;
        }
        ListNode* cur = _dummyHead->next;
        while(index-- && cur != NULL){
            cur = cur -> next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* tmp = new ListNode(val, _dummyHead->next);
        _dummyHead->next = tmp;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode* cur = _dummyHead;
        while(cur->next != NULL){
            cur = cur->next;
        }
        ListNode* tmp = new ListNode(val, NULL);
        cur->next = tmp;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > _size){
            return;
        }
        ListNode* cur = _dummyHead;
        while(index--){
            cur = cur->next;
        }
        ListNode* tmp = new ListNode(val, cur->next);
        cur->next = tmp;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= _size || index < 0){
            return;
        }
        ListNode* cur = _dummyHead;
        while(index--){
            cur = cur->next;
        }
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }
private:
    ListNode* _dummyHead;
    int _size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */