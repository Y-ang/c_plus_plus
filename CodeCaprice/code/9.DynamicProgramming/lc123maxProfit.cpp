#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0][0] = 0; // 没有操作
        dp[0][1] = -prices[0]; // 第一次持有的最大利润
        dp[0][2] = 0; // 第一次卖出的最大利润；
        dp[0][3] = -prices[0]; // 第二次持有的最大例如
        dp[0][4] = 0; // 第二次卖出的利润
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);  // 持有之前的 && 买入当前的
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return dp[prices.size() - 1][4];
    }
};

int main() {

    return 0;
}