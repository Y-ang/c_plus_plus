// @before-stub-for-debug-begin
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, map<string, int>> tics;  // 起点和（终点，票数）的映射
        for (auto& t :tickets) {
            tics[t[0]][t[1]]++;
        }
        vector<string> res;
        res.push_back("JFK");
        backtracking(tickets.size(), tics, res);
        return res;
    }

    bool backtracking(int ticNum, unordered_map<string, map<string, int>>& tics, vector<string>& res) {
        if (ticNum == 0) {   // 遍历第一遍找到结果，就是字典序最小的情况；及时返回
            return true;
        }
        for (auto& endAp : tics[res.back()]) {   // res的back元素是该次飞机的起飞点
            if (endAp.second == 0) continue;
            endAp.second--;   // 票数减一
            res.push_back(endAp.first);
            if (backtracking(ticNum - 1, tics, res)) return true;
            res.pop_back();
            endAp.second++;   // 票数加一
        }
        return false;
    }
};
// @lc code=end

