// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //单调栈 栈中保存的是数组下标的索引  
        // 加入的元素如果大于栈顶元素，则计算栈顶元素的在i天后升温的结果；否则将加入的元素入栈
        stack<int> st;
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {   // 加入元素大于栈顶元素
                res[st.top()] = i - st.top();
                st.pop();
            } 
            st.push(i);     // 加入元素小于等于栈顶元素，则可以直接入栈
        }

        return res;
    }
};
// @lc code=end

