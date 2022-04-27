class Solution {
public:
    void push(int value) {
        if (st.empty()) {
            st.push({value, value});
        } else {
            int minVal = value < st.top().second ? value : st.top().second;
            st.push({value, minVal});
        }
    }
    void pop() {
        st.pop();
    }
    int top() {
        return st.top().first;  // 返回栈顶节点值
    }
    int min() {
        return st.top().second;  // 返回最小值
    }
private:
    stack<pair<int, int>> st;  // 同时保存节点值和当前最小值
};