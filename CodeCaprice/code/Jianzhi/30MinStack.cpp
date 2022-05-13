#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if (valAndMin.empty()) {
            valAndMin.push({x, x});
        } else {
            if (x < valAndMin.top().second) valAndMin.push({x, x});
            else valAndMin.push({x, valAndMin.top().second});
        }
    }
    
    void pop() {
        valAndMin.pop();
    }
    
    int top() {
        if (valAndMin.empty()) return -1;
        return valAndMin.top().first;
    }
    
    int min() {
        if (valAndMin.empty()) return -1;
        return valAndMin.top().second;
    }
private:
    stack<pair<int, int>> valAndMin;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */