// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
// 空间复杂度为O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp保存nums[i]为结尾的最大子数组的和
        int dp = nums[0];
        int res = dp;   // 初始值为第一个元素

        for (int i = 1; i < nums.size(); ++i) {
            dp = max(nums[i], dp + nums[i]);
            res = max(res, dp);
        }
        return res;
    }
};
// @lc code=end

// 空间复杂度为O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());  // dp[i] 到nums[i]，子数组的最大和
        dp[0] = nums[0];
        int res = dp[0];   // 初始值为第一个元素

        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};