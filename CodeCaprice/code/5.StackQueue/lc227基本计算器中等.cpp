#include<bits/stdc++.h>
using namespace std;


/*
遍历字符串 ss，并用变量 preSign 记录每个数字之前的运算符，对于第一个数字，其之前的运算符视为加号。每次遍历到数字末尾时，根据 preSign 来决定计算方式：

加号：将数字压入栈；
减号：将数字的相反数压入栈；
乘除号：计算数字与栈顶元素，并将栈顶元素替换为计算结果。
代码实现中，若读到一个运算符，或者遍历到字符串末尾，即认为是遍历到了数字末尾。处理完该数字后，更新 preSign 为当前遍历的字符。


*/


class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        char preSign = '+';
        int num = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + int(s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
                switch (preSign) {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    default:
                        stk.back() /= num;
                }
                preSign = s[i];
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};



class Solution {
public:
    int calculate(string s) {
        stack<char> ops;
        stack<int> nums;
        unordered_map<char, int> priority = {   // 运算优先级
            {'*', 2},  
            {'/', 2},
            {'+', 1},
            {'-', 1}
        };
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;
            if (s[i] == '(') ops.push('(');
            else if (s[i] == ')') {   // 将左括号前的运算符计算完
                while (ops.top() != '(') {
                    calc(ops, nums);
                }
                ops.pop();    // 将左括号pop出来
            } else if (isdigit(s[i])) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i++] - '0');
                }
                i--;   // for循环中还有一个自加
                nums.push(num);
            } else {
                if ((i == 0 || s[i - 1] == '(') && (s[i] == '+' || s[i] == '-')) {   // + - 做一元运算符
                    nums.push(0);
                } 
                while (!ops.empty() && priority[s[i]] <= priority[ops.top()]) {   //易错  需要把当前运算符之前优先级大于等于它的先算掉
                    calc(ops, nums);                                              // 错误样例 "1*2-3/4+5*6-7*8+9/10"
                }
                ops.push(s[i]);
            }
        }
        while (!ops.empty()) {
            calc(ops, nums);
        }
        return nums.top();
    }

    void calc(stack<char>& ops, stack<int>& nums) {
        if (ops.empty() || nums.size() < 2 || ops.top() == '(') return;   // 无法做计算
        int num1 = nums.top();
        nums.pop();
        int num2 = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        if (op == '+') nums.push(num2 + num1);
        else if (op == '-') nums.push(num2 - num1);
        else if (op == '*') nums.push(num2 * num1);
        else if (op == '/') nums.push(num2 / num1);
    }
};


int main() {
    string str = "1*2-3/4+5*6-7*8+9/10";
    Solution su;
    su.calculate(str);
    return 0;
}