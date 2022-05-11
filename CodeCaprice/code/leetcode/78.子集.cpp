// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtracking(0, path, res, nums);
        return res;
    }
    void backtracking(int startIndex, vector<int>& path, vector<vector<int>>& res, vector<int>& nums) {
        res.push_back(path);  // 每一个路径都计算进去
        for (int i = startIndex; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            backtracking(i + 1, path, res, nums);
            path.pop_back();
        }
    }
};
// @lc code=end

