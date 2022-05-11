// @before-stub-for-debug-begin
#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;  // 回溯路径上的组合
        backtracking(1, path, k, n, res);
        return res;
    }

    void backtracking(int startIndex, vector<int>& path, int k, int n, vector<vector<int>>& res) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; ++i) {  // 剪枝 还需要k-path.size()个元素，所以集合最多只能从n - (k - path.size()) + 1 开始
            path.push_back(i);
            backtracking(i + 1, path, k, n, res);
            path.pop_back();
        }
    }
};
// @lc code=end

