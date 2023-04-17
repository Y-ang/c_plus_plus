#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() == 0 ) return num2;
        if (num2.size() == 0) return num1;
        int sum = 0;
        int carry = 0;
        string res;
        // num1 = reverse(num1.begin(), num1.end());
        // num2 = reverse(num2.begin(), num2.end());
        while (!num1.empty() || !num2.empty() || carry) {
            int val1 = num1.empty() ? 0 : num1.back() - '0';
            int val2 = num2.empty() ? 0 : num2.back() - '0';
            sum = val1 + val2 + carry;
            carry = sum / 10;
            res.push_back(sum % 10 + '0');
            if (!num1.empty()) num1.pop_back();
            if (!num2.empty()) num2.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;

    }
};

int main() {
    string str1 = "11";
    string str2 = "123";
    Solution su;
    su.addStrings(str1, str2);

    return 0;
}