// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem70.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
// 完全背包 + 排列 解法
// 每次爬台阶有[1，2]两种走法，每种走法可以重复选（完全背包），走法前后顺序不同为不同的走法（排列）。一共要爬到第n个楼梯（背包的大小）
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {      // 背包的大小 -- 最终要爬到n台阶
            for (int j = 1; j < 3; ++j) {   // 每次爬的台阶数
                if (j <= i) dp[i] += dp[i - j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

// 斐波那契解法
class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        int dp_1 = 1;
        int dp_2 = 2;
        for (int i = 3; i <= n; ++i) {
            int tmp = dp_2 + dp_1;  // 在前一个台阶上爬1，在前两个台阶上爬2
            dp_1 = dp_2;
            dp_2 = tmp;
        }
        return dp_2;
    }
};
