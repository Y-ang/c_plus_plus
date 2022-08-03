// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
// 方法一：前缀和 空间复杂度为0
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int preSum = 0;
        int total = 0;
        for (auto& n : nums) total += n;
        for (int i = 0; i < nums.size(); ++i) {
            if (2 * preSum + nums[i] == total) return i;
            preSum += nums[i];
        }
        return -1;
    }
};
// @lc code=end

