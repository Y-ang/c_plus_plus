#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param n int整型 
     * @return string字符串vector
     */
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recursion("", 0, 0, n, res);
        return res;
    }   
    void recursion(string str, int left, int right, int n, vector<string>& res) {
        if (left == n && right == n) {
            res.push_back(str);
            return;
        }
        if (left < n) recursion(str + '(', left + 1, right, n, res);
        // 只需保证）数量小于（数量
        if (right < n && right < left) recursion(str + ')', left, right + 1, n, res);
    }
};



class Solution {
public:
    /**
     * 
     * @param n int整型 
     * @return string字符串vector
     */
    vector<string> generateParenthesis(int n) {
        // write code here
        vector<string> res;
        backtracking("", 2 * n, res);
        return res;
    }
    void backtracking(string str, int n, vector<string>& res) {
        if (str.size() == n) {
            if (isValid(str)) res.push_back(str);
            return;
        } else if (str.size() >= n) {
            return;
        }
        backtracking(str + '(', n, res);
        backtracking(str + ')', n, res);
    }
    bool isValid (string str) {
        stack<char> st;
        for (auto& ch : str) {
            if (ch == '(') st.push(')');
            else if (st.empty() || st.top() != ')') return false;
            else st.pop();
        }
        return st.empty();
    }
};