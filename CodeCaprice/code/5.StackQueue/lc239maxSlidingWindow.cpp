#include<bits/stdc++.h>
using namespace std;

// class Solution {
// private:
//     class Myqueue {
//     public:
//         deque<int> q;
//         void pop(int x) {
//             if (!q.empty() && q.front() == x) {
//                 q.pop_front();
//             }
//         }
//         int front() {
//             return q.front();
//         }
//         void push(int x) {
//             while (!q.empty() && q.back() < x) {
//                 q.pop_back();
//             }
//             q.push_back(x);
//         }
//     };
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> res;
//         Myqueue myQue;
//         for (int i = 0; i < k; i++) {
//             myQue.push(nums[i]);
//         }
//         res.push_back(myQue.front());
//         for (int i = k; i < nums.size(); i++) {
//             myQue.pop(nums[i - k]);
//             myQue.push(nums[i]);
//             res.push_back(myQue.front());
//         }
//         return res;
//     }
// };



class Solution {
private:
    // 自定义队列
    class MyQue {
    public:
        deque<int> q;

        void push (int x) {  // 将滑动窗口最后一个元素push，若x大于队尾元素，将队尾元素弹出，保持单调增队列
            if (!q.empty() && x > q.back()) {
                q.pop_back();
            }
            q.push_back(x);
        }

        int front () {  // 队首元素是当前滑动窗口内的最大元素
            return q.front();
        }
        
        void pop (int x) {  // 如果当前元素等于队首元素，则将元素弹出，否则不做任何操作
            if (!q.empty() && x == q.front()) {
                q.pop_front();
            }
        }

        
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        MyQue que;
        // 将第一个滑动窗口内的全部元素入栈
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        // 保存第一个滑动窗口内的最大值
        res.push_back(que.front());
        // 滑动窗口不断后移, i记录的是滑动窗口内的最后一个元素
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]); // 弹出前一个滑动窗口的第一个元素
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
};


int main () {
    Solution su;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    su.maxSlidingWindow(nums, 3);
    return 0;    
}