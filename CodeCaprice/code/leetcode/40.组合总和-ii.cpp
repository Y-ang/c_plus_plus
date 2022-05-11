// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
// 使用startIndex去重
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 数组中有重复的数字，且数组中的每个元素只能用一次，所以需要去重 
        // 如：[2, 2, 2, 2, 1]  target = 3 如果不去重会出线多个[2, 2, 1]的现象
        sort(candidates.begin(), candidates.end());   // 排序后，数组中元素才能比较是否和前一个元素重复
        vector<vector<int>> res;   
        vector<int> path;
        backtracking(0, path, target, res, candidates);
        return res;
    }
    void backtracking(int startIndex, vector<int>& path, int target, vector<vector<int>>& res, vector<int>& candidates) {
        if (target <= 0) {
            if (target == 0) res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size(); ++i) {
            if (i > startIndex && candidates[i] == candidates[i - 1]) continue;  // 同一层上出现重复元素
            path.push_back(candidates[i]);
            backtracking(i + 1, path, target - candidates[i], res, candidates);
            path.pop_back();
        }
    }
};
// @lc code=end


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 数组中有重复的数字，且数组中的每个元素只能用一次，所以需要去重 
        // 如：[2, 2, 2, 2, 1]  target = 3 如果不去重会出线多个[2, 2, 1]的现象
        sort(candidates.begin(), candidates.end());   // 排序后，数组中元素才能比较是否和前一个元素重复
        vector<int> vis(candidates.size(), 0); // 记录当前路径下被使用过的元素下标
        vector<vector<int>> res;   
        vector<int> path;
        backtracking(0, path, target, vis, res, candidates);
        return res;
    }
    void backtracking(int startIndex, vector<int>& path, int target, 
                        vector<int>& vis, vector<vector<int>>& res, vector<int>& candidates) {
        if (target <= 0) {
            if (target == 0) res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size(); ++i) {
            if (i != 0 && candidates[i] == candidates[i - 1] && vis[i - 1] == 0) continue;  // 出现重复元素，且前一个重复元素没有在当前组合中被使用
            vis[i] = 1;
            path.push_back(candidates[i]);
            backtracking(i + 1, path, target - candidates[i], vis, res, candidates);
            path.pop_back();
            vis[i] = 0;
        }
    }
};
