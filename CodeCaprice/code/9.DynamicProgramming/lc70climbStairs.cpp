#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        int dp[2] = {1, 2};
        for (int i = 3; i <= n; i++) {
            int sum = dp[1] + dp[0];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};


class Solution {
public:
    int climbStairs(int n) {
        // 动规 dp[j] 爬到第j个楼梯的方法
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 0; i <= n; i++) {
            if (i - 1 >= 0) dp[i] += dp[i - 1];
            if (i - 2 >= 0) dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};