// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 初始时，设所有硬币都不可取
        vector<int> dp(amount + 1, amount + 1); // dp[j] 可以凑成金额j的最少硬币数
        dp[0] = 0;
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);   // 排除不能凑成j - coins[i]的情况
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
// @lc code=end


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 初始时，设所有硬币都不可取
        vector<int> dp(amount + 1, INT_MAX); // dp[j] 可以凑成金额j的最少硬币数
        dp[0] = 0;
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                if (dp[j - coins[i]] != INT_MAX) dp[j] = min(dp[j], dp[j - coins[i]] + 1);   // 排除不能凑成j - coins[i]的情况
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
