#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) return false;
        // dp[j] 表示背包j容量装下的最大子集和（这是价值、重量都是该集合子集的值）
        int weight = sum / 2;
        vector<int> dp(weight + 1, 0);
        // for (int i = nums[0]; i <= weight; i++) dp[i] = nums[0];
        for (int i = 1; i < nums.size(); i++) { // 可选物品
            for (int j = weight; j >= nums[i]; j--) { // 可选物品的重量, 反向遍历，防止物品重复拿入
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);  // 不选当前值，选当前值
            }
        }
        return dp[weight] == weight;
    }
};

int main() {
    vector<int> nums = {1, 2, 5};
    Solution su;
    su.canPartition(nums);
    return 0;
}