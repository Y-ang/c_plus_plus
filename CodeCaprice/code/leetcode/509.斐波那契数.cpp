// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
// 动态规划 递推 压缩状态转移表
class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        int dp_0 = 0, dp_1 = 1;
        for (int i = 2; i <= n; ++i) {
            int tmp = dp_0 + dp_1;
            dp_0 = dp_1;
            dp_1 = tmp;
        }
        return dp_1;
    }
};
// @lc code=end


// 记忆搜索 + 递归
class Solution {
public:
    int fib(int n) {
        vector<int> memo(n + 1, 0);
        return helper(n, memo);
    }

    int helper(int n, vector<int>& memo) {
        if (n == 0 || n == 1) return n;
        if (memo[n] != 0) return memo[n];
        memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
        return memo[n];
    }
};


// 动态规划 递推 将记忆搜索转化为一张DP表，空间复杂度O(n)
class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};