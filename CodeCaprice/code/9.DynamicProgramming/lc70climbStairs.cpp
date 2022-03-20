class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        int dp[2] = {1, 2};
        for (int i = 3; i <= n; i++) {
            int sum = dp[1] + dp[0];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};