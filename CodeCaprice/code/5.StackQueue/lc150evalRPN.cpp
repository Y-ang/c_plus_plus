#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> res;
        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int val1 = res.top();
                res.pop();
                int val2 = res.top();
                res.pop();
                if (token == "+") res.push(val1 + val2);
                else if (token == "-") res.push(val2 - val1);
                else if (token == "/") res.push(val2 / val1);
                else if (token == "*") res.push(val2 * val1);
            } else {
                res.push(stoi(token));
            }     
        }
        return res.top();  // 返回栈顶计算完的元素
    }
};

int main() {
    Solution su;
    vector<string> s = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int res = su.evalRPN(s) ;
    return 0;
}