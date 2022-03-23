#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // 用动规计算组合数
        vector<int> dp(amount + 1, 0);   // dp[j] 总额数为j时的组合数
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};

int main() {
    Solution su;
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    su.change(amount, coins);


    return 0;
}