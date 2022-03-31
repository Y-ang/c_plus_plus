#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char ch : s) {
            if (st.empty() || st.top() != ch) {
                st.push(ch);
            } else {
                st.pop();
            } 
        }
        string res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;
        for (char ch : s) {
            if (st.empty() || ch != st.top()) {   // 栈为空或栈顶元素与当前元素不相同，当前元素入栈
                st.push(ch);
            } else {
                st.pop();  // 当前元素与栈顶元素相同，栈顶元素被弹出
            }
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};