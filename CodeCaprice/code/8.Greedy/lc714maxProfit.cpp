#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit = 0;
        int preMin = INT_MAX;
        int preMax = 0;
        for (int i = 0; i < prices.size(); i++) {
            preMin = min(preMin, prices[i]); // 最小值
            if (prices[i] - preMin > fee) { // 当前值可以获利
                profit += prices[i] - preMin - fee;
                preMin = prices[i] - fee;  // 如果当前值不是最大值，防止下次多收取手续费；如果当前值是最大值，那么下次的最小值一定比preMin小
            }
        }
        return profit;
    }
};

int main() {
    vector<int> price = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    Solution su;
    su.maxProfit(price, fee);
    return 0;
}