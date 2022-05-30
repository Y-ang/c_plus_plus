// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
// 空间复杂度为O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 存在负值，会使前面的最大乘积变为最小乘积，所以要维护两个状态
        // dp[i]保存nums[i]为结尾的乘积的最大值
        int dpMax = nums[0];
        int dpMin = nums[0];
        int res = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int tmpMax = dpMax, tmpMin = dpMin;    // 需要一个临时变量保存前一个max和min
            dpMax = max({nums[i], nums[i] * tmpMax, nums[i] * tmpMin});
            dpMin = min({nums[i], nums[i] * tmpMax, nums[i] * tmpMin});
            if (dpMax > res) res = dpMax;
        }

        return res;
    }
};
// @lc code=end

// 空间复杂度为O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 存在负值，会使前面的最大乘积变为最小乘积，所以要维护两个状态
        // dp[i]保存nums[i]为结尾的乘积的最大值
        vector<int> dpMax(nums);
        vector<int> dpMin(nums);
        int res = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            dpMax[i] = max({nums[i], nums[i] * dpMax[i - 1], nums[i] * dpMin[i - 1]});
            dpMin[i] = min({nums[i], nums[i] * dpMax[i - 1], nums[i] * dpMin[i - 1]});
            if (dpMax[i] > res) res = dpMax[i];
        }

        return res;
    }
};