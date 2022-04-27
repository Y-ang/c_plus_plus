class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        stack<char> st;
        for (auto& ch : s) {
            if (ch == '(') st.push(')');
            else if (ch == '[') st.push(']');
            else if (ch == '{') st.push('}');
            else if (st.empty() || st.top() != ch) return false; // 栈为空，或栈顶元素与ch不匹配
            else st.pop();
        }
        return st.empty(); // 如果栈中还有元素，则无效
    }
};