#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double res = 0;
        int rest = income;
        for (int i = 0; i < brackets.size(); ++i) {
            if (rest <= 0) break;
            int cur = 0;
            if (i > 0) cur = rest >= brackets[i][0] - brackets[i - 1][0] ? brackets[i][0] - brackets[i - 1][0] : rest;
            else cur = rest >= brackets[i][0] ? brackets[i][0] : rest;
            rest = income - brackets[i][0];
            res += cur * brackets[i][1] * 0.01;
        }
        return res;
    }
};

int main() {
    Solution su;
    vector<vector<int>> vec = {{3,50}, {7,10}, {12,25}};
    int income = 10;
    su.calculateTax(vec, income);
    return 0;
}