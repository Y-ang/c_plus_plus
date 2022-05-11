// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
// 用unordered_set去重
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtracking(0, path, res, nums);
        return res;
    }
    void backtracking(int startIndex, vector<int>& path, vector<vector<int>>& res, vector<int>& nums) {
        if (path.size() > 1) res.push_back(path);
        // 记录本层访问过的节点，重复的后面出现的节点不访问
        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); ++i) {
            if ((path.empty() || path.back() <= nums[i]) && uset.find(nums[i]) == uset.end()) {       // 只访问本层没有出现过的节点，并且该元素大于等于path最后一个元素或path为空，才能进入下次backtrack
                uset.insert(nums[i]);
                path.push_back(nums[i]);
                backtracking(i + 1, path, res, nums);
                path.pop_back();
            }
        }
    }
};
// @lc code=end

