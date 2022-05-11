// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n + 1); // dp[j] 和为j的完全平方数的最小数量
        dp[0] = 0;
        for (int i = 1; i * i <= n; ++i) {  // 可用的完全平方数
            for (int j = i * i; j <= n; ++j) {  // 背包的重量
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end

