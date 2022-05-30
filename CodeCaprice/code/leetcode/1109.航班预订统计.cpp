#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
// 差分数组的思想
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n, 0);    // 保存前后两航班座位的差值
        // 计算座位变动
        for (auto& booking : bookings) {
            diff[booking[0] - 1] += booking[2];
            if (booking[1] < n) diff[booking[1]] -= booking[2];
        }
        // 从座位变动计算航班座位总数
        for (int i = 1; i < n; ++i) {
            diff[i] += diff[i - 1];
        }
        return diff;   
    }
};
// @lc code=end

