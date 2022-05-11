// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        backtracking(0, path, res, nums);
        return res;
    }

    void backtracking(int startIndex, vector<int>& path, vector<vector<int>>& res, vector<int>& nums) {
        res.push_back(path);
        for (int i = startIndex; i < nums.size(); ++i) {
            if (i > startIndex && nums[i] == nums[i - 1]) continue;  // 同一层上的重复数字
            path.push_back(nums[i]);
            backtracking(i + 1, path, res, nums);
            path.pop_back();
        }
    }
};
// @lc code=end

