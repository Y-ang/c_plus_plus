#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return int整型
     */
    int longestValidParentheses(string s) {
        // 动态规划
        int maxLen = 0;
        vector<int> dp(s.size() + 1);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')' && s[i - 1] == '(') {
                dp[i] = i > 1 ? dp[i - 2] + 2 : 2;   // 当前右括号能和前一个左括号匹配
            } else if (s[i] == ')' && s[i - dp[i - 1] - 1] == '(') {  // 前一个位置是右括号，且上一个匹配好的括号的前一个是左括号
                dp[i] = dp[i - 1] + (i - dp[i - 1] > 1 ? dp[i - dp[i - 1] - 2] + 2 : 2);  // 和i - dp[i-1] - 1位置上的括号匹配
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;

        // // 栈
        // // 栈底元素：第一个没有被匹配到的右括号的下标；栈顶元素：有效的括号内，所有被匹配过的括号的前一个下标
        // stack<int> st;
        // int ans = 0;
        // st.push(-1); // 压入-1
        // for (int i = 0; i < s.size(); i++) {
        //     if (s[i] == '(') st.push(i);
        //     else {
        //         st.pop();
        //         if (st.empty()) {
        //             st.push(i); // 第一个没有被匹配的右括号的下标
        //         } else {
        //             ans = max(ans, i - st.top());
        //         }
        //     }
        // }
        // return ans;

    }
};

int main() {
    string str = "())";
    Solution su;
    int res = su.longestValidParentheses(str);
    cout << res;
    return 0;
}