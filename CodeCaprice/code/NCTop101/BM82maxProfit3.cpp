class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 两次交易所能获得的最大收益
     * @param prices int整型vector 股票每一天的价格
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4));
        dp[0][0] = -prices[0]; // 一次买入
        dp[0][2] = -prices[0]; // 两次买入
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]); // 一次买入
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]); // 一次卖出
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]); // 第二次买入
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
        }
        return dp[prices.size() - 1][3];
    }
};