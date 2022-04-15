class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4));
        dp[0][0] = -prices[0]; // 买入
        dp[0][1] = 0; // 保持卖出状态
        dp[0][2] = 0; // 今天卖出
        dp[0][3] = 0; // 冷静期
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][3]) - prices[i]); // 保持买入状态，或者昨天是保持卖出、冷静期 今天就能买入（昨天是卖出状态，今天就不能买入）
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]); // 保持卖出状态，或者昨天是冷静期
            dp[i][2] = dp[i - 1][0] + prices[i];        // 今天卖出
            dp[i][3] = dp[i - 1][2];                    // 昨天卖出今天就是冷静期
        }
        return max({dp[prices.size() - 1][1], dp[prices.size() - 1][2], dp[prices.size() - 1][3]});
    }
};