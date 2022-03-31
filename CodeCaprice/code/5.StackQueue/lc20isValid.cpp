#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st;
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '(') st.push(')');
//             else if (s[i] == '{') st.push('}');
//             else if (s[i] == '[') st.push(']');
//             else if (st.empty() || st.top() != s[i]) return false;
//             else st.pop();
//         }
        
//         return st.empty();
//     }
// };

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        stack<char> st;
        for (char ch : s) {
            if (ch == '(') st.push(')');
            else if (ch == '{') st.push('}');
            else if (ch == '[') st.push(']');
            else if (st.empty() || st.top() != ch) return false; // 当前char是右括号的情况
            else st.pop();   // 当前char是右括号，且匹配成功
        }
        return st.empty();   // 如果栈中不为空则是false
    }
};


int main() {
    Solution su;
    su.isValid("())");
    return 0;
}