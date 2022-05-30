// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
// 差分数组，只要最后表示车上人数的数组中出现大于capacity的情况就返回false
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0); // 车站i事，车上的人数与i-1站车上的人数的差值
        for (auto& trip : trips) {
            int numPsng = trip[0]; // 在该车站上车的人数
            int fromi = trip[1]; // 从出发站上车的人数
            int toi = trip[2]; // 在trip[2]下车，则乘客在车上的时间在trip[1]--trip[2] - 1站范围内
            diff[fromi] += numPsng;
            if (toi < 1001) diff[toi] -= numPsng;
        }
        // 根据diff数组，计算每站车上的人数
        for (int i = 0; i < 1001; ++i) {
            if (i > 0) diff[i] += diff[i - 1];
            if (diff[i] > capacity) return false;
        }
        return true;
    }
};
// @lc code=end

