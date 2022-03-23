#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void completeBackpack(vector<int> weight, vector<int> value, int bagweight) {
        vector<int> dp(bagweight + 1, 0);
        for (int i = 0; i < weight.size(); i++) {
            for (int j = weight[i]; j <= bagweight; j++) {   // 每个物品会被拿多次，所以从前向后遍历
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        cout << dp[bagweight];
    }
};



int main() {
    vector<int> weight = {1, 2, 3};
    vector<int> value = {15, 20, 30};
    Solution su;
    su.completeBackpack(weight, value, 4);
    return 0;
}