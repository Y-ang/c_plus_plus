// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path; // 树的路径，保存每种组合
        backtracking(1, path, k, n, res);
        return res;
    }

    void backtracking(int startIndex, vector<int>& path, int k, int n, vector<vector<int>>& res) {
        if (path.size() == k || n < 0) {          // 树的深度 & 终止条件    剪枝：n < 0 则后序遍历无意义
            if (n == 0) res.push_back(path);  
            return;
        }
        for (int i = startIndex; i <= 9; ++i) {   // 树的宽度，每种路径上元素的取值
            path.push_back(i);
            backtracking(i + 1, path, k, n - i, res);
            path.pop_back();
        }
    }
};
// @lc code=end

