#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1; // 初始状态
        for (int i = 3; i <= n; i++) { // 找从3-n的每个数的最大分解乘积
            for (int j = 1; j < i - 1; j++) { // 第i个数的最大乘积 注意j的范围是[1, i - 2], 这样可以避免dp[1],dp[0]的出现
                dp[i] = max(dp[i], j * (i - j), j * dp[i - j]);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution su;
    su.integerBreak(1);
    return 0;
}