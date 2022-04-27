#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */
    int solve(string s) {
        stack<char> ops;
        stack<int> nums;
        unordered_map<char, int> priority = {
            {'*', 2},
            {'+', 1},
            {'-', 1}
        };
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == ' ') continue;
            if (ch == '(') ops.push('(');
            else if (ch == ')') {
                while (ops.top() != '(') {
                    calc(ops, nums);
                }
                ops.pop(); // 将“(”pop
            } else if (isdigit(ch)) {  // 数字
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i++] - '0');
                }
                i--;
                nums.push(num);
            } else {
                if ((i == 0 || s[i - 1] == '(') && (s[i] == '+' || s[i] == '-')) { // + - 的单目运算符情况
                    nums.push(0);
                }
                if (!ops.empty() && priority[ch] <= priority[ops.top()]) {  // 易错点，如果和栈顶的优先级相同，需要先算栈顶的
                    calc(ops, nums);
                } 
                ops.push(ch);
            }
        }
        while (!ops.empty()) {
            calc(ops, nums);
        }
        return nums.top();
    }
    void calc(stack<char>& ops, stack<int>& nums) {
        if (ops.empty() || nums.size() <= 1 || ops.top() == '(') return;   // 易错点 左括号不
        int num1 = nums.top();
        nums.pop();
        int num2 = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        if (op == '+') nums.push(num1 + num2);
        else if (op == '-') nums.push(num2 - num1);
        else if (op == '*') nums.push(num1 * num2);
        else if (op == '/') nums.push(num2 / num1);
    }
};

int main() {
    string str = "3+2*3*4-1";
    Solution su;
    su.solve(str);
    return 0;
}