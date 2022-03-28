#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); // 这里买入可以是很多次，
        }
        return dp[prices.size() - 1][0];
    }
};

// 优化
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[2][2] = {{0, -prices[0]}, {}};
        for (int i = 1; i < prices.size(); i++) {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] + prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] - prices[i]);
        }
        return dp[(prices.size() - 1) % 2][0];
    }
};