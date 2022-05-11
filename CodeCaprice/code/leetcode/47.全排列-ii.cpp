// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());   // 排序后去重
        vector<vector<int>> res;
        vector<int> path;
        vector<int> vis(nums.size(), 0);
        backtracking(path, vis, res, nums);
        return res;
    }
    void backtracking(vector<int>& path, vector<int>& vis, vector<vector<int>>& res, vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (vis[i] == 1 || (i > 0 && nums[i] == nums[i - 1] && vis[i - 1] == 0)) continue;   // 不是同一层，之前访问过； 或者，同一层是重复出现的元素
            vis[i] = 1;
            path.push_back(nums[i]);
            backtracking(path, vis, res, nums);
            path.pop_back();
            vis[i] = 0;
        }
    }
};
// @lc code=end

