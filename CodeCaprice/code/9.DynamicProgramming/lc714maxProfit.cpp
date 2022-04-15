class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // 动规
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return dp[prices.size() - 1][1];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // 贪心
        int profit = 0;
        int preMin = INT_MAX;
        int preMax = 0;
        for (int i = 0; i < prices.size(); i++) {
            preMin = min(preMin, prices[i]); // 最小值
            if (prices[i] - preMin > fee) { // 当前值可以获利
                profit += prices[i] - preMin - fee;
                preMin = prices[i] - fee;  // 如果当前值不是最大值，防止下次多收取手续费；如果当前值是最大值，那么下次的最小值一定比preMin小
            }
        }
        return profit;
    }
};