#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        // // 递归
        // if (n==1 || n == 0) return n;
        // return fib(n - 1) + fib(n - 2);

        // 两个状态
        if (n < 2) return n;
        int dp[2] = {0, 1};

        for (int i = 2; i <= n; i++) {
            int sum = dp[1] + dp[0];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

int main() {

    return 0;
}