class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 空间复杂度为O(n)
        vector<int> dp(cost.size(), 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];   // 从第i个台阶向上爬需要支付的最小费用
        }
        return min(dp[dp.size() - 1], dp[dp.size() - 2]);   // 楼顶可以由倒数第一个、倒数第二个台阶向上爬

        // 空间复杂度为O(1)
        int dp_0 = cost[0];
        int dp_1 = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            int dp = min(dp_1, dp_0) + cost[i];
            dp_0 = dp_1;
            dp_1 = dp;
        }
        return min(dp_0, dp_1);
    }
};