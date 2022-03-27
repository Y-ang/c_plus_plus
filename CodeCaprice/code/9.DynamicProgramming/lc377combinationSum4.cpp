#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //dp[j] 总和为j的元素排列数
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        // 排列数 外层为背包 内层为物品
        for (int i = 0; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] <= i && dp[i] < INT_MAX - dp[i - nums[j]]) {
                    dp[i] += dp[i - nums[j]];
                    // cout << i << ' ' << dp[i] << endl;
                }
            }
        }
        return dp[target];
    }
};


// // 回溯会超时
// class Solution {
// public:
//     int res = 0;
//     int combinationSum4(vector<int>& nums, int target) {
//         // 回溯
//         backtracking(0, nums, target);
//         return res;
//     }
//     void backtracking(int sum, vector<int> nums, int target) {
//         if (sum == target) {
//             res++;
//             return;
//         }
//         if (sum > target) return;
//         for (int i = 0; i < nums.size(); i++) {
//             backtracking(sum + nums[i], nums, target);
//         }
//     }
// };


int main () {
    Solution su;
    vector<int> nums = {1, 2, 3};
    int target = 4;
    su.combinationSum4(nums, target);
    return 0;
}