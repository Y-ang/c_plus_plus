class MyQueue {
public:
    MyQueue() {
        sIn;
        sOut;
    }
    
    void push(int x) {
        sIn.push(x);
    }
    
    int pop() {
        if (sOut.empty()) {
            while (!sIn.empty()) {
                sOut.push(sIn.top());
                sIn.pop();
            }
        }
        int res = sOut.top();
        sOut.pop();
        return res;
    }
    
    int peek() {
        if (sOut.empty()) {
            while (!sIn.empty()) {
                sOut.push(sIn.top());
                sIn.pop();
            }
        }
        return sOut.top();
    }
    
    bool empty() {
        return sIn.empty() && sOut.empty();
    }
private:
    stack<int> sIn;
    stack<int> sOut;    
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */