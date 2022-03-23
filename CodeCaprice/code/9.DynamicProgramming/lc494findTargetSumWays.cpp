#include<bits/stdc++.h>
using namespace std;


// // 二叉递归法 O(2^n)
// class Solution {
// public:
//     int res = 0;
//     int findTargetSumWays(vector<int>& nums, int target) {
//         find(nums, 0, 0, target);
//         return res;
//     }
//     void find(vector<int>& nums, int index, int sum, int target) {
//         if (sum == target && index == nums.size()) {
//             res++;
//             return;
//         }
//         if (index >= nums.size()) return; //没有满足的
//         find(nums, index + 1, sum + nums[index], target);
//         find(nums, index + 1, sum - nums[index], target);
//     }
// };

// DP
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 求和
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        // -号元素个数之和   
        // pos - neg = target   pos + neg = sum   pos = (target+sum)/2  neg = (sum-target)/2
        // 这里neg和较小，所以取nums中元素，使其和为neg，计算取元素的组合数
        if (target > sum || (sum - target) % 2 != 0) return 0;
        int neg = (sum - target) /2;
        vector<int> dp(neg + 1, 0);  // dp[j] 元素和为j的表达式总数
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = neg; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[neg];

    }
};

int main() {
    vector<int> nums = {8, 5, 7, 6, 4};
    int target = 10;
    Solution su;
    su.findTargetSumWays(nums, target);
    return 0;
}