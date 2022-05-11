// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        backtracking(0, path, target, candidates, res);
        return res;
    }

    void backtracking(int startIndex, vector<int>& path, int target, vector<int>& candidates, vector<vector<int>>& res) {
        if (target <= 0) {    // 终止条件和剪枝  
            if (target == 0) res.push_back(path); // 满足条件的path
            return;
        }

        for (int i = startIndex; i < candidates.size(); ++i) {    
            path.push_back(candidates[i]);
            backtracking(i, path, target - candidates[i], candidates, res); // 当前元素可以取多次，所以下一次遍历从当前元素开始
            path.pop_back();
        }
    }
};
// @lc code=end

