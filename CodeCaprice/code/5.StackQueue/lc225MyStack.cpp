#include<bits/stdc++.h>
using namespace std;

// class MyQueue {
// public:
//     MyQueue() {
//         sIn;
//         sOut;
//     }
    
//     void push(int x) {
//         sIn.push(x);
//     }
    
//     int pop() {
//         if (sOut.empty()) {
//             while (!sIn.empty()) {
//                 sOut.push(sIn.top());
//                 sIn.pop();
//             }
//         }
//         int res = sOut.top();
//         sOut.pop();
//         return res;
//     }
    
//     int peek() {
//         if (sOut.empty()) {
//             while (!sIn.empty()) {
//                 sOut.push(sIn.top());
//                 sIn.pop();
//             }
//         }
//         return sOut.top();
//     }
    
//     bool empty() {
//         return sIn.empty() && sOut.empty();
//     }
// private:
//     stack<int> sIn;
//     stack<int> sOut;    
// };

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

class MyStack {
private:
    queue<int> queIn;
    queue<int> queOut;
public:
    void push(int x) {
        queIn.push(x);
    }

    int top() {
        return queIn.back();  // queIn的最后一个元素
    }

    int pop() {
        int res = queIn.back();
        while (!queIn.empty()) {
           if (queIn.size() != 1) {
               queOut.push(queIn.front());
           }
           queIn.pop();
        }
        queIn = queOut;
        while (!queOut.empty()) queOut.pop();   // 清除queOut元素
        return res;
    }

    bool empty() {
        return queIn.empty();
    }

    MyStack() {
        queIn;
        queOut;
    }
};