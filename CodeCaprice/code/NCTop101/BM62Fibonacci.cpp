#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        // 递归
        // if (n < 3) return 1;
        // return Fibonacci(n - 1) + Fibonacci(n - 2);

        // 动规
        int dp[2] = {1, 1};
        for (int i = 3; i <= n; ++i) {
            int tmp = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return dp[1];
    }
};