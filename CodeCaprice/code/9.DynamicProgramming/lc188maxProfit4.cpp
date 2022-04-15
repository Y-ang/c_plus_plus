class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0 || prices.empty()) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k));
        for (int i = 0; i < 2 * k; i += 2) {
            dp[0][i] = -prices[0];  // 初始状态，每次买入都为负值
        }
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            // 买入卖出剩下次数
            for (int j = 2; j < 2*k; j += 2) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]); // 买入
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]); // 卖出
            }
        }
        return dp[prices.size() - 1][2*k - 1];
    }
};