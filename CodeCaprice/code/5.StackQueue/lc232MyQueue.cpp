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


class MyQueue {
private:
    stack<int> sIn;
    stack<int> sOut;
public:
    MyQueue() {
        sIn;
        sOut;
    };

    void push(int x) {
        sIn.push(x);
    }

    int peek() {   // 如果sout为空，则将sin中所有元素pop出来push到sout中
        if (sOut.empty()) {
            while (!sIn.empty()) {
                sOut.push(sIn.top());
                sIn.pop();
            }
        }
       return sOut.top(); 
    }

    int pop() {
        int res = this->peek();  // 复用peek的代码
        sOut.pop();
        return res;
    }

    bool empty() {
        return sIn.empty() && sOut.empty();
    }
};


int main() {
    MyQueue que;
    que.push(1);
    que.pop();
    bool res = que.empty();
    return 0;
}