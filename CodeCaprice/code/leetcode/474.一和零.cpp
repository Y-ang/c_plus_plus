// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 二维背包
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));   // dp[i][j]装满 i个0 j个1 最大子集的长度
        for (int k = 0; k < strs.size(); ++k) {
            int len_0 = count(strs[k].begin(), strs[k].end(), '0');
            int len_1 = count(strs[k].begin(), strs[k].end(), '1');
            for (int i = m; i >= len_0; --i) {
                for (int j = n; j >= len_1; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - len_0][j - len_1] + 1);  // 不取当前，取当前
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

