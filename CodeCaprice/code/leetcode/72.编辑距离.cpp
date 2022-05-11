// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j]   word1[0... i-1] 和 word2[0 ... j-1]之间的编辑距离
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1)); 
        // 其中一串为空时的编辑距离
        for (int i = 1; i <= word1.size(); ++i) dp[i][0] = i;
        for (int i = 1; i <= word2.size(); ++i) dp[0][i] = i;

        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];           // 相同：跳过，不操作
                } else {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;  // 不相同：删 增 改
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
// @lc code=end

