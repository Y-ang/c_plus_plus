// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
// 回溯
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));
        // dp[i][j] 是由 dp[i - 1][j] 和 dp[i][j - 1] 推出来的
        return dfs(grid.size() - 1, grid[0].size() - 1, memo, grid);
    }

    int dfs(int x, int y, vector<vector<int>>& memo, vector<vector<int>>& grid) {
        if (x < 0 || y < 0) return INT_MAX;
        if (x == 0 && y == 0) return grid[0][0];
        if (memo[x][y] != -1) return memo[x][y];
        memo[x][y] = min(dfs(x - 1, y, memo, grid), dfs(x, y - 1, memo, grid)) + grid[x][y];
        return memo[x][y];
    }
};
// @lc code=end

// // 动态规划
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> dp(n, vector<int>(m));
//         dp[0][0] = grid[0][0];
//         for (int i = 1; i < n; ++i) dp[i][0] = dp[i - 1][0] + grid[i][0];
//         for (int i = 1; i < m; ++i) dp[0][i] = dp[0][i - 1] + grid[0][i];
//         for (int i = 1; i < n; ++i) {
//             for (int j = 1; j < m; ++j) {
//                 dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
//             }
//         }
//         return dp[n - 1][m - 1];
//     }
// };

// int main() {
//     vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
//     Solution su;
//     su.minPathSum(grid);
//     return 0;
// }