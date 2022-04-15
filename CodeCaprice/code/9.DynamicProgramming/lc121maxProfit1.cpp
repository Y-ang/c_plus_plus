#include<bits/stdc++.h>
using namespace std;


// 贪心
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minValue = prices[0];
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res = max(res, prices[i] - minValue);
            if (prices[i] < minValue){
                minValue = prices[i];
            }
        }
        return res;
    }
};


// 动规
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 动规
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));   // 持有或不持有今天股票的最大收益
        dp[0][0] = 0;// 不持有
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);   // 前面就没有持有 && 前面的持有，现在卖掉
            dp[i][1] = max(dp[i - 1][1], -prices[i]);             // 前面的持有     && 现在买入
        }
        return dp[prices.size() - 1][0];
    }
};

// 优化版动规 状态压缩
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 动规
        int dp[2][2] = {{0, -prices[0]}, {0, 0}};
        for (int i = 1; i < prices.size(); i++) {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] + prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], -prices[i]);
        }
        return dp[(prices.size() - 1) % 2][0];
    }
};

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    Solution su;
    su.maxProfit(prices);
    return 0;
}