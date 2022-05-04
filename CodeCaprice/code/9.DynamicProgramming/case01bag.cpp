#include<bits/stdc++.h>
using namespace std;

// 二维数组
class Solution {
public:
    void bag(vector<int>& weight, vector<int>& value, int bagweight) {
        // 动规数组
        vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0)); // 每行表示每个物品，每列表示背包的重量，dp[i][j] = 从0-i的物品里任意取，背包在重量j时的最大价值
        // 初始化，第一列背包没有重量不能放任何物品 全部赋值为0，第一行背包的重量根据第一个物品的重量和价值确定
        for (int i = weight[0]; i <= bagweight; i++) dp[0][i] = value[0];
        // 遍历数组
        for (int i = 1; i < weight.size(); i++) { // 遍历每个物品
            for (int j = 0; j <= bagweight; j++) {
                if (j < weight[i]) dp[i][j] = dp[i - 1][j];  // 书包当年重量放不下i物品
                else dp[i][j] = max(dp[i -1][j], dp[i - 1][j - weight[i]] + value[i]); // 取或不取i的最大价值
            }
        }
        cout << dp[weight.size() - 1][bagweight];
    }
};


// 一维数组
class Solution {
public:
    void bag(vector<int>& weight, vector<int>& value, int bagweight) {
        // 动规数组
        vector<int> dp(bagweight + 1, 0); // dp[j]表示，表示背包在i重量时装有物品的最大价值
        // 初始化，第一个元素永远为0，因为背包没有重量时不会装任何物品，也就没有任何价值，根据第一个物品初始化
        for (int i = weight[0]; i <= bagweight; i++) dp[i] = value[0];
        // 滚动遍历一维数组
        for (int i = 1; i < weight.size(); i++) { // 遍历每个物品
            for (int j = bagweight; j <= weight[i]; j--) { // 反向从大到小遍历，防止物品被重复多次拿入
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]); // 取或不取i的最大价值
            }
        }
        cout << dp[bagweight];
    }
};

class Solution {
public:
    void bag(vector<int>& weight, vector<int>& value, int bagweight) {
        vector<int> dp(bagweight + 1, 0);
        for (int i = 0; i < weight.size(); ++i) {  // 遍历物品
            for (int j = bagweight; j >= weight[i]; --j) { // 对每个物品，从后向前遍历背包重量，保存能装下的最大价值（从后向前防止物品被重复拿）
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        cout << dp[bagweight] << endl;
    }
};


int main() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;
    Solution su;
    su.bag(weight, value, bagweight);

    return 0;
}