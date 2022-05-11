// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
            if (vis[i] == 1) continue;
            vis[i] = 1;
            path.push_back(nums[i]);
            backtracking(path, vis, res, nums);
            path.pop_back();
            vis[i] = 0;
        }
    }
};
// @lc code=end

