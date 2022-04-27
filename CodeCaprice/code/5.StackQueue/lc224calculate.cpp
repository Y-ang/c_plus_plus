#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<char> ops;
        stack<int> nums;
        
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == ' ') continue;
            else if (ch == '(') ops.push('(');
            else if (ch == ')') {  // 把左括号之间的运算计算完
                while (ops.top() != '(') {
                    calc(ops, nums);
                }
                ops.pop(); // 易错点 把左括号pop出来
            } else if (isdigit(ch)) {  // 数字
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i++] - '0');
                }
                i--;  // for循环中还有一个++，需要先减一个
                nums.push(num);
            } else {  // + - 没有优先级，谁先出现，先算谁
                if ((i == 0 || s[i - 1] == '(' ) && (s[i] == '+' || s[i] == '-')) { //将+和-表示一元运算符时进行加0的处理(-1 + 1)  -1 + 1
                    nums.push(0);
                }
                if (!ops.empty()) {
                    calc(ops, nums); // 先计算栈顶运算
                }
                ops.push(ch); // 入栈
            }
        }
        while (!ops.empty()) {
            calc(ops, nums);
        }
        return nums.top();
    }
    void calc(stack<char>& ops, stack<int>& nums) {
        if (ops.empty() || nums.size() < 2 || ops.top() == '(') return;  // 易错点 栈顶如果是左括号 不能进行计算
        int num1 = nums.top();
        nums.pop();
        int num2 = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        if (op == '+') nums.push(num2 + num1);
        else if (op == '-') nums.push(num2 - num1);
    }
};

int main() {
    // string str = "(1+(4+5+2)-3)+(6+8)";
    // string str = "-2 + 1";
    string str = "(-2 + 1)";
    Solution su;
    int res = su.calculate(str);
    cout << res;
    return 0;
}