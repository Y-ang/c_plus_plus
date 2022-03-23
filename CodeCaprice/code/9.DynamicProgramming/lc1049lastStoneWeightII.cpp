#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 让重量接近的两个部分石头相撞，得到最小的重量
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }
        // 构建一个最大容量为sum/2的书包，看最多能装多重的石头
        int weight = sum / 2;
        vector<int> dp(weight + 1, 0);
        for (int i = 0; i < stones.size(); i++) { // 遍历每个物品
            for (int j = weight; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[weight] - dp[weight];
    }
};

int main() {
    vector<int> nums = {2,7,4,1,8,1};
    Solution su;
    su.lastStoneWeightII(nums);
    return 0;
}