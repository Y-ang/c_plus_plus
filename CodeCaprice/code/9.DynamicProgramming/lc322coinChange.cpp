#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        // dp[j] 表示凑成j金额的最少硬币数
        vector<int> dp(amount + 1, INT_MAX);
        // 初始化
        dp[0] = 0;
        // dp[j]表示的是j金额而不是0-j金额所以要保证所计算的硬币数都是coins中存在的硬币
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (dp[j - coins[i]] == INT_MAX) continue;   // 不存在j-coins[i]这样的面额
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main(){
    vector<int> coins = {2};
    int amount = 3;
    Solution su;
    su.coinChange(coins, amount);

    return 0;
}